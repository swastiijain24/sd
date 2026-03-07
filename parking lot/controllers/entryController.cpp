#include <domain/vehicle.cpp>
#include <services/slotService.cpp>
#include <services/ticketService.cpp>

class Entry
{
private:
    SlotService slotService;
    TicketService ticketService;

    Entry(){
        // const
    }

    class EntryDTO
    {
        private:
            bool success;
            string message;
            int ticketId;

        public:
            EntryDTO(bool success, string message)
            {
                // const
            }
    };

    EntryDTO *entryResult(Vehicle::vehicleType type, string NumberPlate)
    {
        Vehicle *vehicle = new Vehicle(type, NumberPlate);
        Slot *slot = slotService.allocateSlot(type);

        if (!slot)
            return new EntryDTO(false, "no slots");

        Ticket *ticket = ticketService.generateTicket();
        slot->setIsOccupied(true);
        return new EntryDTO(true, "slot assigned")
    }
};