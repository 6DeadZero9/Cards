#ifndef __GAME_H__
#define __GAME_H__

#include "../inc/Deck.hpp"
#include "../inc/Player.hpp"

class Game {
    public:
        Game(void) : player_1(), player_2(), deck() {};
        void menu(void);
        void start_game(void);
        void play(void);

    private:
        Player player_1, player_2;
        Deck deck;
};

#endif