//
// Created by Bryannsss.
//

#include "Trie.h"
#include <algorithm>

Trie::Trie(): root(nullptr) {
}

void Trie::insert(const std::string &prefix) {
    if (!is_alpha) return;

    std::string copy = prefix;
    std::ranges::transform(copy, copy.begin(),
                           [](const char c) { return std::tolower(c); });
    root = insert(copy, root);
}

bool Trie::search(const std::string &prefix) {
    if (!is_alpha) return false;

    std::string copy = prefix;
    std::ranges::transform(copy, copy.begin(),
                           [](const char c) { return std::tolower(c); });
    return search(copy, root);
}

bool Trie::is_alpha(const std::string &word) const {
    return std::ranges::all_of(word, [](const char c) {
        return std::isalpha(c);
    });
}

Node *Trie::insert(const std::string &prefix, Node *node) {
    const auto c = prefix[0] - 'a';

    if (node == nullptr)
        node = new Node();

    if (prefix.empty()) {
        node->word_end = true;
        return node;
    }

    node->children[c] = insert(prefix.substr(1), node->children[c]);

    return node;
}

Node *Trie::search(const std::string &prefix, Node *node) {
    if (node == nullptr || prefix.empty())
        return node;

    const auto c = prefix[0] - 'a';
    return search(prefix.substr(1), node->children[c]);
}
