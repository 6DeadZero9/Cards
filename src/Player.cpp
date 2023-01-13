#define FMT_HEADER_ONLY

#include "../inc/Player.hpp"
#include "../inc/Common.hpp"
#include <fmt/format.h>
#include <iostream>

void Player::push_card(Card card) {
    player_cards.push_back(card);
}

Card Player::get_card(unsigned int index, bool remove) {
    Card temp = player_cards.at(index);
    if (remove) remove_card(index);

    return temp;
}

void Player::remove_card(unsigned int index) {
    player_cards.erase(player_cards.begin() + index);
}

void Player::show_cards(bool front, bool show_list = false) {
    if (player_cards.empty()) return;

    if (!show_list) {
        for (int step = 0; step < player_cards.back().card_repr.size(); step++) {
            int card_step = 0;
            for (auto &card : player_cards) {
                std::vector<std::string> show = front ? card.card_repr : card.card_back;
                std::string temp = card.card_symbol;
                std::string current_string = card_step != player_cards.size() - 1 ? show[step].substr(0, CARD_VISIBILITY) : show[step];
                if (temp.size() == 1) step % 2 == 0 ? temp.insert(0, " ") : temp.append(" ");
                
                std::cout << fmt::format(current_string, temp);
                
                card_step++;
            }
            std::cout << std::endl;
        }
    }

    if (show_list) {
        unsigned int counter = 0;
        for (auto &card : player_cards) {
            std::cout << fmt::format("{}. {} {}", counter, card.card_symbol, card.small_card_repr) << std::endl;
            counter++;
        }
    }
}

Card* Player::check_samallest_main(void) {
    Card* smallest = NULL;
    for (auto &card : player_cards) {
        if (card.is_main) {
            smallest = &card;
        }
    }
    return smallest;
}

bool Player::check_if_card_exists(unsigned int index) {
    try {
        player_cards.at(index);
        return true;
    }
    catch (const std::out_of_range& oor) {
        return false;
    }
}