#include <iostream>
#include <portaudio.h>
// #include <pa_linux_pulseaudio.h>
#include "Init.hpp"
#include "Stream.hpp"

int main(void) {
  Init::initPrismaStream();
  
  



  int input;
  std::cin >> input;
  
  Init::killPrismaStream();
  return 0;
}