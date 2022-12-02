#define FMT_HEADER_ONLY

#include "../inc/Player.hpp"
#include <fmt/format.h>
#include <iostream>

using namespace std;

void Player::push_card(Card card) {
    this->player_cards.push_back(card);
}

void Player::show_cards(bool front) {
    if (this->player_cards.empty()) {
        return;
    }
    for (int step = 0; step < this->player_cards.back().card_repr.size(); step++) {
        int card_step = 0;
        for (auto &card : this->player_cards) {
            vector<string> show = front ? card.card_repr : card.card_back;
            string temp = card.card_symbol;
            string current_string = card_step != this->player_cards.size() - 1 ? show[step].substr(0, 8) : show[step];
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

Card* Player::check_samallest_main(void) {
    Card* smallest = NULL;
    for (auto &card : this->player_cards) {
        if (card.is_main) {
            smallest = &card;
        }
    }
    return smallest;
}