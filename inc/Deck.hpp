#include "../inc/Card.hpp"
#include "../inc/Player.hpp"
#include <vector>

class Deck {
    public:
        Deck() {};

        void initialize(unsigned char number_of_cards, std::vector<Player> *players);
        void populate_used_deck(void) { this->used_deck.insert(
            std::end(this->used_deck), 
            std::begin(this->table), 
            std::end(this->table)); 
        };
        
        void show_deck(void);
        std::vector<Card> table;

    private:
        std::vector<Card> original_deck;
        std::vector<Card> used_deck;
};