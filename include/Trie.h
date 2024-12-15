//
// Created by Bryannsss.
//

#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include "Node.h"

class Trie {
public:
    Trie();

    void insert(const std::string &word);

    bool search(const std::string &word);

    bool search_with(const std::string &prefix);

    std::vector<std::string> suggest(const std::string &prefix);

private:
    Node *root;

    bool is_alpha(const std::string &word) const;

    int to_index(char c) const;

    Node *insert(const std::string &word, Node *node);

    bool search(const std::string &word, Node *node);

    Node *find(const std::string &word, Node *node);

    void DFS(const std::string &prefix, Node *node, std::vector<std::string> &words);
};

#endif //TRIE_H
