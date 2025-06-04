#include <iostream>
#include <portaudio.h>
#include "Init.hpp"
#include "Stream.hpp"

using std::cout;

int main(void);
int main(void) {

  
  PaDeviceIndex deviceIndex = initAudio();
  if (deviceIndex == paNoDevice) 
    return 1;
  // amogus


  int input;
  std::cin >> input;
  

  Pa_Terminate();
  return 0;
}