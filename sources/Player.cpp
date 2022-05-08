#include "Player.hpp" 
#include <string>
//#include "Game.hpp"

using namespace std;
namespace coup{
    Player::Player(Game& game1, const string& name){
        this->coin = 0;
        this->turn = false;
        this->game = &game1;
        this->game->addPlayer(*this);
        
    }

    Player::~Player(){}

    void Player::income(){
        this->isTurn();
        this->notAlive();
        this->moreThanTen();
        this->coin+=1;
        this->game->lastActions[this->name] = pair<string,Player*>("income",nullptr);
        game->update();

    }

    void Player::foreign_aid(){
        this->isTurn();
        this->notAlive();
        this->moreThanTen();
        this->coin+=2;
        this->game->lastActions[this->name] = pair<string,Player*>("foreignAid",nullptr);
        game->update();
        
    }

    string Player::role(){
        return this->role1;
        //return "";
    }

    void Player::coup(Player& p){
        this->isTurn();
        this->notAlive();

        p.deadOrAlive = "dead";
        this->game->lastActions[this->name] = pair<string,Player*>("coup",&p);
        game->update();
    }

    int Player::coins() const{
        return this->coin;
    }

    void Player::isTurn() const{
        if(!this->turn){
            //THROW EXCPETION
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

}