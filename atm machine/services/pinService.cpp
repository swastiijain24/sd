#include <string>
#include<domain/card.cpp>
#include<domain/account.cpp>
#include<repositories/accountRepo.cpp>
using namespace std;

class PinService{

    private:
    AccountRepo* accountRepo;

    
    public:

    PinService(AccountRepo* accountRepo){
        this->accountRepo = accountRepo;
    }

    bool verifyPin(string pin, int accountId){
        Account* account = accountRepo->getAccount(accountId);
        return account->getPin()==pin;
    }

    void resetPin(string newPin, int accountId){
        Account* account = accountRepo->getAccount(accountId);
        return account->setPin(newPin);
    }
};