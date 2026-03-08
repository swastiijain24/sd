#include<domain/account.cpp>
#include<repositories/accountRepo.cpp>

class AmountService{
    private:
    AccountRepo* accountRepo;

    public:
    AmountService(AccountRepo* accountRepo){
       this->accountRepo=  accountRepo;
    }

    bool withdraw(int amount, int accountId){
        Account* account = accountRepo->getAccount(accountId);
        int curr = account->getBalance();
        if(amount>curr) return false;
        account->setBalance(curr-amount);
        return true;
    }

    void deposit(int amount, int accountId){
        Account* account = accountRepo->getAccount(accountId);
        int curr = account->getBalance();
        account->setBalance(curr+amount);
    }

    int checkBalance(int accountId){
        Account* account = accountRepo->getAccount(accountId);
        return account->getBalance();
    }
    
};