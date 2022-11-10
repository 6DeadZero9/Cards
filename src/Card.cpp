#define FMT_HEADER_ONLY

#include <iostream>
#include <fmt/format.h>
#include "../inc/Card.hpp"
#include "../inc/Common.hpp"

using namespace std;

Card::Card (short int card_number, short int card_role) {
    this->card_number = card_number;
    this->card_role = card_role;

    this->card_symbol = card_mapping[this->card_number];
    this->card_repr = cards[this->card_role];
}

void Card::show_card (void) {
    int count = 0;
    
    for (auto& step : this->card_repr) {
        string temp = this->card_symbol;

        if (this->card_symbol.length() == 1) {
            if (count % 2 == 0)
                temp.insert(0, " ");
            else
                temp.append(" ");
        }

        cout << fmt::format(step, temp) << endl; 

        count++;
    }
}