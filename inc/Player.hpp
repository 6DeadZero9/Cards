#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Card.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

#define STARTING_NUMBER_OF_CARDS 6

class Player {
    public: 
        string player_name;

        Player(string player_name) { this->player_name = player_name; };
        void push_card(Card card);
        void show_cards(bool front);
        void clear_cards(void) { this->player_cards.clear(); };
        Card* check_samallest_main(void);
    
    private:
        vector<Card> player_cards;
};

#endif