#include "../inc/Card.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    Card card = Card(11, 0, false);
    Card card_2 = Card(10, 0, false);

    cout << card.compare(card_2) << endl;

    return 0;
}