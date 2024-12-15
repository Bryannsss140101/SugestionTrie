//
// Created by Bryan on 12/15/2024.
//

#include <iostream>
#include <conio.h>
#include "../include/Suggestion.h"

Suggestion::Suggestion(const std::string &file_name)
    : path("../data/" + file_name), file(path) {
    if (!read_file())
        throw std::runtime_error("File not found");

    search();
}

Suggestion::~Suggestion() {
    if (file.is_open())
        file.close();
}

bool Suggestion::read_file() {
    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line))
        if (line != "")
            trie.insert(line);

    file.close();
    return true;
}

void Suggestion::search() {
    while (true) {
        std::string prefix;
        std::cout << "Enter your word: ", std::cin >> prefix;

        const auto suggestions = trie.suggest(prefix);

        if (suggestions.empty())
            printf("No results were found for your search (%s)\n", prefix.c_str());
        else
            for (const auto &e: suggestions)
                printf("|--------------> %s\n|\n", e.c_str());

        _getch();
        system("cls");
    }
}
