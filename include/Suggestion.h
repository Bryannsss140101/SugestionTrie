//
// Created by Bryan on 12/15/2024.
//
#ifndef SUGGESTION_H
#define SUGGESTION_H

#include <fstream>
#include <string>
#include <Trie.h>

class Suggestion {
public:
    explicit Suggestion(const std::string &file_name);

    ~Suggestion();

private:
    std::string path;
    std::ifstream file;
    Trie trie;

    bool read_file();

    void search();
};

#endif //SUGGESTION_H
