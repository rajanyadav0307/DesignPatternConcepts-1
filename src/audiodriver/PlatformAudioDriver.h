#pragma once

#include <string>
#include "../../src/PlayBackStrategy/PlayBackStrategy.h"

namespace Drivers
{
    class PlatformAudioDriver
    {
        public:
        virtual void play(std::string &filePath) = 0;
        virtual void stop() = 0;
        virtual void setPlayBackStrategy(PlayBackStrategy *playBackStrategy) = 0;
        virtual float getAudioVolume() = 0;
        virtual void setAudioVolume(float newVolume) = 0;
    };
}   //Drivers