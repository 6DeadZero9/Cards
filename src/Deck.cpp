#define FMT_HEADER_ONLY

#include "../inc/Deck.hpp"
#include "../inc/Common.hpp"
#include <fmt/format.h>
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;
Common common = Common();

void Deck::initialize(unsigned char number_of_cards, std::vector<Player> *players) {
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

    for (auto &card : this->original_deck) {
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

void Deck::show_deck(void) {
    if (this->original_deck.empty()) return;
    Common common = Common();
    int cards_to_show = this->original_deck.size() > SHOW_DECK ? SHOW_DECK - 1 : this->original_deck.size();
    std::vector<Card> to_iterate = common.slicing(this->original_deck, 0, cards_to_show);

    for (int step = 0; step < this->original_deck.back().card_repr.size(); step++) { 
        int card_step = 0;

        for (auto &card : to_iterate) {
            std::vector<string> show = card_step ? card.card_back : card.card_repr;
            std::string temp = card.card_symbol;
            std::string current_string = card_step != cards_to_show ? show[step].substr(0, CARD_VISIBILITY) : show[step];
            if (temp.size() == 1) card_step % 2 == 0 ? temp.insert(0, " ") : temp.append(" ");

            std::cout << fmt::format(current_string, temp);
            if (card_step == cards_to_show)  std::cout << std::endl;

            card_step++;
        }
    }
}