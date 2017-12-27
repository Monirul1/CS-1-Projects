//Brandon Roy 10/30/16

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;

string getUsername(string& Username);
float getSpend(float& Spend);
int displayChoices(float Spend, int& trackDisplay);
int getChoice(float& Choice, int trackDisplay);
float moneyLeft(float& Spend, float& Choice, int& trackDisplay , const float Item1, const float Item2, const float Item3, const float Item4, int& MonLeft);

int main()
{
    string Username = "Roy", Email = "purpur@gmail.com;";
    char Yes_or_No, Receipt;
    int trackDisplay = 0, MonLeft;
    float Spend = 0.0, Choice;
    const float Item1 = 50.00, Item2 = 24.00, Item3 = 14.00, Item4 = 4.00;

    do
    {
        while (1 > 0)
        {
            cout << "Its Black Friday! Welcome to Walmart! Prepare to be in debt!" << endl;
            cout << "Who do I have the pleasure of assisting today?: ";
            getUsername(Username);

            cout << "Are you ready to spend your money? Y/N: ";
            cin >> Yes_or_No;

            if ((Yes_or_No == 'N'))
            {
                cout << "*quit*" << endl;
                break;
            }
            while ((Yes_or_No != 'Y') && (Yes_or_No != 'N'))
            {
                cout << "Invalid Input." << endl;
                cout << "Press Y to continue, N to quit." << endl;
                cin >> Yes_or_No;
            }

            cout << "How much money do you have to spend?: $";
            getSpend(Spend);
            cout << endl;

            cout << "Well " << Username << " , you can afford: " << endl;
            displayChoices(Spend, trackDisplay);
            cout << endl;
            if (trackDisplay == 0)
                break;

            getChoice(Choice, trackDisplay);
            if (Choice == 0)
            {
                cout << "*quit*" << endl;
                break;
            }

            moneyLeft(Spend, Choice, trackDisplay, Item1, Item2, Item3, Item4, MonLeft);
            cout << setprecision(2) << fixed << showpoint;
            cout << "You have spent $" << Choice << " you have $" << Spend << " left." << endl << endl;
            if (MonLeft == 0)
            {
                cout << "You can't afford anything else." << endl;
                break;
            }

            while (MonLeft == 1)
            {
                displayChoices(Spend, trackDisplay);
                if (trackDisplay == 0)
                break;
                getChoice(Choice, trackDisplay);
                moneyLeft(Spend, Choice, trackDisplay, Item1, Item2, Item3, Item4, MonLeft);
                if (MonLeft == 0)
                {
                    cout << "You can't afford anything else." << endl;
                    break;
                }
                cout << setprecision(2) << fixed << showpoint;
                cout << "You have spent $" << Choice << " you have $" << Spend << " left." << endl << endl;
            }
            if (MonLeft == 0)
                break;
        }
    } while ((Yes_or_No == 'Y') && (Choice != 0) && (MonLeft == 1));

    if (Choice == 0)
    {
        cout << setprecision(2) << fixed << showpoint;
        cout << "You still have $" << Spend << " in case you were thinking of shopping again." << endl;
        return 0;
    }
    if (trackDisplay == 0)
    {
        cout << setprecision(2) << fixed << showpoint;
        cout << "You still have $" << Spend << " in case you were thinking of shopping again." << endl;
        return 0;
    }
    else
    {
        cout << "Would you like a receipt emailed to you? Y/N: ";
        cin >> Receipt;
        if ((Receipt == 'N'))
        {
            cout << setprecision(2) << fixed << showpoint;
            cout << "You still have $" << Spend << " in case you were thinking of shopping again." << endl;
            return 0;
        }
        while ((Receipt != 'Y') && (Receipt != 'N'))
        {
            cout << "Invalid Input." << endl;
            cout << "Press Y to continue, N to quit." << endl;
            cin >> Receipt;
        }
        cout << "Enter your email address: ";
        cin >> Email;
        cout << setprecision(2) << fixed << showpoint;
        cout << "You still have $" << Spend << " in case you were thinking of shopping again." << endl;
        return 0;
    }
    return 0;
}
//****************************************************************************************************************
string getUsername(string& Username)
{
    cin >> Username;
    return Username;
}
//****************************************************************************************************************
float getSpend(float& Spend)
{
    cin >> Spend;
    while ((Spend < 0.0) || (Spend < 0))
    {
        cout << "Invalid Input." << endl;
        cout << "Enter amount to spend again: $";
        cin >> Spend;
    }
    return Spend;
}
//****************************************************************************************************************
int displayChoices(float Spend, int& trackDisplay)
{
    if (Spend >= 50.00)
    {
        cout << "0) Enter 0 to Cancel" << endl;
        cout << "1) A Walmart Gift Card: $50.00" << endl;
        cout << "2) Cologne: $24.00" << endl;
        cout << "3) Key Chain: $14.00" << endl;
        cout << "4) Pack of Gum: $4.00" << endl;
        trackDisplay = 1;
    }
    else if ((Spend >= 24.00) && (Spend < 50.00))
    {
        cout << "0) Enter 0 to Cancel" << endl;
        cout << "2) Cologne: $24.00" << endl;
        cout << "3) Key Chain: $14.00" << endl;
        cout << "4) Pack of Gum: $4.00" << endl;
        trackDisplay = 2;
    }
    else if ((Spend >= 14.00) && (Spend < 24.00))
    {
        cout << "0) Enter 0 to Cancel" << endl;
        cout << "3) Key Chain: $14.00" << endl;
        cout << "4) Pack of Gum: $4.00" << endl;
        trackDisplay = 3;
    }
    else if ((Spend >= 4.00) && (Spend < 14.00))
    {
        cout << "0) Enter 0 to Cancel" << endl;
        cout << "4) Pack of Gum: $4.00" << endl;
        trackDisplay = 4;
    }
    else if (Spend < 4.00)
    {
        cout << "You cannot afford anything." << endl;
        trackDisplay = 0;
    }
    return trackDisplay;
}
//****************************************************************************************************************
int getChoice(float& Choice, int trackDisplay)
{
    cout << "So what would you like?: ";
    cin >> Choice;
    while ((trackDisplay == 1) && (Choice != 1) && (Choice != 2) && (Choice != 3) && (Choice != 4) && (Choice != 0))
    {
        cout << "Invalid Input." << endl;
        cout << "Choice not available, please choose another: ";
        cin >> Choice;
    }
    while ((trackDisplay == 2) && (Choice != 2) && (Choice != 3) && (Choice != 4) && (Choice != 0))
    {
        cout << "Invalid Input." << endl;
        cout << "Choice not available, please choose another: ";
        cin >> Choice;
    }
    while ((trackDisplay == 3) && (Choice != 3) && (Choice != 4) && (Choice != 0))
    {
        cout << "Invalid Input." << endl;
        cout << "Choice not available, please choose another: ";
        cin >> Choice;
    }
    while ((trackDisplay == 4) && (Choice != 4) && (Choice != 0))
    {
        cout << "Invalid Input." << endl;
        cout << "Choice not available, please choose another: ";
        cin >> Choice;
    }
    if (Choice == 1)
        cout << "(~^-^)~ Expensive and unoriginal, wonderful!" << endl;
    if (Choice == 2)
        cout << "(~^-^)~ You smell bad, and you should feel bad, wonderful!" << endl;
    if (Choice == 3)
        cout << "(~'-')~ It will have to do..." << endl;
    if (Choice == 4)
        cout << "(-'_')- You're cheap, and you should feel bad..." << endl;
    return Choice;
}
//****************************************************************************************************************
float moneyLeft(float& Spend, float& Choice, int& trackDisplay , const float Item1, const float Item2, const float Item3, const float Item4, int& MonLeft)
{
    if (Choice == 0)
    {
        MonLeft = 0;
        Choice = 0;
    }
    else
        Choice = ((float)(Choice));

    if (Choice == 1)
        Choice = Item1;
    if (Choice == 2)
        Choice = Item2;
    if (Choice == 3)
        Choice = Item3;
    if (Choice == 4)
        Choice = Item4;


    if ((Choice == Item1) || (Choice == Item2) || (Choice == Item3) || (Choice == Item4))
        Spend = ((float)Spend) - ((float)Choice);
    else
        Spend = 0.00;

    if (Spend > 4.00)
        MonLeft = 1;
    else
        MonLeft = 0;

    return MonLeft;
    return Spend;
    return Choice;
}
//****************************************************************************************************************

//****************************************************************************************************************
