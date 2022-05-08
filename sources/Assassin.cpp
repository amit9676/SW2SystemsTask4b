
#include <string>
#include "Assassin.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    Assassin::Assassin(Game& game, const string &name):Player(game,name){
        this->role1 = "Assassin";
    }

    Assassin::~Assassin(){}

    void Assassin::coup(Player& p){
        this->isTurn();
        this->notAlive();
        const int seven = 7;
        const int three = 3;

        if(this->coins() >=seven){
            p.deadOrAlive = "dead";
            //pair<string,*pl
            this->game->lastActions[this->name] = pair<string,Player*>("coup",&p);
        }
        else if(this->coins() >= three){
            p.deadOrAlive = "almost";
            this->game->lastActions[this->name] = pair<string,Player*>("assassination",&p);
        }
        else{
            throw runtime_error("not enough coins for assassination");
        }
        game->update();
        
    }

}