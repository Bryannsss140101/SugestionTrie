//
// Created by Bryannsss.
//

#ifndef TRIE_H
#define TRIE_H
#include <string>
#include "../node/Node.h"

class Trie {
public:
    Trie();

    void insert(const std::string &prefix);

    bool search(const std::string &prefix);

private:
    Node *root;

    bool is_alpha(const std::string &word) const;

    Node *insert(const std::string &prefix, Node *node);

    Node *search(const std::string &prefix, Node *node);
};

#endif //TRIE_H
