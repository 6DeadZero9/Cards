#define FMT_HEADER_ONLY

#include "../inc/Player.hpp"
#include <fmt/format.h>
#include <iostream>

using namespace std;

void Player::push_card(Card card) {
    this->player_cards.push_back(card);
}

void Player::show_cards(void) {
    if (this->player_cards.empty()) {
        return;
    }
    for (int step = 0; step < this->player_cards.back().card_repr.size(); step++) {
        int card_step = 0;
        for (auto &card : this->player_cards) {
            string temp = card.show_symbol();
            string current_string = card_step != this->player_cards.size() - 1 ? card.card_repr[step].substr(0, 8) : card.card_repr[step];
            if (temp.size() == 1) card_step % 2 == 0 ? temp.insert(0, " ") : temp.append(" ");
            

            if (card_step != this->player_cards.size() - 1) {
                cout << fmt::format(current_string, temp);
            }
            else {
                cout << fmt::format(current_string, temp) << endl;
            }
            card_step++;
        }
    }
}