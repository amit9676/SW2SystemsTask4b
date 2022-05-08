#include <string>
#include "Game.hpp"
#include <iostream>

using namespace std;
namespace coup{
    Game::Game(){
        player = {};
    }

    Game::~Game(){}

    vector<string> Game::players(){
        vector<string> players = {};
        for(auto &i: this->player){
            if(i->deadOrAlive == "alive"){
                players.push_back(i->name);
            }
        }
        return players;
    }

    string Game::winner(){
        if(this->player.size() > 1){
            //throw error
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
        this->player.push_back(&p);
        pair<string,Player*> actions;
        actions.first = "";
        actions.second = nullptr;
        this->lastActions[p.name] = actions;
    }

    void Game::update(){
        
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



}