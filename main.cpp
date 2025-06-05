#include <iostream>
#include <portaudio.h>
// #include <pa_linux_pulseaudio.h>
#include "Init.hpp"
#include "Device.hpp"

int main(void) {
  Init::initPrismaStream();
  std::cout << "Using Device " << Device::getSelectedDevice() << " - " << Pa_GetDeviceInfo(Device::getSelectedDevice())->name << std::endl;

  int input;
  std::cin >> input;
  
  Init::killPrismaStream();
  return 0;
}