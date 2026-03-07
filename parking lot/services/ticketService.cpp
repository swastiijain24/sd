#include<domain/ticket.cpp>

class TicketService{

    TicketService(){
        // const
    }

    Ticket* generateTicket(){
        Ticket* ticket = new Ticket()
        ticket.setIsactive(true);
        ticket.save();
        return ticket;
    }

    // bool isValid(Ticket* ticket){
    //     return ticket.getIsActive();
    // }

};