#include "../../src/Notification/PlatformNotification.h"
#include <algorithm>  // for std::find, std::remove
#include <iterator>   // for std::end()
namespace Notifications
{
    PlatformNotification *PlatformNotification::Instance()
    {
        static PlatformNotification notificationInstance;
        return &notificationInstance;
    }

    void PlatformNotification::subscribeNotifications(Clients *client)
    {
        if (!client)
            return;
        std::unique_lock<std::mutex> lock(listMutex);
        if (std::find(m_clients.begin(), m_clients.end(), client) == m_clients.end())
        {
            m_clients.push_back(client);
        }
    }
    void PlatformNotification::unSubscribeNotifications(Clients *client)
    {
        if (!client)
            return;
        std::unique_lock<std::mutex> lock(listMutex);
        m_clients.erase(std::remove(m_clients.begin(), m_clients.end(), client), m_clients.end());
    }
    
    void PlatformNotification::dispatchEvent(Events event)
    {
        std::unique_lock<std::mutex> lock(listMutex);
        for (Clients *client : m_clients)
        {
            switch (event)
            {
            case PlatformNotification::Events::Head_Set_Plugged_In:
            {
                client->onAudioHeadSetPluggedIn();
                break;
            }
            case PlatformNotification::Events::Head_Set_Plugged_Out:
            {
                client->onAudioHeadSetPluggedOut();
                break;
            }
            case PlatformNotification::Events::Volume_Increased:
            {
                client->onVolumeIncreased();
                break;
            }
            case PlatformNotification::Events::Volume_Decreased:
            {
                client->onVolumeDecreased();
                break;
            }
            default:
                break;
            }
        }
    }

}