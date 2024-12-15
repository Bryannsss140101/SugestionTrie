//
// Created by Bryan on 12/15/2024.
//

#ifndef NODE_H
#define NODE_H

struct Node {
    Node **children;
    bool word_end;

    Node() : children(nullptr), word_end(false) {
        children = new Node *[27];
        for (int i = 0; i < 27; ++i)
            children[i] = nullptr;
    }
};

#endif //NODE_H