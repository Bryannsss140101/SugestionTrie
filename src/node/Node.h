//
// Created by Bryannsss.
//

#ifndef NODE_H
#define NODE_H

struct Node {
private:
    int size;

public:
    Node **children;
    bool word_end;

    Node() : size(26), children(nullptr), word_end(false) {
        children = new Node *[size];
        for (int i = 0; i < size; ++i)
            children[i] = nullptr;
    }
};

#endif //NODE_H
