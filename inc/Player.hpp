#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Card.hpp"
#include <vector>
#include <string>

class Player {
    public: 
        std::string player_name;

        Player(std::string player_name) { this->player_name = player_name; };
        void push_card(Card card);
        void show_cards(bool front);
        void clear_cards(void) { this->player_cards.clear(); };
        Card* check_samallest_main(void);
    
    private:
        std::vector<Card> player_cards;
};

#endif