#include <string>
#include <vector>

using std::vector;
using std::string;

class Card {
public:
    short int card_number;
    short int card_role;

    Card(short int card_number, short int card_role);
    void show_card(void);
private:
    vector<string> card_repr;
    string card_symbol;
};