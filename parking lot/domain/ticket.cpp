class Ticket{
    private:
    int id;
    bool isActive;
    int slot;
    int vehicle; 
    int timestamp;

    public:
    ticket(){
        // const
    }

    bool getIsactive(){
        return isActive;
    }

    void setisactive(bool flag){
        isactive =flag;
    }

    int getslot(){
        return slot;
    }
}