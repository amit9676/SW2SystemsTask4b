#include <string>
#include "Captain.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    Captain::Captain(Game& game, const string& name):Player(game,name){
        this->role1 = "Captain";
        this->lastSteal = 0;
    }

    Captain::~Captain(){}

    void Captain::steal(Player& p){
        this->loneParticipent();
        this->isTurn();
        this->notAlive();
        this->moreThanTen();

        this->game->lastActions[this->name] = pair<string,Player*>("steal",&p);
        if(p.coin >= 2){
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
        game->update();
    }

    void Captain::block(Player& p){
        this->notAlive();
        if(p.role() != "Captain"){
            throw runtime_error("captain can only bloack captain");
        }
        if(this->game->lastActions[p.name].first != "steal"){
            throw runtime_error("blocked palyer last move was not steal");
        }
        if(p.deadOrAlive != "alive" || this->game->lastActions[p.name].second->deadOrAlive != "alive"){
            throw runtime_error("captain can only block from living captain");
        }
        Captain* c = dynamic_cast<Captain*>(&p);
        c->coin -= c->lastSteal;
        this->game->lastActions[p.name].second->coin += c->lastSteal;
    }

}