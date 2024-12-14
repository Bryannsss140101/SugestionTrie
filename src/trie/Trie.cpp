//
// Created by Bryannsss.
//

#include "Trie.h"
#include <algorithm>
#include <cctype>

Trie::Trie(): root(nullptr) {
}

void Trie::insert(const std::string &prefix) {
    const bool is_alpha = std::ranges::all_of(prefix, [](const char c) {
        return std::isalpha(c);
    });

    if (!is_alpha) return;

    std::string copy = prefix;
    std::ranges::transform(copy, copy.begin(),
                           [](const char c) { return std::tolower(c); });
    root = insert(copy, root);
}

bool Trie::search(const std::string &prefix) {
    std::string copy = prefix;
    std::ranges::transform(copy, copy.begin(),
                           [](const char c) { return std::tolower(c); });
    return search(copy, root);
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
