#include "Ambassador.hpp"

namespace coup{
    void Ambassador::transfer(Player& p1, Player& p2) {
        if(_game->turn()==_name) {
            p1.decreasCoins(1);
            p2.increaseCoins(1);
            _game->next_turn();
            this->set_lastCommand("transfer");
        } else{
            throw "it is not your turn!";
        }
    }

    string Ambassador::role() {
        return "Ambassador";
    }

}