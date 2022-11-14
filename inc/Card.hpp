#include <string>
#include <vector>

using std::vector;
using std::string;

class Card {
public:
    short int card_number;
    short int card_role;
    bool is_main;

    Card(short int card_number, short int card_role, bool is_main);
    bool compare(const Card& to_compare);
    void show_card(void);
private:
    vector<string> card_repr;
    string card_symbol;
};