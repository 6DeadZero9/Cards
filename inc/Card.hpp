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
    bool is_main;

    Card(short unsigned int card_number, short unsigned int card_role, bool is_main);
    bool compare(const Card& to_compare);
    void show_card(void);
    string show_symbol(void) { return this->card_symbol; };
private:
    string card_symbol;
};

#endif