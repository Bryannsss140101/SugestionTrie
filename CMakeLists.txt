cmake_minimum_required(VERSION 3.29)
project(SuggestionTrie)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(SuggestionTrie main.cpp
        src/Trie.cpp
        src/Suggestion.cpp)
