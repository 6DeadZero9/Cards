#include "../inc/Game.hpp"

void print_game_name(void) {
    system("clear");
    system("figlet Durak | lolcat");
}

Game::Game(void) {

}

void Game::menu(void) {
    print_game_name();
}