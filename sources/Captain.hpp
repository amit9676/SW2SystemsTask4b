#pragma once
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain : public Player{
        private:

        public:
        Captain(const Game& game, const string&);
        void steal(Player&);
        void block(Player&);
        ~Captain();
        int lastSteal;

    };
}