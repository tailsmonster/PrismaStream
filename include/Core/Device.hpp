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
 
  PaDeviceIndex getDefaultIndex(); // gets the index for the default device
  int getDeviceCount(); // Returns Number of all Devices 
  PaDeviceIndex getCurrentDeviceIdx(); //gets the device currently in use's index
  DeviceInfo getCurrentDeviceInfo(); // returns a struct with all the information of the current device in use. 
  void printAllDevicesInfo(int numDevices); // Prints Info for all devices
  void printDeviceInfo(PaDeviceIndex idx, bool isLisingAll = false); // prints the info from a specific device.
  void setDevice(PaDeviceIndex idx); // sets currently used device to device index

}