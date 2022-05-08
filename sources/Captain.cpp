//#include "Player.hpp" 
#include <string>
//#include "Game.hpp"
#include "Captain.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    Captain::Captain(const Game& game, const string& name):Player(game,name){
        this->role1 = "Captain";
        this->lastSteal = 0;
    }

    Captain::~Captain(){}

    void Captain::steal(Player& p){
        this->isTurn();
        this->notAlive(*this);
        this->moreThanTen(*this);

        this->game.lastActions[this->name] = pair<string,Player*>("steal",&p);
        if(p.coin > 2){
            p.coin -=2;
            this->coin+=2;
            this->lastSteal = 2;
        }
        else if(p.coin == 1){
            p.coin -=1;
            this->coin+=1;
            this->lastSteal = 1;
        }
        else{
            this->lastSteal = 0;
        }
        game.update();
    }

    void Captain::block(Player& p){
        this->notAlive(*this);
        if(p.role() != "Captain"){
            //throw exception
        }
        if(this->game.lastActions[p.name].first != "steal"){
            //throw excption
        }
        if(p.deadOrAlive != "alive" || this->game.lastActions[p.name].second->deadOrAlive != "alive"){
            //throw exception
        }
        Captain* c = (Captain* )&p;
        c->coin -= c->lastSteal;
        this->game.lastActions[p.name].second->coin += c->lastSteal;
    }

}