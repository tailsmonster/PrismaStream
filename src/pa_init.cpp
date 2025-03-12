#include "../include/pa_init.hpp"

PaDeviceIndex initAudio() {
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    return paNoDevice;
  }

  int numDevices = Pa_GetDeviceCount();
  if (numDevices < 1) {
    std::cerr << "No audio devices found!" << std::endl;
    Pa_Terminate();
    return paNoDevice;
  }

  std::cout << "Number of devices: " << numDevices << std::endl;

  for (int i = 0; i < numDevices; i++) {
    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(i);
    if (deviceInfo) 
      std::cout << i << ": " << deviceInfo->name << " | Max Output Channels: " << deviceInfo->maxOutputChannels << std::endl;
    else 
      std::cerr << "Failed to get info for device " << i << std::endl;
  }

  PaDeviceIndex deviceIndex = Pa_GetDefaultOutputDevice();
  if (deviceIndex == paNoDevice) {
    std::cerr << "No default audio output device found!" << std::endl;
    Pa_Terminate();
    return paNoDevice;
  }

  const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(deviceIndex);
  if (!deviceInfo) {
    std::cerr << "Error: Unable to retrieve device info!" << std::endl;
    Pa_Terminate();
    return paNoDevice;
  }

  std::cout << "Using default output device: " << deviceIndex << " - " << deviceInfo->name << std::endl;
  std::cout << "PortAudio is working!" << std::endl;
  return deviceIndex;
}
