#ifndef CELLTOWER_H
#define CELLTOWER_H

#include<iostream>

using namespace std;

class CellTower
{
private:
  char id;
  double easting;
  double northing;
  double latitude;
  double longitude;

public:
    CellTower(char i, double e, double n, double la, double lo);
    CellTower();
    
    void setID(char i);
    char getID();
    void setEasting(double e);
    double getEasting();
    void setNorthing(double n);
    double getNorthing();
    void setLatitude(double l);
    double getLatitude();
    void setLongitude(double l);
    double getLongitude();
    

    friend istream& operator>>(istream& is, CellTower& obj);

    ~CellTower();
};









#endif // CELLTOWER_H
