#include "../include/ui/ButtonInterface.h"
#include "../include/ui/VerticalScrollBar.h"
#include <string>

namespace Media
{

    class Player
    {
    public:
        virtual ~Player();

        static Player *Instance();

        class VolumeController
        {
        public:
            float getCurrentVolume();
            void setCurrentVolume(float newVolume);
        };

        class PlayButton : public Button
        {
        public:
            void onClicked() override;
        };

        class PauseButton : public Button
        {
        public:
            void onClicked() override;
        };

        class ResumeButton : public Button
        {
        public:
            void onClicked() override;
        };

        class StopButton : public Button
        {
        public:
            void onClicked() override;
        };

        class VolumeScrollBar : public VerticalScrollBar
        {
        public:
            virtual void onMovedUp() override;
            virtual void onMovedDown() override;
        };

        void audioFileSetter(std::string &file);

        inline void pressPlay() { playButton->onClicked(); }

        inline void pressPause() { pauseButton->onClicked(); }

        inline void pressResume() { resumeButton->onClicked(); }

        inline void pressStop() { stopButton->onClicked(); }

        inline void scrollVolumeUp() { volumeScrollBar->onMovedUp(); }

        inline void scrollVolumeDown() { volumeScrollBar->onMovedDown(); }

        friend class VolumeController;
        friend class PlayButton;
        friend class PauseButton;
        friend class ResumeButton;
        friend class StopButton;
        friend class VolumeScrollBar;

    private:
        Player();
        std::string filePath;
        PlayButton *playButton;
        PauseButton *pauseButton;
        ResumeButton *resumeButton;
        StopButton *stopButton;
        VolumeScrollBar *volumeScrollBar;
        VolumeController *volumeController;
    };

} // Media