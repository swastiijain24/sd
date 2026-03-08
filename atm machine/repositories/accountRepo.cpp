#include <unordered_map>
#include<domain/account.cpp>

class AccountRepo{
    private:
    unordered_map<int , Account*> accMap;

    public:
    Account* getAccount(int accountId){
        return accMap[accountId];
        
    }

    string getMobileNum(int accountId){
        return accMap[accountId]->getMobileNum();
    }
};