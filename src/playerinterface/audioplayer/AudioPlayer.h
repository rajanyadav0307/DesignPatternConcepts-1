#include "../../../src/playerinterface/PlayerInterface.h"
#include "../src/audiodriver/PlatformAudioDriver.h"
#include "../src/audiodriver/AudioDriverFactory.h"
#include <iostream>

namespace Media
{

    class AudioPauseState : public PauseState
    {
    public:
        void play(PlayerInterface *player, std::string &filePath) override
        {
            std::cout << "Meida can't play from pause state; try resume" << std::endl;
        }

        void pause(PlayerInterface *player) override
        {
            std::cout << "Meida can't pause since it is in pause state" << std::endl;
        }

        void resume(PlayerInterface *player) override;

        void stop(PlayerInterface *player) override;
    };

    class AudioEndState : public EndState
    {
    public:
        void play(PlayerInterface *player, std::string &filePath) override
        {
            std::cout << "Media can't play since it is in end state" << std::endl;
        }

        void pause(PlayerInterface *player) override
        {
            std::cout << "Media can't pause since it is in end state" << std::endl;
        }

        void resume(PlayerInterface *player) override
        {
            std::cout << "Media can't resume since it is in end state" << std::endl;
        }

        void stop(PlayerInterface *player) override
        {
            std::cout << "Media can't stop since it is in end state" << std::endl;
        }
    };
    class AudioPlayState : public PlayState
    {
    public:
        void play(PlayerInterface *player, std::string &filePath) override
        {
            std::cout << "Meida can't play since it is in play state" << std::endl;
        }

        void pause(PlayerInterface *player) override;

        void resume(PlayerInterface *player) override
        {
            std::cout << "Meida can't resume since it is in play state" << std::endl;
        }

        void stop(PlayerInterface *player) override;
    };

    class AudioReadyState : public ReadyState
    {
    public:
        void play(PlayerInterface *player, std::string &filePath) override;
        void pause(PlayerInterface *player) override
        {
            std::cout << "Meida can't pause since it is in ready state" << std::endl;
        }

        void resume(PlayerInterface *player) override
        {
            std::cout << "Meida can't resume since it is in ready state" << std::endl;
        }

        void stop(PlayerInterface *player) override
        {
            std::cout << "Meida can't stop since it is in ready state" << std::endl;
        }
    };

    class AudioPlayer : public PlayerInterface
    {
    public:
        virtual ~AudioPlayer() = default;
        AudioPlayer();
        Drivers::PlatformAudioDriver *audioDriver;
    };
} // Media