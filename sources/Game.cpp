#include <string>
#include "Game.hpp"
#include <iostream>

using namespace std;
namespace coup{
    Game::Game(){
        player = {};
        auxelleryList = {};
        gameStarted = false;
    }

    Game::~Game(){}

    vector<string> Game::players(){
        vector<string> players = {};
        for(auto &i: this->auxelleryList){
            players.push_back(i->name);
        }
        return players;
    }

    string Game::winner(){
        if(this->players().size() > 1 || !gameStarted){
            throw runtime_error("game ongoing");
        }
        return this->player.front()->name;
        
    }

    string Game::turn(){
        
        for(size_t i = 0; i < this->player.size(); i++){
            if(this->player[i]->turn){
                return this->player[i]->name;
            }
        }
        return "amit";
    }

    void Game::addPlayer(Player& p){
        if(gameStarted){
            throw runtime_error("game has already started, cant add new players");
        }
        this->player.push_back(&p);
        this->auxelleryList.push_back(&p);
        
        const int six = 6;
        if(this->player.size() > six){
            throw runtime_error("too many players!");
        }
        const int one = 1;
        if(this->player.size() == 1){
            p.turn = true;
        }

        pair<string,Player*> actions;
        actions.first = "";
        actions.second = nullptr;
        this->lastActions[p.name] = actions;
    }

    void Game::update(){
        gameStarted = true;
        this->player[0]->turn = false;
        this->player.push_back(this->player[0]);
        this->player.pop_front();

        while(this->player[0]->deadOrAlive != "alive"){
            if(this->player[0]->deadOrAlive == "almost"){
                this->player.push_back(this->player[0]);
            }
            this->player.pop_front();

            
        }
        this->player[0]->turn = true;
    }

    void Game::auxelleryUpdate(){
        for(size_t i = 0; i < auxelleryList.size(); i++){
            auxelleryList[i]->joinerIndex = i;
        }
    }



}