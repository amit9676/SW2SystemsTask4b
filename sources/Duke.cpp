
#include <string>
#include "Player.hpp"
#include "Duke.hpp"

using namespace std;
namespace coup{
    Duke::Duke(Game& game, const string& name):Player(game,name){
        this->role1 = "Duke";
    }

    Duke::~Duke(){}

    void Duke::block(Player& p){
        //(if on memory last action of said player is not foreign aid - throw exception)
        //else if said player is no alonger alive - throw exception
        if(game->lastActions[p.name].first != "foreignAid"){
            throw runtime_error("player last move was not foreign aid");
        }
        this->notAlive();
        p.coin -= 2;
    }

    void Duke::tax(){
        this->isTurn();
        this->notAlive();
        this->moreThanTen();
        this->coin +=3;
        this->game->lastActions[this->name] = pair<string,Player*>("tax",nullptr);
        game->update();
    }

}