//
// Created by Bryannsss.
//

#include <algorithm>
#include <vector>
#include "../include/Trie.h"

Trie::Trie(): root(nullptr) {
}

void Trie::insert(const std::string &word) {
    if (!is_alpha(word)) return;
    root = insert(word, root);
}

bool Trie::search(const std::string &word) {
    if (!is_alpha(word)) return false;
    return search(word, root);
}

bool Trie::search_with(const std::string &prefix) {
    if (!is_alpha(prefix)) return false;
    return find(prefix, root);
}

std::vector<std::string> Trie::suggest(const std::string &prefix) {
    std::vector<std::string> suggestions;

    const auto node = find(prefix, root);
    DFS(prefix, node, suggestions);
    return suggestions;
}

bool Trie::is_alpha(const std::string &word) const {
    return std::ranges::all_of(word, [](const char c) {
        return std::isalpha(c) || c == ' ';
    });
}

int Trie::to_index(const char c) const {
    if (c == ' ') return 26;
    return c - 'a';
}

Node *Trie::insert(const std::string &word, Node *node) {
    const auto index = to_index(std::tolower(word[0]));

    if (node == nullptr)
        node = new Node();

    if (word.empty()) {
        node->word_end = true;
        return node;
    }

    node->children[index] = insert(word.substr(1), node->children[index]);
    return node;
}

bool Trie::search(const std::string &word, Node *node) {
    const auto index = to_index(std::tolower(word[0]));

    if (node == nullptr)
        return false;

    if (word.empty())
        return node->word_end;

    return search(word.substr(1), node->children[index]);
}

Node *Trie::find(const std::string &word, Node *node) {
    if (node == nullptr || word.empty())
        return node;

    const auto index = to_index(std::tolower(word[0]));
    return find(word.substr(1), node->children[index]);
}

void Trie::DFS(const std::string &prefix, Node *node, std::vector<std::string> &words) {
    if (node == nullptr)
        return;

    if (node->word_end)
        words.push_back(prefix);

    for (int i = 0; i < 27; ++i)
        if (node->children[i] != nullptr) {
            const char c = i == 26 ? ' ' : 'a' + i;
            DFS(prefix + c, node->children[i], words);
        }
}
