#pragma once

#include <iostream>
#include <portaudio.h>
#include "Device.hpp"


namespace Stream {

  void playTestTone(PaDeviceIndex deviceIdx);

  bool openStream(const Device::DeviceInfo& deviceInfo);

  void closeStream();

}