#pragma once

#include <iostream>
#include <portaudio.h>

// init PortAudio and get the default output device
PaDeviceIndex initStream();