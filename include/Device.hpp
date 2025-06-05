#pragma once

#include <iostream>
#include <portaudio.h>
#include "Init.hpp"

namespace Device {

  struct DeviceInfo {
    std::string name;
    int maxOutputChannels;
    int maxInputChannels;
    double defaultSampleRate;
    double defaultLowOutputLatency;
    double defaultHighOutputLatency;
    double defaultLowInputLatency;
    double defaultHighInputLatency;
  };

  int getDeviceCount();
  void printAllDevicesInfo(int numDevices);
  PaDeviceIndex getDefaultIndex();
  void printDeviceInfo(struct DeviceInfo);
  DeviceInfo getCurrentDeviceInfo();
  void setDevice(PaDeviceIndex idx);
  PaDeviceIndex getSelectedDevice();

}