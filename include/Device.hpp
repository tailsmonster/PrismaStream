#pragma once

#include <iostream>
#include <portaudio.h>
#include "Init.hpp"

namespace App::Device {
  void initPortAudio();

  int getDeviceCount();
  
  void printAllDevicesInfo(int numDevices);
  
  PaDeviceIndex getDefaultIndex();
  
  const PaDeviceInfo* printDeviceInfo(PaDeviceIndex idx);

}