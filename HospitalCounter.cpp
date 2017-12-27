#include<iostream>
#include<iomanip>
#include<cmath>
//MD MONIRUL ISLAM

using namespace std;

double Costs(int numDays, double ratePerday, double lab, double medication);  //int nummdays int douvle rate days enter the numebr that best works for you""

double Costs(double lab, double medication); //double Costs (double lab, double medication
int main()
{
       int stay;
       double totalIn;
       double totalOut;
       int numDays;
       double ratePerday, lab, medication;

       cout << "Please ENTER 1 for inpatient stay or a 2 for outpatient stay." << endl;
       cin >> stay;

       while (stay != 1 && stay != 2)
       {
              cout << "Please ENTER 1 for inpatient stay or a 2 for outpatient stay." << endl;
              cin >> stay;
       }

       switch(stay)
       {

       case 1:
              cout << "Please enter the number of days spent at the hospital: " << endl;
              cin >> numDays;
              cout << "Please enter the hospital's daily rate: " << endl;
              cin >> ratePerday;
              cout << "Please enter the charges for Hospital Services: " << endl;
              cin >> lab;
              cout << "Please enter the charges for medications: " << endl;
              cin >> medication;
              totalIn = Costs(numDays, ratePerday, lab, medication);
              cout << "The total inpatient costs are: $" << totalIn << endl;
              break;

       case 2:
              cout << "Please enter the charges for Hospital Services: " << endl;
              cin >> lab;
              cout << "Please enter the charges for medications: " << endl;
              cin >> medication;
              totalOut = Costs(lab, medication);
              cout << "The total outpatient costs are: $" << totalOut << endl;
              break;
       }

       return 0;
}

double Costs(int numDays, double ratePerday, double lab, double medication)
{

       return (numDays * ratePerday) + lab + medication;
}


double Costs(double lab, double medication)
{

       return lab + medication;
}
