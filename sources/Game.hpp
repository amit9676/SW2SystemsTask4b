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
            //vector<string> player;
            
            //string turns;
        public:
            Game();
            ~Game();
            deque<Player*> player;
            string turn();
            vector<string> players();
            //static vector<string> players();
            string winner();
            map<string,pair<string,Player*>> lastActions;
            void addPlayer(Player &p);
            void update();
            //void checkturn();
    };
}