class Card{
    private:
    int id;
    int accountId;

    public: Card(int accountId){
        this->accountId = accountId;
    }

    int getAccount(){
        return accountId;
    }
};