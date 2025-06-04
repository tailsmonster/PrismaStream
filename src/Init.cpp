#include <iostream>
#include <portaudio.h>
#include "Init.hpp"
#include "Metadata.hpp"

namespace App::Init {
  void initPortAudio() {
    std::cout << "Staring PrismaStream version: " << *version << std::endl;
    PaError err = Pa_Initialize();
    if (err != paNoError) {
      std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
      return paNoDevice;
    } else {
      std::cout << "===INITIALIZING PORTAUDIO API===" << std::endl;
      std::cout << "PortAudio version: " << Pa_GetVersion() << std::endl;
      std::cout << "Version Info: " << Pa_GetVersionInfo() << std::endl;
    }
  };

  int getDeviceCount() {
    int numDevices = Pa_GetDeviceCount();
    if (numDevices < 0) {
      std::cerr << "No audio devices found!" << std::endl;
      std::cerr << "Pa_GetDeviceCount returned" << numDevices << std::endl;
      Pa_Terminate();
      return paNoDevice;
    }
    return numDevices;
  };
  
  void printAllDevicesInfo(int numDevices) {
    std::cout << "Number of devices: " << numDevices << std::endl;
    for (int i = 0; i < numDevices; i++) {
      const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(i);
      if (deviceInfo) {
        std::cout << i << ": " << deviceInfo->name 
        << " | Max Output Channels: " << deviceInfo->maxOutputChannels << std::endl;
      }
      else {
        std::cerr << "Failed to get info for device " << i << std::endl;
      }
    }
  };
  
  PaDeviceIndex getDefaultIndex() {
    PaDeviceIndex defaultIdx = Pa_GetDefaultOutputDevice();
    if (defaultIdx == paNoDevice) {
      std::cerr << "No default audio output device found!" << std::endl;
      Pa_Terminate();
      return paNoDevice;
    }
    return defaultIdx;
  };
  
  const PaDeviceInfo* printDeviceInfo(PaDeviceIndex idx) {
    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(idx);
    if (!deviceInfo) {
      std::cerr << "Error: Unable to retrieve device info!" << std::endl;
      Pa_Terminate();
      return nullptr;
    }
  
    if (idx == getDefaultIndex()) {
      std::cout << "Using DEFAULT output device: " << idx << " - " << deviceInfo->name << std::endl;
    } else {
      std::cout << "Using output device: " << idx << " - " << deviceInfo->name << std::endl;
    }
  
    std::cout << " | Max Output Channels: " << deviceInfo->maxOutputChannels << std::endl;
    std::cout << "PortAudio is initialized!" << std::endl;
  
    return deviceInfo;
  }
}
