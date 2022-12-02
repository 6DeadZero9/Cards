#include "../inc/Deck.hpp"
#include "../inc/Common.hpp"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

void Deck::initialize(unsigned char number_of_cards, vector<Player> *players) {
    unsigned role_number_of_cards = number_of_cards / NUMBER_OF_ROLES;
    unsigned cards_for_one_player = number_of_cards / players->size();
    cards_for_one_player = cards_for_one_player < FIRST_HAND ? cards_for_one_player : FIRST_HAND;
    short unsigned int main_card;
   
    this->original_deck.clear();
    for (auto &player : *players) {
        player.clear_cards();
    }

    for (short unsigned int role = 0; role < NUMBER_OF_ROLES; role++) {
        for (short unsigned int card = MAX_NUMBER_ONE_ROLE - role_number_of_cards + 1; card <= MAX_NUMBER_ONE_ROLE; card++) {
            this->original_deck.push_back(Card(card, role));
        }
    }

    shuffle(begin(this->original_deck), end(this->original_deck), random_device());

    for (auto card : this->original_deck) {
        if (card.card_role == this->original_deck[0].card_role) {
            card.is_main = true;
        }
    }

    for (auto &player : *players) {
        for (int card = 0; card < cards_for_one_player; card++) {
            player.push_card(this->original_deck.back());
            this->original_deck.pop_back();
        }
    }
}