#include<services/amountService.cpp>
#include<services/cardService.cpp>
#include<services/pinService.cpp>

class Deposit{
    
    private:
    CardService* cardService;
    PinService* pinService;
    AmountService* amountService;

    public:
    Deposit(CardService* cardService, PinService* pinService,  AmountService* amountService){
        this->cardService = cardService;
        this->pinService = pinService;
        this->amountService = amountService;
    }

    class depositDTO{
        private:
        bool success;
        string message;

        public:
        depositDTO(bool s, string m){
            success =s;
            message =m;
        }
    };


    depositDTO* depositMoney(Card* card, string pin, int amount){
        bool validCard = cardService->verifyCard(card);
        if(!validCard) return new depositDTO(false, "invalid card");

        int accountId = cardService->accountId(card);

        bool validPin = pinService->verifyPin(pin, accountId);
        if(!validPin) return new depositDTO(false, "invalid pin");

        amountService->deposit(amount, accountId);
        return new depositDTO(true, "deposited money");
    }

};