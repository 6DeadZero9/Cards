#define FMT_HEADER_ONLY

#include "../inc/Game.hpp"
#include "../inc/libfiglet.hpp"
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

void cls(void)
{
    #ifdef WINDOWS
    system("cls");
    #else
    system ("clear");
    #endif
}

void print_title_and_text(std::string text = "", bool show_title = true) {
    if (show_title) {
        const auto current_font = srilakshmikanthanp::libfiglet::figlet(
            srilakshmikanthanp::libfiglet::flf_font::make_shared("../fonts/Bloody.flf"), 
            srilakshmikanthanp::libfiglet::full_width::make_shared());
        cls();
        std::cout << std::endl << std::endl << current_font("Durak") <<  std::endl;
    }

    if (text.size()) std::cout << std::endl << std::endl << text << std::endl << std::endl;   
}

Game::Game(short unsigned int number_of_players) : players(), deck() {
    for (short unsigned int step = 0; step < number_of_players; step++) {
        std::string name;
        std::cout << fmt::format("Player {} name: ", step); std::cin >> name; std::string flush; getline(std::cin, flush);

        players.push_back(Player(fmt::format(name, step)));
    }
};

void Game::next_turn(void) {
    current_player_offset = current_player;
    defendant = current_player + 1 >= players.size() ? 0 : current_player + 1;
    current_round++;
    first_card_of_the_turn = false;
    defendant_turn = false;
    defendant_takes_cards = false;
    current_turn_players_end.clear();
    deck.table.clear();
    deck.fiil_players_deck(&players);;
}

unsigned int Game::determine_first_player(void) {
    Card *smallest_card = NULL;
    unsigned int first_player = 0;
    unsigned int counter = 0;
    for (auto &player : players ) {
        Card *current_card = player.check_samallest_main();
        if (current_card != NULL && (smallest_card == NULL || (current_card->is_main && !current_card->compare(*smallest_card)))) {
            smallest_card = current_card;
            first_player = counter;
        }
        counter++;
    }

    return first_player;
}

void Game::show_table(unsigned int current_player) {
    unsigned int counter {0};
    for (auto &player : players) {
        if (current_player != counter) {
            std::cout << players.at(counter).player_name << std::endl;
            player.show_cards(false, false);   
        }
        counter++;
    }
    deck.show_deck();
    std::cout << players.at(current_player).player_name << std::endl;
    players.at(current_player).show_cards(true, false);
    std::cout << std::endl << fmt::format("Current round: {}", current_round) << std::endl;
}

unsigned int Game::card_choice(unsigned int current_player) {
    std::string choice;
    unsigned int output = 0;

    while (true) {
        print_title_and_text();
        show_table(current_player);
        print_title_and_text("Choose the card you want to place:", false);

        players.at(current_player).show_cards(false, true);

        std::cout << "Your choice: "; std::cin >> choice;
        
        try {
            output = std::stoi(choice);
        }
        catch (std::invalid_argument) {
            continue;
        }

        if (!players.at(current_player).check_if_card_exists(output)) continue;
        return output; 
    }
}

bool Game::check_for_game_ending(void) {
    unsigned int player_that_lost;
    char temp;

    if (players_off_the_game.size() == players.size() - 1) {
        for (int step; step < players.size(); step++) {
            if (!std::binary_search(players_off_the_game.begin(), 
                                    players_off_the_game.end(), 
                                    step)) 
            {
                player_that_lost = step;
                break;
            }
        }

        print_title_and_text(
            fmt::format(
                "{} lost the game!!!", 
                players.at(player_that_lost).player_name)
        );
        std::cout << "Press any button to exit."; std::cin >> temp;
        return true;
    }
    return false;
}

void Game::menu(void) {
    while (true) {
        print_title_and_text("\t\t1. Play\n\t\t2. Exit");

        char choice;
        std::cout << "Your choice: "; std::cin >> choice;

        switch (choice) {
        case '1':
            play();
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
    unsigned int choosen_card;
    bool outer_loop = true;
    bool is_move_possible;
    bool is_game_ended;
    char choice;
    std::string current_text;
    Card temp = Card(0, 0);

    while (outer_loop) {
        print_title_and_text("\t\t1. 36 cards\n\t\t2. 52 cards");

        std::cout << "Your choice: "; std::cin >> choice;
        std::cin.sync();

        switch (choice) {
        case '1':
            deck.initialize(36, &players);
            outer_loop = false;
            break;
        case '2':
            deck.initialize(52, &players);
            outer_loop = false;
            break;
        default:
            break;
        }
    }

    current_player = determine_first_player();
    players_off_the_game.clear();
    current_round = 0;
    next_turn();

    while (true) {
        print_title_and_text();
        show_table(current_player_offset);
        if (!defendant_turn) {
            if ((current_player_offset == defendant) || std::binary_search(current_turn_players_end.begin(), 
                                                                           current_turn_players_end.end(), 
                                                                           current_player_offset)) {
                current_player_offset = current_player_offset + 1 >= players.size() ? 0 : current_player_offset + 1;
                continue;
            }
            else {
                current_text = "{}'s turn\n\n\t1. Place card\n\t2. End turn(if first card was placed)\n\t3. End game";
            }
        }
        else {
            current_text = "{}'s turn(defendant)\n\n\t1. Place card\n\t2. Take cards\n\t3. End game";
        }
        print_title_and_text(
            fmt::format(
                current_text, 
                players.at(current_player_offset).player_name), 
            false
        );

        std::cout << "Your choice: "; std::cin >> choice;
        switch (choice) {
        case '1':
            choosen_card = card_choice(current_player_offset);
            temp = players.at(current_player_offset).get_card(choosen_card, false);
            is_move_possible = (!defendant_turn) && (!first_card_of_the_turn || deck.table_symbols.count(temp.card_symbol));
            is_move_possible = is_move_possible || (defendant_turn && temp.compare(deck.table.back()));
            
            if (is_move_possible) {
                players.at(current_player_offset).remove_card(choosen_card);
                deck.table.push_back(temp);
                deck.table_symbols.insert(temp.card_symbol);
                first_card_of_the_turn = true;
                
                if (!deck.deck_size() && !players.at(current_player_offset).deck_size()) {
                    players_off_the_game.push_back(current_player_offset);
                    is_game_ended = check_for_game_ending();
                    return;
                } 
            }
            else {
                continue;
            }
            break;
        case '2':
            if (!defendant_turn) {
                if (first_card_of_the_turn) {
                    current_turn_players_end.push_back(current_player_offset);
                    if (current_turn_players_end.size() == players.size() - 1) {
                        if (!defendant_takes_cards) {
                            current_player = defendant;
                        }
                        else {
                            players.at(defendant).push_cards(deck.table);
                            current_player = defendant + 1 >= players.size() ? 0 : defendant + 1;
                        }
                        next_turn();
                        continue;
                    }
                }
                else {
                    continue;
                }
            }
            else {
                defendant_takes_cards = true;
            }
            break;
        case '3':
            exit(0);
            break;
        default:
            break;
        }
        defendant_turn = defendant_takes_cards ? false : !defendant_turn;
        current_player_offset = current_player_offset + 1 >= players.size() ? 0 : current_player_offset + 1;
    }
}