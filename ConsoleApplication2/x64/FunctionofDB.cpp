class Func
{
protected:
    vector<Func> atm;
    int change;
    int order;
    int  bills;

public:
    Func(int change = 5000, int order = 2000,int  bills(1))
    {
        atm.change = 5000;
        atm.order = 2000;
        atm.bills=1;
      
    }

    void change()
    {
        if (this->change == 0)
        {
            cout << "change ";
            cin >> changer;
            this->change = +change;
        }
    }
    void order()
    {
        if (this->order == 0)
        {
            cout << "order: ";
            cin >> order;
            this->order = +order;
        }
    }
    void  bills(1)()
    {
        if (this->bills == 0)
        {
            cout << " bills";
            cin >> bills;
            this->bills = +bills;
        }
    }
  
    int change() { return this->change; }
    int order() { return this->order; }
    int bills() { return this->bills; }
   

    void Show()
    {
        cout << "Automat is full: \n";
      
    }
    int SetCache()
    {
        return this->cache = orderC + billsC;
    }
};

class Coffee :public Automat
{
   
public:
    order()
    {
       int order = 100;
       int  resr = 10;
       int  kod = 15;
       int  wod = 2;
    }
    void bills()
    {

        int order = 1010;
        int resr = 120;
        int kod = 125;
        int  wod = 210;
    }

};




class Client :public order, public bills
{

public:

    choice = getChoice(machine);
    while (choice != 5)
    {

        transaction(machine, choice, earnings);


        choice = getChoice(machine);
    }


    cout << "Total earnings: $" << earnings << endl;
    return 0;
}
};