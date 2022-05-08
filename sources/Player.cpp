#include "Player.hpp" 
#include <string>
//#include "Game.hpp"

using namespace std;
namespace coup{
    Player::Player(Game& game1, const string& name){
        this->coin = 0;
        this->turn = false;
        this->game = game1;
        this->game.addPlayer(*this);
        
    }

    Player::~Player(){}

    void Player::income(){
        this->isTurn();
        this->notAlive(*this);
        this->moreThanTen(*this);
        this->coin+=1;
        this->game.lastActions[this->name] = pair<string,Player*>("income",nullptr);
        game.update();

    }

    void Player::foreign_aid(){
        this->isTurn();
        this->notAlive(*this);
        this->moreThanTen(*this);
        this->coin+=2;
        this->game.lastActions[this->name] = pair<string,Player*>("foreignAid",nullptr);
        game.update();
        
    }

    string Player::role(){
        return this->role1;
        //return "";
    }

    void Player::coup(Player& p){
        this->isTurn();
        this->notAlive(*this);

        p.deadOrAlive = "dead";
        this->game.lastActions[this->name] = pair<string,Player*>("coup",&p);
        game.update();
    }

    int Player::coins(){
        return this->coin;
    }

    void Player::isTurn(){
        if(!this->turn){
            //THROW EXCPETION
        }
    }

    void Player::notAlive(Player &p){
        if(p.deadOrAlive != "alive"){
            //throw exception
        }
    }

    void Player::moreThanTen(Player &p){
        if(p.coin >= 10){
            //throw exception
        }
    }

}