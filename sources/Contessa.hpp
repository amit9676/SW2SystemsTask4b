#pragma once
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
namespace coup{
    class Contessa : public Player{
        private:

        public:
            Contessa(const Game&, const string&);
            void block(Player&);
            ~Contessa();

    };
}