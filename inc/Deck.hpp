#include "../inc/Card.hpp"
#include <vector>

#define MAX_NUMBER_ONE_ROLE 14

using std::vector;

class Deck {
    public:
        Deck() {};

        void initialize(unsigned char number_of_cards);
    private:
        vector <Card> original_deck;
        vector <Card> used_deck;
};