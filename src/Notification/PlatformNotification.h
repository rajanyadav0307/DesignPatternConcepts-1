#include <mutex>
#include <vector>

namespace Notifications
{

    class PlatformNotification
    {
    public:
        virtual ~PlatformNotification() = default;

        static PlatformNotification* Instance();

        enum class Events
        {
            Head_Set_Plugged_In,
            Head_Set_Plugged_Out,
            Volume_Increased,
            Volume_Decreased
        };

        struct Clients
        {
            virtual ~Clients() = default;
            virtual void onAudioHeadSetPluggedIn() = 0;
            virtual void onAudioHeadSetPluggedOut() = 0;
            virtual void onVolumeIncreased() = 0;
            virtual void onVolumeDecreased() = 0;
        };

        using ClientList = std::vector<Clients*>;

        void subscribeNotifications(Clients *client);
        void unSubscribeNotifications(Clients *client);
        void dispatchEvent(Events event);

    private:
        ClientList m_clients;
        PlatformNotification() = default;
        std::mutex listMutex;
    };
} // Notifications