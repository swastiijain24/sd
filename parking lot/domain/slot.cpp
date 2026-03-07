#include <domain/vehicle.cpp>
class Slot
{
private:
    int id;
    Vehicle::vehicleType type;
    bool isOccupied;
    int floorNum;

public:
    Slot(int floorNum, Vehicle::vehicleType type)
    {
        // set all abv
    }

    void setIsOccupied(bool isocc)
    {
        this->isOccupied = isocc;
    }

    

    
};