#include <unordered_map>
#include<domain/slot.cpp>
#include<domain/vehicle.cpp>
#include<services/floorService.cpp>

class SlotService{
    private:

    public: SlotService(){
        // const
    }

    Slot* allocateSlot(Vehicle::vehicleType type){
        // return slot or null if not available 

        Slot* slot;
        return slot;
    }

    void deactivate(ticket* ticket){
        slot* slot = getslot(ticket.slot)
    }


};