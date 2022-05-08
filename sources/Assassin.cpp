
#include <string>
#include "Assassin.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    Assassin::Assassin(const Game& game, const string &name):Player(game,name){
        this->role1 = "Assassin";
    }

    Assassin::~Assassin(){}

    void Assassin::coup(Player& p){
        this->isTurn();
        this->notAlive(*this);

        if(this->coins() >=7){
            p.deadOrAlive = "dead";
            //pair<string,*pl
            this->game.lastActions[this->name] = pair<string,Player*>("coup",&p);
        }
        else if(this->coins() >= 3){
            p.deadOrAlive = "almost";
            this->game.lastActions[this->name] = pair<string,Player*>("assassination",&p);
        }
        else{
            //throw exception
        }
        game.update();
        
    }

}