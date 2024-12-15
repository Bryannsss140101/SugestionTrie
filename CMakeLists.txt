cmake_minimum_required(VERSION 3.29)
project(SuggestionSystem)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(SuggestionSystem main.cpp
        src/Trie.cpp
        src/Suggestion.cpp)
