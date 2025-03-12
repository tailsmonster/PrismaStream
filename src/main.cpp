#include <iostream>
#include <portaudio.h>

int main() {
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    return 1;
  }

  int numDevices = Pa_GetDeviceCount();
  if (numDevices < 1) {
    std::cerr << "No audio devices found!" << std::endl;
    Pa_Terminate();
    return 1;
  }

  std::cout << "Number of devices: " << numDevices << std::endl;

  for (int i = 0; i < numDevices; i++) {
    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(i);
    if (deviceInfo) {
      std::cout << i << ": " << deviceInfo->name 
        << " | Max Output Channels: " << deviceInfo->maxOutputChannels
        << std::endl;
    } else {
    std::cerr << "Failed to get info for device " << i << std::endl;
    }
  }

  
  // Try to use the first output-capable device
  PaDeviceIndex deviceIndex = 13;
  const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(deviceIndex);
  if (!deviceInfo) {
    std::cerr << "Error: Invalid device index!" << std::endl;
    return 1;
  }

  std::cout << "Selected device: " << deviceIndex 
    << " - " << Pa_GetDeviceInfo(deviceIndex)->name << std::endl;

  int input;
  std::cin >> input;
  Pa_Terminate();
  return 0;
}