#include <iostream>
#include <portaudio.h>
#include "Init.hpp"
#include "Device.hpp"
#include "Metadata.hpp"



namespace Init {
  auto DEFAULT_DEVICE = DeviceInit::getDefaultIndex()
  void initPrismaStream() {
    std::cout << "Staring PrismaStream version: " << *version << std::endl;
    PaError err = Pa_Initialize();
    if (err != paNoError) {
      std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
      return paNoDevice;
    } else {
      std::cout << "===INITIALIZING PORTAUDIO API===" << std::endl;
      std::cout << "PortAudio version: " << Pa_GetVersion() << std::endl;
      std::cout << "Version Info: " << Pa_GetVersionInfo() << std::endl << "" << std::endl;
    }
    DeviceInit::printAllDevicesInfo(DeviceInit::getDeviceCount());
    
  };





  void killPrismaStream() {
    Pa_Terminate();
  };
}
