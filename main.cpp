#include "CellTower.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
// Structure to hold a pair of towers and their distance and aid in finding max distance
struct pairs{
    CellTower t1;
    CellTower t2;
    double disct;
};

//find max distance tower and assign frequency
// Structure to hold a tower with its max distance and assigned frequency
struct Tower{
    CellTower t;
    double dist;
    int frequency;


};

//function to calculate distance between two towers
double distance( CellTower& t1,  CellTower& t2);

int main(){

    vector<CellTower> towers;
    string filename = "data.csv";
    ifstream file(filename);
    vector<pairs> myPairs;
    Tower myTower;
    vector<Tower> maxTowers;
    

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }
    string header;
    getline(file, header);

    CellTower tower;
    while (file >> tower) {
        towers.push_back(tower);
    }

    file.close();
    // Calculate distances between all pairs of towers through cartesian product
    //to find all combinations
    // and find the maximum distance for each tower
        std::cout << "Distances between All possible cell towers combination:" << endl;
        for (int n = 0; n < towers.size(); n++) {
                double maxDist = 0.0;
                pairs maxPair;
                maxPair.t1 = towers[n];
                for (int m = 0; m < towers.size(); m++) {
                        if (n == m) continue;
                        double d = distance(towers[n], towers[m]);
                        std::cout << "Towers " << towers[n].getID() << " and " << towers[m].getID() << " distance " << d << '\n';
                        if (d > maxDist) {
                                maxDist = d;
                                maxPair.t2 = towers[m];
                                maxPair.disct = d;
                        }
                }
                myPairs.push_back(maxPair);
        }

    std::cout << endl;
    //sorting the pairs based on distance
    sort(myPairs.begin(), myPairs.end(), [](const pairs& a, const pairs& b) {
       return a.disct > b.disct; // Sort by disct, descending
    });

    int freq = 110;
    std::cout << "Longest distance between cell towers in sorted order: " << endl;
    for(int i = 0;  i < myPairs.size(); i++) {
        if(freq > 115){
            freq = 110;
        }
        
        std::cout << "Furthest Tower of " << myPairs[i].t1.getID() << " is " << myPairs[i].t2.getID() 
             << ". Its distance is " << myPairs[i].disct << '\n';
        myTower.t = myPairs[i].t1;
        myTower.dist = myPairs[i].disct;
        myTower.frequency = freq;
        maxTowers.push_back(myTower);
         // Only increment freq if not the first element and the distance is different
    if(i > 0 && myPairs[i].disct != myPairs[i-1].disct && myPairs[i].disct != 0) {
        freq += 1;
    }
        
    }

    //sorting the pairs based on distance
    sort(maxTowers.begin(), maxTowers.end(), []( Tower& a,  Tower& b) {
       return a.t.getID() < b.t.getID(); // Sort by disct, descending
    });

    cout << "\n\nTowers with assigned frequencies based on distance:\n\n";
    /*string MaxDistance, idstr, eaststr, northstr,latstr,longstr, Frequency;
    stringstream strInput(header);
    if(getline(strInput,idstr, ',')
          && getline(strInput,eaststr, ',')
          && getline(strInput,northstr, ',')
          && getline(strInput,latstr, ',')
          && getline(strInput,longstr)){
             MaxDistance = "Dist";
             Frequency = "Freq";
            cout <<  idstr << ", " << eaststr << ", " << northstr << ", " << latstr << ", " << longstr << ", " << MaxDistance << ", " << Frequency  << endl;
          }*/

          cout << "ID, East, North, Latitude, Longitude, MaxDist, Freq" << endl;

    for(int i = 0; i < maxTowers.size(); i++) {
        myTower = maxTowers[i];
        cout <<  myTower.t.getID() << ", " << myTower.t.getEasting() << ", " << myTower.t.getNorthing() << ", "  << 
        myTower.t.getLatitude() << ", " << myTower.t.getLongitude() << ", " << myTower.dist 
             << ", " << myTower.frequency << "\n";
    }

    return 0;
}

//we use pythagorus thearemn to calculate distance
// eastings and northings are points with difference as the distance in a particular direction

double distance( CellTower& t1, CellTower& t2){
    double d = sqrt(pow(t1.getEasting() - t2.getEasting(),2)+pow(t1.getNorthing() - t2.getNorthing(),2));

    return d;
 
}

//the other way round is to use latitudes and longitudes with google maps api.
//but that is more complex and not needed for this exercise
//as we are just looking for relative distances between towers
//and not the actual distance on the earth surface
// I can use google sheets with appscript to derive distances if needed
//or develop an api on top of google maps api or GCP to be connected to this project
