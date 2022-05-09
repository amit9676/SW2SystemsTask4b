#pragma once
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin : public Player{
        private:

        public:
        Assassin(Game&, const string&);
        void coup(Player&);
        ~Assassin();

    };
}