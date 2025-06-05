#include <iostream>
#include <portaudio.h>
#include "Device.hpp"
#include "Init.hpp"

namespace Device {
  static PaDeviceIndex selectedDeviceIdx = paNoDevice;

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
      printDeviceInfo(deviceInfo, i);
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

  void printDeviceInfo(const PaDeviceInfo* deviceInfo, PaDeviceIndex idx = -1) {
    if (idx>0 ) {
      std::cout << idx <<") ";
    }
    if (deviceInfo) { 
      std::cout << deviceInfo->name << ": "   << std::endl
      << " | Max Output Channels: " << deviceInfo->maxOutputChannels  << std::endl
      << " | Max Input Channels: " << deviceInfo->maxInputChannels  << std::endl
      << " | Default Low Output Latency: " << deviceInfo->defaultLowOutputLatency  << std::endl
      << " | Default High Output Latency: " << deviceInfo->defaultHighOutputLatency  << std::endl
      << " | Default Low Input Latency: " << deviceInfo->defaultLowOInputLatency  << std::endl
      << " | Default High Input Latency: " << deviceInfo->defaultLowInputLatency  << std::endl
      << "" << std::endl;
    } else {
      std::cerr << "Failed to retrieve device info" << std::endl;
    }
  }

  DeviceInfo getCurrentDeviceInfo() {
    DeviceInfo device;
    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(selectedDeviceIdx);

    device.name = deviceInfo->name;
    device.maxOutputChannels = deviceInfo->maxOutputChannels;
    device.maxInputChannels = deviceInfo->maxInputChannels;
    device.defaultSampleRate = deviceInfo->defaultSampleRate;
    device.defaultLowOutputLatency = deviceInfo->defaultLowOutputLatency;
    device.defaultHighOutputLatency = deviceInfo->defaultHighOutputLatency;
    device.defaultLowInputLatency = deviceInfo->defaultLowInputLatency;
    device.defaultHighInputLatency = deviceInfo->defaultHighInputLatency;
    return device;
  }
  
  void setDevice(PaDeviceIndex idx) {
    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(idx);
    if (!deviceInfo) {
      std::cerr << "Error: Unable to retrieve device info!" << std::endl;
      Pa_Terminate();
      return;
    }
    selectedDeviceIdx = idx;
    if (idx == getDefaultIndex()) {
      std::cout << "Using DEFAULT output device: " << idx << " - " << deviceInfo->name << std::endl;
    } else {
      std::cout << "Using output device: " << idx << " - " << deviceInfo->name << std::endl;
    }
    printDeviceInfo(deviceInfo);
  }
  
  PaDeviceIndex getSelectedDeviceIdx() {
    return selectedDeviceIdx;
  }

}