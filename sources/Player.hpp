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
            coup::Game* game;
            int coin;
            int joinerIndex;
            Player(coup::Game&, const string&);

            void income();
            void foreign_aid();
            virtual void coup(Player&);
            string role();
            int coins() const;
            ~Player();
            
            void isTurn() const;
            void notAlive() const;
            void moreThanTen() const;
            void loneParticipent() const;

        
    };
}