#pragma once
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador : public Player{
        private:

        public:
        Ambassador(const Game&, const string&);
        void transfer(Player&,Player&);
        void block(Player&);
        ~Ambassador();

    };
}