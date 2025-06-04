#pragma once

#include <iostream>
#include <portaudio.h>
#include "Metadata.h"

// init PortAudio and get the default output device

namespace App::Init {
  void initPortAudio();

  int getDeviceCount();
  
  void printAllDevicesInfo(int numDevices);
  
  PaDeviceIndex getDefaultIndex();
  
  const PaDeviceInfo* printDeviceInfo(PaDeviceIndex idx);
}