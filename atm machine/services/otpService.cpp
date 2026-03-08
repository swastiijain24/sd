#include <string>
using namespace std;


class OtpService{
    private:
    string otp;

    public:
    void sendOtp(string mobileNum){
        // send otp
        // will get a  otp ;
        // this->otp = otp;
    }

    bool verifyOtp(string otp){
        return this->otp==otp;
    }
};