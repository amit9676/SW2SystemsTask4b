#pragma once
#include <vector>
#include <string>
#include <queue>
#include <map>
#include "Player.hpp"

using namespace std;
namespace coup{
    class Player;
    class Game
    {
        private:
        public:
            Game();
            ~Game();
            bool gameStarted;
            deque<Player*> player;
            vector<Player*> auxelleryList;
            string turn();
            vector<string> players();
            string winner();
            map<string,pair<string,Player*>> lastActions;
            void addPlayer(Player &p);
            void update();
            void auxelleryUpdate();
    };
}