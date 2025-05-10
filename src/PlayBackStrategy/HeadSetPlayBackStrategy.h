#include "../../src/PlayBackStrategy/PlayBackStrategy.h"

namespace Drivers
{
    class HeadSetPlayBackStrategy : public PlayBackStrategy
    {
    public:
        virtual ~HeadSetPlayBackStrategy() = default;
        static HeadSetPlayBackStrategy *headSetPlayBackStrategyInstance()
        {
            static HeadSetPlayBackStrategy headSetPlayBackStrategyInstance;
            return &headSetPlayBackStrategyInstance;
        }
        virtual Drivers::PlayBackMode getPlayBackStrategy() { return PlayBackMode::HeadSet; }
        virtual void strategyPlay()
        {
            std::cout << "Playing in Head Set" << std::endl;
        }

    private:
        HeadSetPlayBackStrategy() = default;
    };
}