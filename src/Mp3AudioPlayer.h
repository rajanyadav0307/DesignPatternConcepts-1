#include "../src/playerinterface/audioplayer/AudioPlayer.h"

namespace Media
{

    class Mp3AudioPlayer : public AudioPlayer
    {
    public:
        virtual ~Mp3AudioPlayer() = default;

        static Mp3AudioPlayer *Instance();

        // PlayerInterface
        void play(std::string &filePath) override;
        void pause() override;
        void resume() override;
        void stop() override;

        float getCurrentVolume(); // Volume in 0.0 - 1.0
        void setCurrentVolume(float &newVolume);

    private:
        Mp3AudioPlayer();
    };

}