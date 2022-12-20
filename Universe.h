#ifndef GAME_OF_LIFE_UNIVERSE_H
#define GAME_OF_LIFE_UNIVERSE_H

#include <bits/stdc++.h>
using namespace std;


class Universe {
private:
    int size;
    char** game;
public:
    void initialize();
    void reset();
    int count_neighbors(int i, int j);
    void display();
    void next_generation();
    void run();
};


#endif //GAME_OF_LIFE_UNIVERSE_H
