#pragma once
#include "Game.hpp"
using namespace std;
namespace coup{
    class Game;
    class Player{
        private:
            
        protected:
            
            string role1;
            
            
        public:
            string name;
            bool turn;
            string deadOrAlive;
            coup::Game game;
            int coin;
            Player(coup::Game&, const string&);

            void income();
            void foreign_aid();
            virtual void coup(Player&);
            string role();
            int coins();
            ~Player();
            
            void isTurn();
            void notAlive(Player&);
            void moreThanTen(Player&);

        
    };
}