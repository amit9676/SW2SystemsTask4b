#include "Contessa.hpp" 
#include "Player.hpp"
#include <string>

using namespace std;
namespace coup{
    Contessa::Contessa(Game& game, const string& name):Player(game,name){
        this->role1 = "Contessa";
    }

    Contessa::~Contessa(){}

    void Contessa::block(Player& player){
        //if p status is either either alive or dead - throw exception
        this->notAlive();
        if(player.role() != "Assassin"){
            throw runtime_error("costenna can only block assassins");
        }
        if(game->lastActions[player.name].first != "assasination"){
            throw runtime_error("player last move was not assassination");
        }
        if(game->lastActions[player.name].second->deadOrAlive != "almost"){
                throw runtime_error("costenna can only block assassin coup");
        }
        game->lastActions[player.name].second->deadOrAlive = "alive";
    }


}