#define FMT_HEADER_ONLY

#include "../inc/Deck.hpp"
#include "../inc/Common.hpp"
#include <fmt/format.h>
#include <algorithm>
#include <iostream>
#include <random>

Common common = Common();

void Deck::initialize(unsigned char number_of_cards, std::vector<Player> *players) {
    unsigned role_number_of_cards = number_of_cards / NUMBER_OF_ROLES;
    unsigned cards_for_one_player = number_of_cards / players->size();
    cards_for_one_player = cards_for_one_player < FIRST_HAND ? cards_for_one_player : FIRST_HAND;
   
    this->original_deck.clear();
    for (auto &player : *players) {
        player.clear_cards();
    }

    for (short unsigned int role = 0; role < NUMBER_OF_ROLES; role++) {
        for (short unsigned int card = MAX_NUMBER_ONE_ROLE - role_number_of_cards + 1; card <= MAX_NUMBER_ONE_ROLE; card++) {
            this->original_deck.push_back(Card(card, role));
        }
    }

    shuffle(begin(this->original_deck), end(this->original_deck), std::random_device());

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
            std::vector<std::string> show = card_step ? card.card_back : card.card_repr;
            std::string temp = card.card_symbol;
            std::string current_string = card_step != cards_to_show ? show[step].substr(0, CARD_VISIBILITY) : show[step];
            if (temp.size() == 1) step % 2 == 0 ? temp.insert(0, " ") : temp.append(" ");

            std::cout << fmt::format(current_string, temp);

            card_step++;
        }
        card_step = 0;
        if (table.size()) {
            for (auto &card : table) {
                std::string temp = card.card_symbol;
                std::string current_string = card_step % 2 == 0 ? card.card_repr[step].substr(0, CARD_VISIBILITY) : card.card_repr[step];
                if (card_step == table.size() - 1) current_string = card.card_repr[step];
                if (card_step % 2 == 0) std::cout << "\t";
                if (temp.size() == 1) card_step % 2 == 0 ? temp.insert(0, " ") : temp.append(" ");
                std::cout << fmt::format(current_string, temp);

                card_step++;
            }
        }
        std::cout << std::endl;
    }
}
