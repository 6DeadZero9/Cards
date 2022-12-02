#ifndef __GAME_H__
#define __GAME_H__

#include "../inc/Deck.hpp"
#include "../inc/Player.hpp"
#include "vector"

using std::vector;

class Game {
    public:
        Game(short unsigned int number_of_players);
        void menu(void);
        void start_game(void);
        void play(void);

    private:
        vector<Player> players;
        Deck deck;
};

#endif