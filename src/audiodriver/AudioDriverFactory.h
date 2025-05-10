#define PULSE

#ifdef WAVE
#include "../../src/audiodriver/WindowsAudioDriver.h"
#elif  defined(PULSE)
#include "../../src/audiodriver/LinuxAudioDriver.h"
#elif defined(MAC)
#include "../../src/audiodriver/UnixAudioDriver.h"
#endif

#include "../../src/audiodriver/PlatformAudioDriver.h"

class AudioDriverFactory
{
public:
        static Drivers::PlatformAudioDriver *getAudioDriver()
        {
#ifdef WAVE
                return new Drivers::WindowsAudioDriver();
#elif defined(PULSE)
                return new Drivers::LinuxAudioDriver();
#elif defined(MAC)
                return new Drivers::UnixAudioDriver();
#endif
        }
};
