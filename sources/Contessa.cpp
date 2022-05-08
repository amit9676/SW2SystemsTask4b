#include "Contessa.hpp" 
#include "Player.hpp"
#include <string>

using namespace std;
namespace coup{
    Contessa::Contessa(const Game& game, const string& name):Player(game,name){
        this->role1 = "Contessa";
    }

    Contessa::~Contessa(){}

    void Contessa::block(Player& player){
        //if p status is either either alive or dead - throw exception
        this->notAlive(*this);
        if(player.role() != "Assassin"){
            //throw exception
        }
        if(game.lastActions[player.name].first != "assasination"){
            //throw exception
        }
        if(game.lastActions[player.name].second->deadOrAlive != "almost"){
                //throw exception
        }
        game.lastActions[player.name].second->deadOrAlive = "alive";
    }


}