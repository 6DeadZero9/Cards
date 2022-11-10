#ifndef __COMMON__
#define __COMMON__
#include <map>
#include <string>
#include <vector>

using std::map;
using std::vector;
using std::string;

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
            "|     /   \\     |",
            "|    /_/-\\_\\    |",
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
        3, {
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
};

#endif