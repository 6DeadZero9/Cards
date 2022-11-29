#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Card.hpp"
#include <vector>

using std::vector;

#define STARTING_NUMBER_OF_CARDS 6

class Player {
    public: 
        Player(void) {};
        void push_card(Card card);
        void show_cards(void);
        void clear_cards(void) { this->player_cards.clear(); };
    
    private:
        vector<Card> player_cards;
};

#endif