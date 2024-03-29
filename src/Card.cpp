#define FMT_HEADER_ONLYstring

#include <iostream>
#include <fmt/format.h>
#include "../inc/Card.hpp"
#include "../inc/Common.hpp"
#include "../inc/CardException.hpp"

using namespace std;

Card::Card (short unsigned int card_number, short unsigned int card_role) {
    Common common = Common();
    this->card_number = card_number;
    this->card_role = card_role;

    this->card_symbol = common.card_mapping[this->card_number];
    this->small_card_repr = common.small_card_repr[this->card_role];
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
        std::cout << "Can't compare two identical cards, exiting..." << std::endl;
        exit(1);
    }
}

void Card::show_card (void) {
    int count = 0;
    
    for (auto& step : this->card_repr) {
        std::string temp = this->card_symbol;
        if (temp.size() == 1) count % 2 == 0 ? temp.insert(0, " ") : temp.append(" ");

        std::cout << fmt::format(step, temp) << std::endl; 

        count++;
    }
}