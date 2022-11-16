#include "../inc/Card.hpp"
#include <vector>

using std::vector;

class Deck {
    public:
        Deck();

    private:
        vector <Card> original_deck;
        vector <Card> used_deck;
};