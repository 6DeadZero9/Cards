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
        void remove_card(unsigned int index);
        void show_cards(bool front, bool show_list);
        void clear_cards(void) { player_cards.clear(); };
        void push_cards(std::vector<Card> new_cards) { player_cards.insert(
            std::end(player_cards), 
            std::begin(new_cards), 
            std::end(new_cards)); 
        };
        int deck_size(void) { return player_cards.size(); };
        bool check_if_card_exists(unsigned int index);
        Card get_card(unsigned int index, bool remove);
        Card* check_samallest_main(void);
    
    private:
        std::vector<Card> player_cards;
};

#endif