#include "../src/Mp3AudioPlayer.h"

namespace Media
{
    Mp3AudioPlayer::Mp3AudioPlayer() : Media::AudioPlayer()
    {

    }
    Mp3AudioPlayer *Mp3AudioPlayer::Instance()
    {
        static Mp3AudioPlayer player;
        return &player;
    }

    float Mp3AudioPlayer::getCurrentVolume()
    {
       return audioDriver->getAudioVolume();
    }

    void Mp3AudioPlayer::setCurrentVolume(float &newVolume)
    {
        audioDriver->setAudioVolume(newVolume);
    }

    void Mp3AudioPlayer::play(std::string &filePath)
    {
        state->play(this, filePath);
    }
    void Mp3AudioPlayer::pause()
    {
        state->pause(this);
    }
    void Mp3AudioPlayer::resume()
    {
        state->resume(this);
    }
    void Mp3AudioPlayer::stop()
    {
        state->stop(this);
    }

}