//
// Created by bjabo on 10/31/2022.
//
#include <unistd.h>
#include "Universe.h"

void Universe::initialize() {
    // initialize size
    cout << R"(please enter "n" which "n" is the 2d plane size (n*n) : )";
    cin >> size;
    game = new char*[size];
    for(int i = 0; i < size; i++)
        game[i] = new char [size];
    this->reset();

    // picking the number
    int num, place = 1;
    cout <<"please enter the number of places that you want to choose :  ";
    cin >> num;
    cout <<"\nplease pick the places\n";
    cout << '\n';

    // generate places to choose
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << place << "\t";
            place++;
        }
        cout << '\n' << '\n';
    }
    vector<int> places(num);

    // choosing elements
    cout << '\n';
    for(int i = 1; i <= num; i++){
        start:
        cout << "please enter the element number " << i << " : ";
        int temp;   cin >> temp;
        if(temp > size*size || temp < 0 || find(places.begin(), places.end(), temp) != places.end()){
            cout << "wrong value please try again\n\n";
            goto start;
        }
        places[i-1] = temp;
    }
    // fill chosen elements
    place = 1;
    sort(places.begin(), places.end());
    int it = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(place == places[it]){
                game[i][j] = '*';
                it++;
            }
            place++;
        }
    }
    this->display();
}


void Universe::reset() {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            game[i][j] = '-';
}

int Universe::count_neighbors(int i, int j) {
    int cnt = 0;
    int x = size, y = size;
    if((j+1) < x && game[i][j+1] == '*')
        cnt++;
    if((j-1)>=0 && game[i][j-1] == '*')
        cnt++;

    if((i+1)<x && game[i+1][j] == '*')
        cnt++;

    if((i-1)>=0 && game[i-1][j] == '*')
        cnt++;

    if((i-1)>=0 && (j-1)>=0 && game[i-1][j-1] == '*')
        cnt++;

    if((i-1)>=0 && (j+1)<y && game[i-1][j+1] == '*')
        cnt++;

    if((j+1)<y && (i+1)<x && game[i+1][j+1] == '*')
        cnt++;
    if((i+1)<x && (j-1)>=0 && game[i+1][j-1] == '*')
        cnt++;

    return cnt;
}

void Universe::display() {
    system("cls");
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << game[i][j] << '\t';
        cout <<"\n\n";
    }
}

void Universe::next_generation() {
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int num = this->count_neighbors(i,j);
            if(game[i][j] == '*'){
                if(num < 2 || num > 3)
                    game[i][j] = '-';
            }
            else if(num == 3) {
                game[i][j] = '*';
            }
        }
    }
}

void Universe::run() {
    this->initialize();
    for(int i =0; i < 3; i++){
        this->display();
        this->next_generation();
        sleep(1);
    }
}
