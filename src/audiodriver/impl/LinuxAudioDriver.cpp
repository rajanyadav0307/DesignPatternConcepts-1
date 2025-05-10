#include "../../../src/audiodriver/LinuxAudioDriver.h"
#include "../../../src/PlayBackStrategy/LoudSpeakerPlayBackStrategy.h"
#include "../../../src/PlayBackStrategy/HeadSetPlayBackStrategy.h"

namespace Drivers
{
     LinuxAudioDriver::LinuxAudioDriver() : m_playbackStrategy{nullptr}, volume{0.0f}
     {
          Notifications::PlatformNotification::Instance()->subscribeNotifications(this);
          setPlayBackStrategy(LoudSpeakerPlayBackStrategy::loudSpeakerPlayBackStrategyInstance());
     }

     LinuxAudioDriver::~LinuxAudioDriver()
     {
          Notifications::PlatformNotification::Instance()->unSubscribeNotifications(this);
     }

     void LinuxAudioDriver::play(std::string &filePath)
     {
          std::cout << "Playing music" << std::endl;

          m_playbackStrategy->strategyPlay();
     }

     void LinuxAudioDriver::stop()
     {
          std::cout << "Playback stopped" << std::endl;
     }

     void LinuxAudioDriver::setPlayBackStrategy(PlayBackStrategy *playBackStrategy)
     {
          m_playbackStrategy = playBackStrategy;
     }

     void LinuxAudioDriver::onAudioHeadSetPluggedIn()
     {
          setPlayBackStrategy(HeadSetPlayBackStrategy::headSetPlayBackStrategyInstance());
     }
     void LinuxAudioDriver::onAudioHeadSetPluggedOut()
     {
          setPlayBackStrategy(LoudSpeakerPlayBackStrategy::loudSpeakerPlayBackStrategyInstance());
     }

     void LinuxAudioDriver::onVolumeIncreased()
     {
     }

     void LinuxAudioDriver::onVolumeDecreased()
     {
     }

     float LinuxAudioDriver::getAudioVolume() { return volume; }
     void LinuxAudioDriver::setAudioVolume(float newVolume) { volume = newVolume; }

}