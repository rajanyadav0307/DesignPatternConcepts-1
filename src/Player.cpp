
#include "../include/Player.h"
#include "../src/Mp3AudioPlayer.h"
#include <iostream>

namespace Media
{
    Player::Player() : filePath{""},
                       playButton{new PlayButton()},
                       pauseButton{new PauseButton()},
                       resumeButton{new ResumeButton()},
                       stopButton{new StopButton()},
                       volumeScrollBar{new VolumeScrollBar()},
                       volumeController{new VolumeController()}
    {
    }

    Player::~Player()
    {
        delete playButton;
        delete pauseButton;
        delete resumeButton;
        delete stopButton;
        delete volumeScrollBar;
        delete volumeController;
    }

    Player *Player::Instance()
    {
        static Player player;
        return &player;
    }

    float Player::VolumeController::getCurrentVolume()
    {
        return Media::Mp3AudioPlayer::Instance()->getCurrentVolume();
    }

    void Player::VolumeController::setCurrentVolume(float newVolume)
    {
        Media::Mp3AudioPlayer::Instance()->setCurrentVolume(newVolume);
    }

    void Player::PlayButton::onClicked()
    {
        Media::Mp3AudioPlayer::Instance()->play(Player::Instance()->filePath);
    }

    void Player::PauseButton::onClicked()
    {
        Media::Mp3AudioPlayer::Instance()->pause();
    }

    void Player::ResumeButton::onClicked()
    {
        Media::Mp3AudioPlayer::Instance()->resume();
    }

    void Player::StopButton::onClicked()
    {
        Media::Mp3AudioPlayer::Instance()->stop();
    }

    void Player::VolumeScrollBar::onMovedDown()
    {
        std::cout << "Volume Decreased" << std::endl; // to be implemented
    }

    void Player::VolumeScrollBar::onMovedUp()
    {
        std::cout << "Volume Increased" << std::endl;
    }

    void Player::audioFileSetter(std::string &file)
    {
        filePath = file;
    }

}