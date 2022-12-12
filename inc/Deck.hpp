#include "../inc/Card.hpp"
#include "../inc/Player.hpp"
#include <vector>

class Deck {
    public:
        Deck() {};

        void initialize(unsigned char number_of_cards, std::vector<Player> *players);
        void show_deck(void);
    private:
        std::vector<Card> original_deck;
        std::vector<Card> used_deck;
        std::vector<Card> table;
};