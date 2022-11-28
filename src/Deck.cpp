#include "../inc/Deck.hpp"
#include "../inc/Common.hpp"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

void Deck::initialize(unsigned char number_of_cards) {
    unsigned role_number_of_cards = number_of_cards / NUMBER_OF_ROLES;
    short unsigned int main_card = rand() % NUMBER_OF_ROLES;

    for (short unsigned int role = 0; role < NUMBER_OF_ROLES; role++) {
        for (short unsigned int card = MAX_NUMBER_ONE_ROLE - role_number_of_cards + 1; card <= MAX_NUMBER_ONE_ROLE; card++) {
            this->original_deck.push_back(Card(card, role, main_card == role));
        }
    }

    auto rng = default_random_engine {};
    shuffle(begin(this->original_deck), end(this->original_deck), rng);

    for (int length = 0; length < this->original_deck.size(); length++) {
        this->original_deck[length].show_card();
    }

    cout << this->original_deck.size() << endl;

    int tmp;
    cin >> tmp;
}