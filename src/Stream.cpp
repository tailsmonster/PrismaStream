#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <cmath>
#include <portaudio.h>
#include "Device.hpp"
/*
  So chat,,,, what are we doing?
  Now that we have an audio sink to use, it's time to actually open a sink and play some music. 
*/

namespace Stream {
  static PaStream* stream = nullptr;

  constexpr double SAMPLE_RATE = 44100.0;
  constexpr double FREQUENCY = 440.0; // A4 note
  constexpr double AMPLITUDE = 0.2;
  static double phase = 0.0;

  static int testToneCallback(
    const void* input, void* output,
    unsigned long frameCount,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData
  ) {
    float* out = static_cast<float*>(output);
    (void)input; // unused
    for (unsigned long i = 0; i < frameCount; ++i) {
      out[i] = static_cast<float>(AMPLITUDE * sin(phase));
      phase += 2.0 * M_PI * FREQUENCY / SAMPLE_RATE;
      if (phase >= 2.0 * M_PI)
        phase -= 2.0 * M_PI;
    }
    return paContinue;
  }

  void playTestTone(PaDeviceIndex deviceIdx) {
    stream = nullptr;
    PaStreamParameters outputParams;

    const PaDeviceInfo* info = Pa_GetDeviceInfo(deviceIdx);

    outputParams.device = deviceIdx;
    outputParams.channelCount = 1;
    outputParams.sampleFormat = paFloat32;
    outputParams.suggestedLatency = info->defaultLowOutputLatency;
    outputParams.hostApiSpecificStreamInfo = nullptr;

    PaError err = Pa_OpenStream(
      &stream,
      nullptr,               // no input
      &outputParams,         // output only
      SAMPLE_RATE,
      paFramesPerBufferUnspecified,
      paClipOff,
      testToneCallback,
      nullptr
    );

    if (err != paNoError) {
      std::cerr << "Failed to open stream: " << Pa_GetErrorText(err) << std::endl;
      return;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
      std::cerr << "Failed to start stream: " << Pa_GetErrorText(err) << std::endl;
      return;
    }

    std::cout << "Playing test tone on " << info->name << "..." << std::endl;
    Pa_Sleep(2000); // play for 2 seconds

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
  }


  bool openStream(const Device::DeviceInfo& deviceInfo) {
    PaStreamParameters outputParams;
    outputParams.device = Device::getCurrentDeviceIdx();
    outputParams.channelCount = deviceInfo.maxOutputChannels;
    outputParams.sampleFormat = paFloat32;  // 32-bit floating point
    outputParams.suggestedLatency = deviceInfo.defaultLowOutputLatency;
    outputParams.hostApiSpecificStreamInfo = nullptr;

    PaError err = Pa_OpenStream(
      &stream,
      nullptr,  // no input
      &outputParams,
      deviceInfo.defaultSampleRate,
      paFramesPerBufferUnspecified,  // let PortAudio decide
      paClipOff,
      nullptr,  // no callback
      nullptr   // no user data
    );

    if (err != paNoError) {
      std::cerr << "Failed to open stream: " << Pa_GetErrorText(err) << std::endl;
      return false;
    }

    std::cout << "Stream opened successfully." << std::endl;
    return true;
  }

  void closeStream() {
    if (stream) {
      Pa_CloseStream(stream);
      stream = nullptr;
      std::cout << "Stream closed." << std::endl;
    }
  }

}