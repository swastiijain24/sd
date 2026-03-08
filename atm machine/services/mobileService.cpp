#include<repositories/accountRepo.cpp>
class MobileService{
    private:
    AccountRepo* accountrepo;

    MobileService(AccountRepo* accountRepo){
        this->accountrepo=accountRepo;
    }

    public:
    string getMobileNum(int accountId){
        return accountrepo->getMobileNum(accountId);
    }
};