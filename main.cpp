#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Object.hpp"
#include "Car.hpp"
#include "Pedestrian.hpp"
#include "Passenger.hpp"
//#include <cstdlib>



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

