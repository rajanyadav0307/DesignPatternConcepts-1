#include <cassert>
#include "../include/Player.h"

int main()
{
    Media::Player* player = Media::Player::Instance();
    std::string file = "/opt/data/audio/song.mp3";
    player->audioFileSetter(file);
    player->pressPlay();
    player->scrollVolumeUp();
    player->pressPause();
    player->pressResume();
    player->scrollVolumeDown();
    player->pressStop();
}