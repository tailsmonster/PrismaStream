#include <iostream>
#include <portaudio.h>
#include "Init.hpp"
#include "Metadata.hpp"
#include "Device.hpp"
#include "Stream.hpp"


namespace Init {
  void initPrismaStream() {
    std::cout << "Starting PrismaStream version: " << version << std::endl;
    PaError err = Pa_Initialize();
    if (err != paNoError) {
      std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
      killPrismaStream();  
    } else {
      std::cout << "===INITIALIZING PORTAUDIO API===" << std::endl;
      std::cout << "PortAudio version: " << Pa_GetVersion() << std::endl;
      std::cout << "Version Info: " << (Pa_GetVersionInfo()) << std::endl << "" << std::endl;
    }
    Device::printAllDevicesInfo(Device::getDeviceCount());
    Device::setDevice(Device::getDefaultIndex());
    std::cout << "PortAudio is initialized!" << std::endl;
    Stream::openStream(Device::getCurrentDeviceInfo());
  };

  void killPrismaStream() {
    Stream::closeStream();
    Pa_Terminate();
  };
}
