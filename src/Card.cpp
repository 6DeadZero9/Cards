#define FMT_HEADER_ONLY

#include <iostream>
#include <fmt/format.h>
#include "../inc/Card.hpp"
#include "../inc/Common.hpp"
#include "../inc/CardException.hpp"

using namespace std;
Common common = Common();

Card::Card (short unsigned int card_number, short unsigned int card_role) {
    this->card_number = card_number;
    this->card_role = card_role;

    this->card_symbol = common.card_mapping[this->card_number];
    this->card_repr = common.cards[this->card_role];
    this->card_back = common.cards[4];
}

bool Card::compare(const Card& to_compare) {
    try {
        if ((this->card_number == to_compare.card_number) && (this->card_role == to_compare.card_role))
            throw CardException();      

        if ((this->is_main && to_compare.is_main) || ((!this->is_main && !to_compare.is_main) && (this->card_role == to_compare.card_role))) 
            return this->card_number > to_compare.card_number;
        else if (this->is_main && !to_compare.is_main) 
            return true;
        else
            return false;
    }
    catch (CardException &) {
        cout << "Can't compare two identical cards, exiting..." << endl;
        exit(1);
    }
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