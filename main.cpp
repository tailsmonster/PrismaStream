#include <iostream>
#include <portaudio.h>
// #include <pa_linux_pulseaudio.h>
#include "Core/Init.hpp"
#include "Core/Device.hpp"
#include "Core/Stream.hpp"

int main(void) {
  Init::initPrismaStream();
  static Device::DeviceInfo CURRENT_DEVICE = Device::getCurrentDeviceInfo();
  static int CURRENT_DEV_IDX = Device::getCurrentDeviceIdx();
  std::cout << "Using Device " << CURRENT_DEV_IDX << " - " << CURRENT_DEVICE.name << std::endl;

  Stream::playTestTone(CURRENT_DEV_IDX);
  int input;
  std::cin >> input;
  
  Init::killPrismaStream();
  return 0;
}