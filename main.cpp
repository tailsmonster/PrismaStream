#include <iostream>
#include <portaudio.h>
// #include <pa_linux_pulseaudio.h>
#include "Init.hpp"
#include "Stream.hpp"

int main(void) {

  
  PaDeviceIndex deviceIndex = initAudio();
  if (deviceIndex == paNoDevice) 
    return 1;
  
    


  int input;
  std::cin >> input;
  

  Pa_Terminate();
  return 0;
}