#include <string>
namespace Media
{
    class PlayerInterface;

    class PlayerState
    {
    public:
        virtual ~PlayerState() = default;

        virtual void play(PlayerInterface *player, std::string &filePath) = 0;

        virtual void pause(PlayerInterface *player) = 0;

        virtual void resume(PlayerInterface *player) = 0;

        virtual void stop(PlayerInterface *player) = 0;

    protected:
        std::string currentFilePath{""};
    };

    class ReadyState : public PlayerState
    {
    public:
        virtual ~ReadyState() = default;

        virtual void play(PlayerInterface *player, std::string &filePath) = 0;

        virtual void pause(PlayerInterface *player) = 0;

        virtual void resume(PlayerInterface *player) = 0;

        virtual void stop(PlayerInterface *player) = 0;
    };

    class PlayState : public PlayerState
    {
    public:
        virtual ~PlayState() = default;
        virtual void play(PlayerInterface *player, std::string &filePath) = 0;

        virtual void pause(PlayerInterface *player) = 0;

        virtual void resume(PlayerInterface *player) = 0;

        virtual void stop(PlayerInterface *player) = 0;
    };

    class PauseState : public PlayerState
    {
    public:
        virtual ~PauseState() = default;
        virtual void play(PlayerInterface *player, std::string &filePath) = 0;

        virtual void pause(PlayerInterface *player) = 0;

        virtual void resume(PlayerInterface *player) = 0;

        virtual void stop(PlayerInterface *player) = 0;
    };

    class EndState : public PlayerState
    {
    public:
        virtual ~EndState() = default;
        virtual void play(PlayerInterface *player, std::string &filePath) = 0;

        virtual void pause(PlayerInterface *player) = 0;

        virtual void resume(PlayerInterface *player) = 0;

        virtual void stop(PlayerInterface *player) = 0;
    };

    class PlayerInterface
    {
    public:
        virtual ~PlayerInterface() = default;

        PlayerInterface(PlayerState *initialState) : state{initialState} {}

        virtual void play(std::string &filePath) = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void stop() = 0;

        virtual void setPlayerState(PlayerState *newState)
        {
            state = newState;
        }

        PlayerState *state;
    };

}