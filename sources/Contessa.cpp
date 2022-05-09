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
        this->notAlive();
        player.notAlive();
        if(player.role() != "Assassin"){
            throw runtime_error("costenna can only block assassins");
        }
        if(game->lastActions[player.name].first != "assassination"){
            throw runtime_error("player last move was not assassination");
        }
        if(game->lastActions[player.name].second->deadOrAlive != "almost"){
                throw runtime_error("costenna can only block assassin coup");
        }
        game->lastActions[player.name].second->deadOrAlive = "alive";

        //for tests only
        this->game->auxelleryList.insert(this->game->auxelleryList.begin() + player.joinerIndex, game->lastActions[player.name].second);
        this->game->auxelleryUpdate();
        
    }


}