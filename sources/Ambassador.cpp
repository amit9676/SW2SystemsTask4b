
#include <string>
#include "Ambassador.hpp"
#include "Player.hpp"
#include "Captain.hpp"

using namespace std;
namespace coup{
    Ambassador::Ambassador(const Game& game, const string &name):Player(game,name){
        this->role1 = "Ambassador";
    }

    Ambassador::~Ambassador(){}

    void Ambassador::block(Player& p){
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

    void Ambassador::transfer(Player& giver, Player& reciever){
        this->isTurn();
        this->notAlive(*this);
        this->moreThanTen(*this);
        if(giver.deadOrAlive != "alive" || reciever.deadOrAlive != "alive"){
            //throw exception
        }
        if(giver.coin < 1){
            //throw exception

        }
        giver.coin--;
        reciever.coin++;
        this->game.lastActions[this->name] = pair<string,Player*>("transfer",nullptr);
        game.update();
    }

}