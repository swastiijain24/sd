#include <string>
using namespace std;
class Account{
    private:
    int id;
    string bankName;
    string ownerName;
    string mobileNum;
    int balance;
    string pin;

    public:
    Account(string bankName, string ownerName, int balance, string pin, string mobileNum){
        this->id = id;
        this->bankName = bankName;
        this->ownerName = ownerName;
        this->balance = balance;
        this->pin = pin;
        this->mobileNum=mobileNum;
    }

    string getMobileNum(){
        return mobileNum;
    }

    string getPin(){
        return pin;
    }

    void setPin(string newPin){
        pin=newPin;
    }
    
    int getBalance(){
        return balance;
    }

    void setBalance(int amount){
        this->balance= amount;
    }

};