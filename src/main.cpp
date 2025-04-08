#include <iostream>
#include <portaudio.h>
#include "../include/pa_init.hpp"
#include "../include/stream.hpp"

int main() {
  PaDeviceIndex deviceIndex = initAudio();
  if (deviceIndex == paNoDevice) 
    return 1;
  // amogus


  int input;
  std::cin >> input;
  

  Pa_Terminate();
  return 0;
}