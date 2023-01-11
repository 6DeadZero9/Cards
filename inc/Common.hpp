#ifndef __COMMON__
#define __COMMON__

#include <map>
#include <string>
#include <vector>

#define MAX_NUMBER_ONE_ROLE 14
#define NUMBER_OF_PLAYERS 2
#define CARD_VISIBILITY 8
#define NUMBER_OF_ROLES 4
#define FIRST_HAND 6
#define SHOW_DECK 2

class Common {
    public:
        std::map<short int, std::string> card_mapping = {
            { 2, "2" },
            { 3, "3" },
            { 4, "4" },
            { 5, "5" },
            { 6, "6" },
            { 7, "7" },
            { 8, "8" },
            { 9, "9" },
            { 10, "10" },
            { 11, "J" },
            { 12, "Q" },
            { 13, "K" },
            { 14, "A" },
        };

        std::map<short int, std::string> small_card_repr = {
            { 0, "\u2660" },
            { 1, "\u2666" },
            { 2, "\u2663" },
            { 3, "\u2665" },
        };

        std::map<short int, std::vector<std::string>> cards = {
            {
                0, {
                    "/---------------\\",
                    "| {}            |",
                    "|               |",
                    "|       ^       |",
                    "|      / \\      |",
                    "|     / ^ \\     |",
                    "|    /_/ \\_\\    |",
                    "|       ^       |",
                    "|      /_\\      |",
                    "|               |",
                    "|            {} |",
                    "\\---------------/"
                } 
            },
            {
                1, {
                    "/---------------\\",
                    "| {}            |",
                    "|               |",
                    "|       ^       |",
                    "|      / \\      |",
                    "|     /   \\     |",
                    "|     \\   /     |",
                    "|      \\ /      |",
                    "|       v       |",
                    "|               |",
                    "|            {} |",
                    "\\---------------/"
                } 
            },     
            {
                2, {
                    "/---------------\\",
                    "| {}            |",
                    "|       _       |",
                    "|      / \\      |",
                    "|     _\\_/_     |",
                    "|    / \\ / \\    |",
                    "|    \\_/ \\_/    |",
                    "|       ^       |",
                    "|      /_\\      |",
                    "|               |",
                    "|            {} |",
                    "\\---------------/"
                } 
            },
            {
                3, {
                    "/---------------\\",
                    "| {}            |",
                    "|               |",
                    "|   /--\\ /--\\   |",
                    "|   \\   v   /   |",
                    "|    \\     /    |",
                    "|     \\   /     |",
                    "|      \\ /      |",
                    "|       v       |",
                    "|               |",
                    "|            {} |",
                    "\\---------------/"
                } 
            },
            {
                4, {
                    "/---------------\\",
                    "| -----   ----- |",
                    "||     \\ /     ||",
                    "||      v      ||",
                    "||     / \\     ||",
                    "|\\  \\ /   \\ /  /|",
                    "|/  / \\   / \\  \\|",
                    "||     \\ /     ||",
                    "||      ^      ||",
                    "||     / \\     ||",
                    "| -----   ----- |",
                    "\\---------------/"
                } 
            },
        };

        template <typename T>
        std::vector<T> slicing(std::vector<T> const& v, int X, int Y) {
            auto first = v.begin() + X;
            auto last = v.begin() + Y + 1;

            std::vector<T> vector(first, last);

            return vector;
        }
};

#endif