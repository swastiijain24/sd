#include <string>
using namespace std;

class Vehicle{
    public: enum vehicleType{
        CAR, BIKE, TRUCK
    };

    private :
    int id; 
    vehicleType type;
    string numberPlate;

    public: Vehicle(vehicleType type, string numberPlate){
        // set all abv;
    }

    

};