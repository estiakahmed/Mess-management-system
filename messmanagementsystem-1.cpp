#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Userinfo
{
protected:
    string username, password;
public:
    Userinfo(string name, string pass) : username(name), password(pass) {}
};

class MenuItem
{
public:
    virtual void display() = 0;
    virtual int getPrice() = 0;
    virtual string getName() = 0;
};

class RiceAndEgg : public MenuItem
{
public:
    void display() override { cout << "1. Rice and Egg (100 BDT)" << endl; }
    string getName() override { return "Rice and Egg"; }
    int getPrice() override { return 100; }
};

class VegetableAndFriedRice : public MenuItem
{
public:
    void display() override { cout << "2. Vegetable Fried Rice (150 BDT)" << endl; }
    string getName() override { return "Vegetable Fried Rice"; }
    int getPrice() override { return 150; }
};

class Mutton : public MenuItem
{
public:
    void display() override { cout << "3. Mutton (200 BDT)" << endl; }
    string getName() override { return "Mutton"; }
    int getPrice() override { return 200; }
};

class Chicken : public MenuItem
{
public:
    void display() override { cout << "4. Chicken (250 BDT)" << endl; }
    string getName() override { return "Chicken"; }
    int getPrice() override { return 250; }
};

class totalBalance
{
private:
    int fund;

public:
    totalBalance(int balance) : fund(balance) {}

    void showBalance()
    {
        cout << "Remaining Balance: " << fund << " BDT" << endl;
    }

    bool reduce(int amount)
    {
        if (fund >= amount)
        {
            fund -= amount;
            return true;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
            return false;
        }
    }
};

int main()
{
    Userinfo* user = nullptr;
    totalBalance balance(1000);
    vector<string> meals;

    int op;
    string name, pass;

    while (true)
    {
        cout << "\n1. Register User" << endl;
        cout << "2. Menu Items" << endl;
        cout << "3. Show Balance" << endl;
        cout << "4. Show Total Meals" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> op;

        RiceAndEgg rice;
        VegetableAndFriedRice veg;
        Mutton mutton;
        Chicken chicken;
        MenuItem* chosenItem = nullptr;

        switch (op)
        {
        case 1:
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> pass;
            user = new Userinfo(name, pass);
            cout << "---User Registration Successful---" << endl;
            break;

        case 2:
            if (!user)
            {
                cout << "Register first!" << endl;
                break;
            }

            rice.display();
            veg.display();
            mutton.display();
            chicken.display();

            int input;
            cin >> input;

            if (input == 1) chosenItem = &rice;
            else if (input == 2) chosenItem = &veg;
            else if (input == 3) chosenItem = &mutton;
            else if (input == 4) chosenItem = &chicken;
            else
            {
                cout << "Invalid choice!" << endl;
                break;
            }

            if (balance.reduce(chosenItem->getPrice()))
            {
                meals.push_back(chosenItem->getName());
                cout << "You ordered: " << chosenItem->getName() << endl;
            }
            break;

        case 3:
            balance.showBalance();
            break;

        case 4:
            cout << "Total Meals Ordered:" << endl;
            for (string m : meals)
                cout << "- " << m << endl;
            break;

        case 5:
            delete user;
            return 0;

        default:
            cout << "Invalid option!" << endl;
        }
    }
}
