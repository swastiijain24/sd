#include <string>
#include<services/cardService.cpp>
#include<services/otpService.cpp>
#include<services/mobileService.cpp>
#include<services/pinService.cpp>


using namespace std;

class ChangePin{
    private :
    CardService* cardService;
    MobileService* mobileService;
    OtpService* otpService;
    PinService* pinService;

    public:
    ChangePin(CardService* cardService, MobileService* mobileService, OtpService* otpService, PinService* pinService){
        this->cardService = cardService;
        this->mobileService = mobileService;
        this->otpService = otpService;
        this->pinService = pinService;
    }


    class ChangePinDTO{
        private:
        bool success;
        string message;

        public:
        ChangePinDTO(bool s, string m){
            success=s;
            message=m;
        }


    };

    ChangePinDTO* forgotOrResetPin(Card* card, string otp, string newPin){
        bool validCard = cardService->verifyCard(card);
        if(!validCard) return new ChangePinDTO(false, "card not supported");

        int accountId = cardService->accountId(card);
        string mobileNum = mobileService->getMobileNum(accountId);
        otpService->sendOtp(mobileNum);
        bool validtOpt = otpService->verifyOtp(otp);

        if(!validtOpt) return new ChangePinDTO(false, "invalid otp");

        pinService->resetPin(newPin, accountId);
        return new ChangePinDTO(true, "pin updated");

    }
};