#ifndef __CARD_H__
#define __CARD_H__

#include <string>
#include <vector>

using std::vector;
using std::string;

class Card {
public:
    short int card_number;
    short int card_role;
    vector<string> card_repr;
    vector<string> card_back;
    string card_symbol;
    bool is_main = false;

    Card(short unsigned int card_number, short unsigned int card_role);
    bool compare(const Card& to_compare);
    void show_card(void);
};

#endif