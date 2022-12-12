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

    private:
        std::vector<Player> players;
        Deck deck;
};

#endif