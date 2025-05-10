#include "../../src/audiodriver/PlatformAudioDriver.h"
#include "../../src/Notification/PlatformNotification.h"

namespace Drivers
{
    class LinuxAudioDriver : public PlatformAudioDriver, public Notifications::PlatformNotification::Clients
    {
    public:
        LinuxAudioDriver();
        ~LinuxAudioDriver();    

        // PlatformAudioDrivers
        virtual void play(std::string &filePath) override;
        virtual void stop() override;
        virtual void setPlayBackStrategy(PlayBackStrategy *playBackStrategy) override;
        virtual float getAudioVolume() override;
        virtual void setAudioVolume(float newVolume) override;

        // Clients API
        virtual void onAudioHeadSetPluggedIn() override;
        virtual void onAudioHeadSetPluggedOut() override;
        virtual void onVolumeIncreased() override;
        virtual void onVolumeDecreased() override;

    private:
        PlayBackStrategy *m_playbackStrategy;
        float volume;
    };
}   //Drivers