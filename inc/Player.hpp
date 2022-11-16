#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Card.hpp"
#include <vector>

using std::vector;

class Player {
    public: 
        vector<Card> player_cards;

        Player();
};

#endif