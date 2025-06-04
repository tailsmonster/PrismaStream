#pragma once

#include <iostream>
#include <portaudio.h>
#include "Metadata.h"

// init PortAudio

namespace App::Init {
  void initPortAudio();

  void killPortAudio();
}