#include "../../../src/playerinterface/audioplayer/AudioPlayer.h"

namespace Media
{
    AudioPlayer::AudioPlayer() : PlayerInterface(new AudioReadyState()),
                                 audioDriver{AudioDriverFactory::getAudioDriver()}
    {
    }

    void AudioPauseState::resume(PlayerInterface *player)
    {
        AudioPlayer* audioPlayer = dynamic_cast<AudioPlayer*>(player);
        std::cout << "Player Resumed" << std::endl;
        if (currentFilePath != "")
        {
            audioPlayer->setPlayerState(new AudioPlayState());
            audioPlayer->audioDriver->play(currentFilePath);
        }
        else
        {
            std::cout << "Player can't resume" << std::endl;
        }
    }

    void AudioPauseState::stop(PlayerInterface *player)
    {
        std::cout << "Player Stopped" << std::endl;
        player->setPlayerState(new Media::AudioEndState());
    }

    void AudioPlayState::pause(PlayerInterface *player)
    {
        std::cout << "Player Paused" << std::endl;
        player->setPlayerState(new Media::AudioPauseState());
    }

    void AudioPlayState::stop(PlayerInterface *player)
    {
        std::cout << "Player Stopped" << std::endl;
        player->setPlayerState(new Media::AudioEndState());
    }

    void AudioReadyState::play(PlayerInterface *player, std::string &filePath)
    {
        AudioPlayer* audioPlayer = dynamic_cast<AudioPlayer*>(player);
        std::cout << "Media Starting to Play..." << std::endl;
        audioPlayer->setPlayerState(new Media::AudioPlayState());
        currentFilePath = filePath;
        audioPlayer->audioDriver->play(filePath);
    }
} // namespace Media
