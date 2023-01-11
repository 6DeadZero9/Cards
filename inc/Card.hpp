#ifndef __CARD_H__
#define __CARD_H__

#include <string>
#include <vector>

class Card {
public:
    short int card_number;
    short int card_role;
    std::string small_card_repr;
    std::vector<std::string> card_repr;
    std::vector<std::string> card_back;
    std::string card_symbol;
    bool is_main = false;

    Card(short unsigned int card_number, short unsigned int card_role);
    bool compare(const Card& to_compare);
    void show_card(void);
};

#endif