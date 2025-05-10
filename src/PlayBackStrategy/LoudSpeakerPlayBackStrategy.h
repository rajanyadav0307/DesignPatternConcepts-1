#include "../../src/PlayBackStrategy/PlayBackStrategy.h"

namespace Drivers
{
    class LoudSpeakerPlayBackStrategy : public PlayBackStrategy
    {
    public:
        virtual ~LoudSpeakerPlayBackStrategy() = default;
        static LoudSpeakerPlayBackStrategy *loudSpeakerPlayBackStrategyInstance()
        {
            static LoudSpeakerPlayBackStrategy loudSpeakerPlayBackStrategyInstance;
            return &loudSpeakerPlayBackStrategyInstance;
        }
        virtual Drivers::PlayBackMode getPlayBackStrategy() { return PlayBackMode::LoudSpeaker; }
        virtual void strategyPlay()
        {
            std::cout << "Playing in Loud Speaker" << std::endl;
        }

    private:
        LoudSpeakerPlayBackStrategy() = default;
    };
}