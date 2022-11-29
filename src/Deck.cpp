#include "../inc/Deck.hpp"
#include "../inc/Common.hpp"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

void Deck::initialize(unsigned char number_of_cards, Player* player_1, Player* player_2) {
    this->original_deck.clear();
    player_1->clear_cards();
    player_2->clear_cards();
    unsigned role_number_of_cards = number_of_cards / NUMBER_OF_ROLES;
    short unsigned int main_card = rand() % NUMBER_OF_ROLES;

    for (short unsigned int role = 0; role < NUMBER_OF_ROLES; role++) {
        for (short unsigned int card = MAX_NUMBER_ONE_ROLE - role_number_of_cards + 1; card <= MAX_NUMBER_ONE_ROLE; card++) {
            this->original_deck.push_back(Card(card, role, main_card == role));
        }
    }

    shuffle(begin(this->original_deck), end(this->original_deck), random_device());

    for (auto &player : { player_1, player_2 }) {
        for (int card = 0; card < FIRST_HAND; card++) {
            player->push_card(this->original_deck.back());
            this->original_deck.pop_back();
        }
    }

    player_1->show_cards();
    int temp; cin >> temp;
}