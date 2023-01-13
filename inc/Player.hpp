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
        Card get_card(unsigned int index, bool remove);
        void remove_card(unsigned int index);
        void show_cards(bool front, bool show_list);
        void clear_cards(void) { this->player_cards.clear(); };
        void push_cards(std::vector<Card> new_cards) { this->player_cards.insert(
            std::end(this->player_cards), 
            std::begin(new_cards), 
            std::end(new_cards)); 
        };
        Card* check_samallest_main(void);
        bool check_if_card_exists(unsigned int index);
    
    private:
        std::vector<Card> player_cards;
};

#endif