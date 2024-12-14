#include <iostream>
#include <conio.h>
#include "src/trie/Trie.h"

using namespace std;

int main() {
    Trie trie;

    trie.insert("hol");
    trie.insert("hold");
    trie.insert("hola");
    trie.insert("1");

    cout << trie.search("h") << endl;
    cout << trie.search("ho") << endl;
    cout << trie.search("hol") << endl;
    cout << trie.search("hold") << endl;
    cout << trie.search("hola") << endl;
    cout << trie.search("hola") << endl;
    cout << trie.search("z") << endl;
    cout << trie.search("1") << endl;

    _getch();
    return 0;
}
