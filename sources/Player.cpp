#include "Player.hpp" 
#include <string>

using namespace std;
namespace coup{
    Player::Player(Game& game1, const string& name){
        this->coin = 0;
        this->turn = false;
        this->game = &game1;
        this->joinerIndex = this->game->auxelleryList.size();
        this->game->addPlayer(*this);
        this->deadOrAlive = "alive";
        this->name = name;
        
        
    }

    Player::~Player(){}

    void Player::income(){
        this->loneParticipent();
        this->isTurn();
        this->notAlive();
        this->moreThanTen();
        this->coin+=1;
        this->game->lastActions[this->name] = pair<string,Player*>("income",nullptr);
        game->update();

    }

    void Player::foreign_aid(){
        this->loneParticipent();
        this->isTurn();
        this->notAlive();
        this->moreThanTen();
        this->coin+=2;
        this->game->lastActions[this->name] = pair<string,Player*>("foreignAid",nullptr);
        game->update();
        
    }

    string Player::role(){
        return this->role1;
    }

    void Player::coup(Player& p){
        this->loneParticipent();
        this->isTurn();
        this->notAlive();
        p.notAlive();

        const int seven = 7;
        if(this->coin< seven){
            throw runtime_error("not enough coins for operation");
        }
        this->coin -=seven;
        
        p.deadOrAlive = "dead";
        this->game->lastActions[this->name] = pair<string,Player*>("coup",&p);

        //for tests only
        this->game->auxelleryList.erase(this->game->auxelleryList.begin()  + p.joinerIndex);
        this->game->auxelleryUpdate();
        //

        game->update();
    }

    int Player::coins() const{
        return this->coin;
    }

    void Player::isTurn() const{
        if(!this->turn){
            throw runtime_error("not the player's turn");
        }
    }

    void Player::notAlive() const{
        if(this->deadOrAlive != "alive"){
            throw runtime_error("player has already being couped");
        }
    }

    void Player::moreThanTen() const{
        const int ten = 10;
        if(this->coin >= ten){
            throw runtime_error("player has 10 or more coins, doing coup is must");
        }
    }

    void Player::loneParticipent() const{
        if(this->game->player.size() == 1){
            throw runtime_error("cant play with one participent only");
        }
    }

}