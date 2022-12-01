#include "../inc/Game.hpp"
#include "../inc/libfiglet.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace srilakshmikanthanp::libfiglet;
using namespace std;

void cls(void)
{
    #ifdef WINDOWS
    std::system("cls");
    #else
    std::system ("clear");
    #endif
}

void print_game_name(void) {
    const auto current_font = figlet(flf_font::make_shared("../fonts/Bloody.flf"), full_width::make_shared());
    cout << current_font("Durak") <<  endl;

}

void print_starting_menu_options(void) {
    
}

void Game::menu(void) {
    while (true) {
        cls();
        cout << endl << endl;  
        print_game_name();
        cout << endl << endl << "\t\t1. Play\n\t\t2. Exit" << endl << endl;   

        char choice;
        cout << "Your choice: "; cin >> choice;
        cin.sync();

        switch (choice) {
        case '1':
            this->play();
            break;
        case '2':
            exit(0);
            break;
        
        default:
            break;
        }
    }
}

void Game::play(void) {
    bool outer_loop = true;
    while (outer_loop) {
        cls();
        cout << endl << endl;  
        print_game_name();
        cout << endl << endl << "\t\t1. 36 cards\n\t\t2. 52 cards" << endl << endl;  

        char choice;
        cout << "Your choice: "; cin >> choice;

        switch (choice) {
        case '1':
            this->deck.initialize(36, &(this->player_1), &(this->player_2));
            outer_loop = false;
            break;
        case '2':
            this->deck.initialize(52, &(this->player_1), &(this->player_2));
            outer_loop = false;
            break;
        default:
            break;
        }
    }
}