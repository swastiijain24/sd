class Exit{
    Ticket* ticket;
    TicketService* ticketService;
    PaymentService paymentService;
    

    public: Exit(Ticket* ticket, TicketService* ticketService){
        this->ticket = ticket;
        // const
    }

    class exitDTO{
        bool success;
        string message;

        exitDTO(bool success, string message){
            // const
        }
    }

    if(!ticket.getisactive()) return new exitDTO(false, "invalid tikcet");
    price = priceservice.calculateprice(ticket);
    paymentService.processpayment(price, ticket, adapter)
    receipt = receiptservice.generatereceipt(ticket)
    Slotservice.makeEmpty(ticket); 
    ticket.setAc

};