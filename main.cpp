#include <iostream>
#include <portaudio.h>
// #include <pa_linux_pulseaudio.h>
#include "Init.hpp"
#include "Device.hpp"
#include "Stream.hpp"

int main(void) {
  Init::initPrismaStream();
  static Device::DeviceInfo CURRENT_DEVICE = Device::getCurrentDeviceInfo();
  std::cout << "Using Device " << Device::getCurrentDeviceIdx() << " - " << CURRENT_DEVICE.name << std::endl;

  Stream::playTestTone(Device::getCurrentDeviceIdx());

  int input;
  std::cin >> input;
  
  Init::killPrismaStream();
  return 0;
}