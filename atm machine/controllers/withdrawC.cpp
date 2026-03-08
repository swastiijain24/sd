#include <string>
#include<services/amountService.cpp>
#include<services/cardService.cpp>
#include<services/pinService.cpp>
#include<domain/card.cpp>
using namespace std;

class Withdraw{
    private:
    CardService* cardService;
    PinService* pinService;
    AmountService* amountService;

    public:
    Withdraw(CardService* cardService, PinService* pinService,  AmountService* amountService){
        this->cardService = cardService;
        this->pinService = pinService;
        this->amountService = amountService;
    }

    class WithdrawDTO{
        private:
        bool success;
        int amount;
        string message;

        public: WithdrawDTO(bool suc, int amt, string msg){
            success = suc;
            amount=amt;
            message =msg;
        }
    };

    WithdrawDTO* withdrawMoney(Card* card, string pin, int amount){
        bool validCard = cardService->verifyCard(card);
        if(!validCard) return new WithdrawDTO(false, 0, "invalid card");

        int accountId = cardService->accountId(card);

        bool validPin = pinService->verifyPin(pin, accountId);
        if(!validPin) return new WithdrawDTO(false, 0, "invalid pin");

        if(!amountService->withdraw(amount, accountId)) return new WithdrawDTO(true, 0, "insufficient balance");
        return new WithdrawDTO(true, amount, "money withdrawn");

    }



};