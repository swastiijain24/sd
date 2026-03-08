#include<domain/card.cpp>

class CardService{
    public:
    bool verifyCard(Card* card){
        // verify the card is valid or not
        // return true or false;
        return 1;
    }

    int accountId(Card* card){
        return card->getAccount();
    }
};