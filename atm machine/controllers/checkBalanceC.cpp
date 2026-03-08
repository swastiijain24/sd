#include<services/amountService.cpp>
#include<services/cardService.cpp>
#include<services/pinService.cpp>

class CheckBalance{
    
    private:
    CardService* cardService;
    PinService* pinService;
    AmountService* amountService;

    public:
    CheckBalance(CardService* cardService, PinService* pinService,  AmountService* amountService){
        this->cardService = cardService;
        this->pinService = pinService;
        this->amountService = amountService;
    }

    class CheckBalanceDTO{
        private:
        bool success;
        int amount;
        string message;

        public:
        CheckBalanceDTO(bool s,int amt, string m){
            success =s;
            amount =amt;
            message =m;
        }
    };


    CheckBalanceDTO* checkBalanceMoney(Card* card, string pin){
        bool validCard = cardService->verifyCard(card);
        if(!validCard) return new CheckBalanceDTO(false,0, "invalid card");

        int accountId = cardService->accountId(card);

        bool validPin = pinService->verifyPin(pin, accountId);
        if(!validPin) return new CheckBalanceDTO(false,0, "invalid pin");

        int balance = amountService->checkBalance(accountId);
        return new CheckBalanceDTO(true,balance, "checkBalanced money");
    }

};