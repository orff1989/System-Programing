#include "Captain.hpp"

namespace coup{

    void Captain::steal(Player& p) {
        if(_game->turn()==_name) {
            if (p.coins()>=2){
                p.decreasCoins(2);
                _coins+=2;
            }
            else if (p.coins()==1){
                p.decreasCoins(1);
                _coins+=1;
            }
            else{
                throw "this player has not enough money";
            }
            _game->next_turn();
            set_lastCommand("steal "+p.getName());
        } else{
            throw "it is not your turn!";
        }


    }

    string Captain::role() {
        return "Captain";
    }
}