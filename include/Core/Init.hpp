#pragma once

#include <iostream>
#include <portaudio.h>
// #include "Metadata.h"

// init PortAudio

namespace Init {
  void initPrismaStream();

  void killPrismaStream();
}