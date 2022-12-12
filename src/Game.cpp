#define FMT_HEADER_ONLY

#include "../inc/Game.hpp"
#include "../inc/libfiglet.hpp"
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <cstdlib>


void cls(void)
{
    #ifdef WINDOWS
    system("cls");
    #else
    system ("clear");
    #endif
}

void print_game_name(std::string text = "") {
    const auto current_font = srilakshmikanthanp::libfiglet::figlet(
        srilakshmikanthanp::libfiglet::flf_font::make_shared("../fonts/Bloody.flf"), 
        srilakshmikanthanp::libfiglet::full_width::make_shared());
    cls();
    std::cout << std::endl << std::endl << current_font("Durak") <<  std::endl;

    if (text.size()) std::cout << std::endl << std::endl << text << std::endl << std::endl;   
}

Game::Game(short unsigned int number_of_players) : players(), deck() {
    for (short unsigned int step = 0; step < number_of_players; step++) {
        std::string name = "Player {}";
        this->players.push_back(Player(fmt::format(name, step)));
    }
};

unsigned int Game::determine_first_player(void) {
    Card *smallest_card = NULL;
    unsigned int first_player = 0;
    unsigned int counter = 0;
    for (auto &player : this->players ) {
        Card *current_card = player.check_samallest_main();
        if (current_card != NULL && (smallest_card == NULL || (current_card->is_main && !current_card->compare(*smallest_card)))) {
            smallest_card = current_card;
            first_player = counter;
        }
        counter++;
    }

    return first_player;
}

void Game::menu(void) {
    while (true) {
        print_game_name("\t\t1. Play\n\t\t2. Exit");

        int choice;
        std::cout << "Your choice: "; std::cin >> choice; std::string flush; getline(std::cin, flush);

        switch (choice) {
        case 1:
            this->play();
            break;
        case 2:
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
        print_game_name("\t\t1. 36 cards\n\t\t2. 52 cards");

        int choice;
        std::cout << "Your choice: "; std::cin >> choice; std::string flush; getline(std::cin, flush);

        switch (choice) {
        case 1:
            this->deck.initialize(36, &this->players);
            outer_loop = false;
            break;
        case 2:
            this->deck.initialize(52, &this->players);
            outer_loop = false;
            break;
        default:
            break;
        }
    }

    while (true) {
        print_game_name("");
        this->players[0].show_cards(true);
        this->players[1].show_cards(true);
        this->deck.show_deck();
        int test = this->determine_first_player();
        std::cout << test << std::endl;
        char temp; std::cin >> temp; std::string flush; getline(std::cin, flush);
    }
}