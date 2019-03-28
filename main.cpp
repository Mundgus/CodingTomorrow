#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <set>
#include "Object.hpp"
#include "Car.hpp"
#include "Pedestrian.hpp"
#include "Passenger.hpp"



using namespace std;

vector<vector<char>> loadTerkep();

//void out(string S){
//    system(("echo " + S + "| nc 31.46.64.35 12323").c_str());
//}

/*  S: Út
 *  Z: Zebra
 *  P: Járda
 *  G: Fű
 *  B: Épület
 *  T: Fa
 * */

const vector<vector<char>> terkep = loadTerkep();
const string teamToken = "zmW5ZTg6acpMSxyMIq0L34NotwKoiTCRpqiLyLvbM5UFsYet07s9KIdNAjmdiSgzMPf3qZ";

struct request_id{
    unsigned game_id;
    unsigned tick;
    unsigned car_id;
};

istream& operator >> (istream& in, request_id& R){
    string S;
    while(in >> S && S.find('}') == -1){
        stringstream SS;
        if(S.find("game_id") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> R.game_id;
        }
        if(S.find("tick") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> R.tick;
        }
        if(S.find("car_id") != -1){
            SS << S;
            getline(SS, S,':');
            SS >> R.car_id;
        }
    }
    return in;
}

void loadTick(request_id& req, vector<Car>& cars, vector<Pedestrian> ped, vector<Passenger>& pass) {
    system("echo {\"token\":\"zmW5ZTg6acpMSxyMIq0L34NotwKoiTCRpqiLyLvbM5UFsYet07s9KIdNAjmdiSgzMPf3qZ\"} | nc 31.46.64.35 12323 > Tick.txt");
    //out("alma\n\nalma");
    ifstream file("Tick.txt");
    string S;
    while(file >> S){
        cout << S << endl;
        /*if(S.find("request_id") != -1)
            in >> req;
        if(S.find("cars") != -1){
            Car C;
            //in >> C;
            cars.push_back(C);
        }*/
    }
    file.close();
}

///Csak annyit csinál, hogy a legrövidebb útvonalat(nem a legyorsabbat!!!) megkeresi a két pont között (nem megy át a füvön)
vector<position> pathfinder();


int main(){
    vector<Car> cars;
    vector<Pedestrian> ped;
    vector<Passenger> pass;
    request_id req;

    loadTick(req, cars, ped, pass);

    return 0;
}


vector<vector<char>> loadTerkep(){
    vector<vector<char>> terkep;
    ifstream file("../LoadingFiles/terkep.txt");
    string S;
    while(getline(file,S)){
        vector<char> row;
        for(char c : S){
            row.push_back(c);
        }
        terkep.push_back(row);
    }

    file.close();
    return terkep;
}

    struct pathPiece{
        position actual;
        position last;
        unsigned double distance;
        pathPiece(position ACTUAL, position FINISH){
            actual = ACTUAL;
            distance = sqrt(pow(ACTUAL.x-FINISH.x,2) + pow(ACTUAL.y-FINISH.y,2));
        }
        bool operator < (const pathPiece& P)const{
            if(this->distance != P.distance)
                return this->distance < P.distance;
            if(this->actual.x != P.actual.x)
                return this->actual.x < P.actual.x;
            return this->actual.y < P.actual.y;
        }
    };

vector<position> pathfinder(vector<vector<char>> terkep, position START, position FINISH){
   /* set<pathPiece> path;
    pathPiece P(START, FINISH);
    path.insert(P);
    while(path.begin()->distance != 0){
        int x = path.begin()->actual.x;
        int y = path.begin()->actual.y;
        if(x != 60){
            if(y != 60)
                position p1(x+1,y+1);
            if(y != 0)
                position p2(x+1,y-1);
        }
        if(x != 0) {
            if (y != 60)
                position p3(x - 1, y + 1);
            position p4(x - 1, y - 1);
        }
        pathPiece P1(p1,FINISH);
        pathPiece P2(p2,FINISH);
        pathPiece P3(p3,FINISH);
        pathPiece P4(p4,FINISH);
    }*/
}
