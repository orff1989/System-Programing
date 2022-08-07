#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup {

    class Captain : public Player{

    public:
        Captain(Game& game, string Name) :
                Player(&game, Name) {}


        void steal(Player& p);

        string role() override;
    };
}