#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup {

    class Ambassador : public Player{

    public:
        Ambassador(Game& game, string Name) :
                Player(&game, Name) {}

        void transfer(Player& p1, Player& p2);

        string role() override;
    };
}