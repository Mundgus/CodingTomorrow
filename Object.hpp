//
// Created by norbert on 2019.03.28..
//

#ifndef CODINGTOMORROW_HPP
#define CODINGTOMORROW_HPP

#include <iostream>
#include <sstream>
using namespace std;

struct position{
    unsigned x;
    unsigned y;
    position(unsigned X, unsigned Y): x(X),y(Y){}
    position(){}
};

/*
istream& operator >>(istream& in, position& pos){
    string S;
    while(in >> S && S.find('}') == -1){
        stringstream SS;
        if(S.find("x") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> pos.x;
        }
        if(S.find("y") != -1) {
            SS << S;
            getline(SS, S, ':');
            SS >> pos.y;
        }
    }
    return in;
}
*/

enum direction{LEFT, RIGHT, UP, DOWN};


class Object {
public:
    unsigned id;
    position pos;
};


#endif //CODINGTOMORROW_OBJECT_HPP
