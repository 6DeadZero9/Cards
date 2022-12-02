#include "../inc/Card.hpp"
#include "../inc/Player.hpp"
#include <vector>

#define MAX_NUMBER_ONE_ROLE 14
#define FIRST_HAND 6

using std::vector;

class Deck {
    public:
        Deck() {};

        void initialize(unsigned char number_of_cards, vector<Player> *players);
    private:
        vector <Card> original_deck;
        vector <Card> used_deck;
};