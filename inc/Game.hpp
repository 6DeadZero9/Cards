#ifndef __GAME_H__
#define __GAME_H__

#include "../inc/Deck.hpp"
#include "../inc/Player.hpp"
#include "vector"

class Game {
    public:
        Game(short unsigned int number_of_players);
        void menu(void);
        unsigned int determine_first_player(void);
        void start_game(void);
        void play(void);
        void show_table(unsigned int current_player);
        unsigned int card_choice(unsigned int current_player);
        void next_turn(void);

    private:
        unsigned int current_player;
        unsigned int current_player_offset;
        unsigned int current_round;
        unsigned int defendant;
        bool first_card_of_the_turn;
        bool defendant_turn;
        bool defendant_takes_cards;
        bool first_rebound_done;
        std::vector<unsigned int> current_turn_players_end;
        std::vector<Player> players;
        Deck deck;
};

#endif