#include "CellTower.h"

#include <sstream>

CellTower::CellTower()
{
}

CellTower::CellTower(char i, double e, double n, double la, double lo){
    id = i;
    easting = e;
    northing = n;
    latitude = la;
    longitude = lo;

}

void CellTower::setID(char i){

    id = i;
}

char CellTower::getID(){
    return id;
}

void CellTower::setEasting(double e){
    easting  = e;
}
double CellTower::getEasting(){
    return easting;
}
void CellTower::setNorthing(double n){
    northing = n;
}
    
double CellTower::getNorthing(){
    return northing;
}
void CellTower::setLatitude(double l){
    latitude = l;
}
double CellTower::getLatitude(){
    return latitude;
}
void CellTower::setLongitude(double l){
    longitude = l;
}
double CellTower::getLongitude(){
    return longitude;
}
// Overload the extraction operator to read CellTower data from an input stream
istream& operator>>(istream& is, CellTower& obj) {
    string line, idstr, eaststr, northstr,latstr,longstr;
    // Example: reading an integer and then a string
    if (getline(is, line)) {
        stringstream strInput(line);

        if(getline(strInput,idstr, ',')
          && getline(strInput,eaststr, ',')
          && getline(strInput,northstr, ',')
          && getline(strInput,latstr, ',')
          && getline(strInput,longstr)){

            try
            {
                obj.id = idstr[0];
                obj.easting = stod(eaststr);
                obj.northing = stod(northstr);
                obj.latitude = stod(latstr);
                obj.longitude = stod(longstr);
            }
            catch(const std::exception& e)
            {
                is.setstate(ios::failbit);
                cerr << "Error passing line: " << line << " - " << e.what() << endl;
            }
            
          };
    }
    return is; // Return the input stream object for chaining
}


CellTower::~CellTower()
{
}