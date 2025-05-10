#pragma once
#include "../../src/Common/Common.h"
#include <iostream>

namespace Drivers
{

    class PlayBackStrategy
    {
        public:
        virtual Drivers::PlayBackMode getPlayBackStrategy() = 0;
        virtual void strategyPlay() = 0;
    };
}