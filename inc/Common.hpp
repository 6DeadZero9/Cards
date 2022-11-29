#ifndef __COMMON__
#define __COMMON__

#include <map>
#include <string>
#include <vector>

using std::map;
using std::vector;
using std::string;

#define NUMBER_OF_ROLES 4


class Common {
    public:
        map<short int, string> card_mapping = {
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

        map<short int, vector<string>> cards = {
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
        };

        template <typename T>
        vector<T> slicing(vector<T> const& v, int X, int Y) {
            auto first = v.begin() + X;
            auto last = v.begin() + Y + 1;

            vector<T> vector(first, last);

            return vector;
        }
};

#endif