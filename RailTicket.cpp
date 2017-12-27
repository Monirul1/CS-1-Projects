#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
// MD MONIRUL ISLAM
using namespace std;

char getAge(char& age);
char getRound(char& round);
char getPeak(char& peak);
double getCost(char age, char round, char peak, double& cost);
double getDouble(double cost, double& payment);
double calculateChange(double cost, double payment);

int main()
{
    char Yes_or_No = 'Y';
    char age = '!', round = '!', peak = '!';
    double cost = 0.0, payment = 0.0;
    
    do
    {
        while (1 > 0)
        {
            cout << "Get Your Ticket." << endl
            << "Enter X at anytime to cancel. Make sure inputs are capitalized." << endl
            << "Select R for Regular, S for Senior or C for child: ";
            cin >> age;
            age = getAge(age);
            if ((age == 'X'))
            {
                cout << "Canceled" << endl;
                break;
            }
            cout << "Select O for one way or R for round trip: ";
            cin >> round;
            round = getRound(round);
            if ((age == 'X') || (round == 'X'))
            {
                cout << "Canceled" << endl;
                break;
            }
            cout << "Select P for peak or O for off-peak: ";
            cin >> peak;
            peak = getPeak(peak);
            if ((age == 'X') || (round == 'X') || (peak == 'X'))
            {
                cout << "Canceled" << endl;
                break;
            }
            getCost(age, round, peak, cost);
            getDouble(cost, payment);
            if ((age == 'X') || (round == 'X') || (peak == 'X') || (payment == 0))
            {
                cout << "Canceled" << endl;
                break;
            }
            calculateChange(cost, payment);
            break;
        }
        cout << "Would you like to buy another ticket? Y/N: ";
        cin >> Yes_or_No;
        
        while ((Yes_or_No != 'Y') && (Yes_or_No != 'N'))
        {
            cout << "Invalid Input." << endl;
            cout << "Would you like to buy another ticket? Y/N: ";
            cin >> Yes_or_No;
        }
        
    } while (Yes_or_No == 'Y');
    
    cout << "Have a nice trip." << endl;
    return 0;
    
}
//*********************************************************************************************************
char getAge(char& age)
{
    if ((age == 'R') || (age == 'S') || (age == 'C') || (age == 'X'))
        return age;
    
    while ((age != 'R') && (age != 'S') && (age != 'C') && (age != 'X'))
    {
        cout << "Invalid Input" << endl;
        cout << "Select R for Regular, S for Senior or C for child:";
        cin >> age;
    }
    return age;
}
//*********************************************************************************************************
char getRound(char& round)
{
    if ((round == 'O') || (round == 'R') || (round == 'X'))
        return round;
    
    while ((round != 'O') && (round != 'R') && (round != 'X'))
    {
        cout << "Invalid Input" << endl;
        cout << "Select O for one way or R for round trip:";
        cin >> round;
    }
    return round;
}
//*********************************************************************************************************
char getPeak(char& peak)
{
    if ((peak == 'P') || (peak == 'O') || (peak == 'X'))
        return peak;
    
    while ((peak != 'P') && (peak != 'O') && (peak != 'X'))
    {
        cout << "Invalid Input" << endl;
        cout << "Select P for peak or O for off-peak:";
        cin >> peak;
    }
    return peak;
}
//*********************************************************************************************************
double getCost(char age, char round, char peak, double& cost)
{
    if (round == 'R')
    {
        if (peak == 'P')
        {
            if (age == 'C')
                cost = 8.50;
            else if ((age == 'S') || (age == 'R'))
                cost = 17.50;
        }
        if (peak == 'O')
        {
            if (age == 'R')
                cost = 13.00;
            else if (age == 'S')
                cost = 8.50;
            else if (age == 'C')
                cost = 6.50;
        }
    }
    
    if (round == 'O')
    {
        if (peak == 'P')
        {
            if (age == 'C')
                cost = 4.25;
            else if (age == 'S')
                cost = 4.25;
            else if (age == 'R')
                cost = 8.75;
        }
        if (peak == 'O')
        {
            if (age == 'R')
                cost = 6.25;
            else if (age == 'S')
                cost = 4.25;
            else if (age == 'C')
                cost = 3.25;
        }
    }
    cout << setprecision(2) << fixed << showpoint;
    cout << "This ticket will cost: $" << cost << endl;
    return cost;
}
//*********************************************************************************************************
double getDouble(double cost, double& payment)
{
    cout << "Select the amount you paid: $";
    cin >> payment;
    
    while (payment < 0)
    {
        cout << "Invalid Input." << endl;
        cout << "Select the amount you paid: $";
        cin >> payment;
    }
    
    if (payment == 0)
    {
        cout << "Transaction Canceled." << endl;
        return payment;
    }
    
    while (payment < cost)
    {
        cout << "Invalid Input." << endl;
        cout << "Select the amount you paid: $";
        cin >> payment;
    }
}
//*********************************************************************************************************
double calculateChange(double cost, double payment)
{
    
    double change = 0.0;
    change = payment - cost;
    cout << setprecision(2) << fixed << showpoint;
    cout << "Please collect your ticket. Your change is: " << change << endl;
}
//**