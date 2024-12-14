cmake_minimum_required(VERSION 3.29)
project(TrieTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(TrieTree main.cpp
        src/node/Node.h
        src/trie/Trie.cpp
        src/trie/Trie.h)
