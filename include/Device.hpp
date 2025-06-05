#pragma once

#include <iostream>
#include <portaudio.h>
#include "Init.hpp"

namespace Device {

  int getDeviceCount();
  
  void printAllDevicesInfo(int numDevices);
  
  PaDeviceIndex getDefaultIndex();

  void printDeviceInfo(const PaDeviceInfo* deviceInfo);
  
  void setDevice(PaDeviceIndex idx);
  
  PaDeviceIndex getSelectedDevice();

}