//
// Created by norbert on 2019.03.28..
//

#ifndef CODINGTOMORROW_CAR_HPP
#define CODINGTOMORROW_CAR_HPP

#include "Object.hpp"


class Car : public Object{
public:
    int life;
    unsigned transported;
    unsigned passengerID;
    unsigned speed;
    Car();
};

/*istream& operator >> (istream& in, Car& C){
    string S;
    while(in >> S && S.find('}') == -1){
        stringstream SS;
        if(S.find("life") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.life;
        }
        if(S.find("transported") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.transported;
        }
        if(S.find("speed") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.speed;
        }
        *//*if(S.find("direction") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.direction;
        }
        if(S.find("command") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.command;
        }*//*
        if(S.find("id") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.id;
        }
        if(S.find("pos") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> C.pos;
        }
    }
    return in;
}*/
#endif //CODINGTOMORROW_CAR_HPP
