
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;

int GetNumbers(int& int1, int& int2, int& int3);
string GetUsername(string& Username);
int GetSum(int int1, int int2, int int3, int& sum);
int GetAvereage(int int1, int int2, int int3, int sum, int& average);
int GetMax(int int1, int int2, int int3, int& largest);
int GetMin(int int1, int int2, int int3, int& smallest);
int GetAnswers(int& Guess_sum, int& Guess_average, int& Guess_largest, int& Guess_smallest);
int ShowCorrectAnswers(string Username, int sum, int average, int largest, int smallest, int Guess_sum, int Guess_average, int Guess_largest, int Guess_smallest, int& track_sum, int& track_average, int& track_largest, int& track_smallest);
void ShowResults(int track_sum, int track_average, int track_largest, int track_smallest, int track_times);

int main()
{
    string Username = "MONIRULLLLLLLLLL";
    char Yes_or_No, Yes_or_No2;
    int int1 = 0, int2 = 0, int3 = 0, sum = 0, average = 0, largest = 0, smallest = 0;
    int Guess_sum = 0, Guess_average = 0, Guess_largest = 0, Guess_smallest = 0;
    int track_sum = 0, track_average = 0, track_largest = 0, track_smallest = 0, track_times = 1;

    do
    {
        while (1 > 0)
        {
            cout << "I want to play a game." << endl
                 << "Press Y to continue, N to quit." << endl;
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

            GetUsername(Username);
            GetNumbers(int1, int2, int3);
            cout << Username << ", you have entered: " << int1 << ", " << int2 << ", " << int3 << endl;
            GetSum(int1, int2, int3, sum);
            GetAvereage(int1, int2, int3, sum, average);
            GetMax(int1, int2, int3, largest);
            GetMin(int1, int2, int3, smallest);
            GetAnswers(Guess_sum, Guess_average, Guess_largest, Guess_smallest);
            ShowCorrectAnswers(Username, sum, average, largest, smallest, Guess_sum, Guess_average, Guess_largest, Guess_smallest, track_sum, track_average, track_largest, track_smallest);

            cout << "Would you like to play again? Y/N: ";
            cin >> Yes_or_No2;
            if ((Yes_or_No2 == 'Y'))
            {
                track_times++;
                cout << endl;
            }
            if ((Yes_or_No2 == 'N'))
            {
                cout << endl;
                ShowResults(track_sum, track_average, track_largest, track_smallest, track_times);
                break;
            }
            while ((Yes_or_No2 != 'Y') && (Yes_or_No2 != 'N'))
            {
                cout << "Invalid Input." << endl;
                cout << "Press Y to continue, N to quit." << endl;
                cin >> Yes_or_No2;
            }
        }
    } while ((Yes_or_No == 'Y') && (Yes_or_No2 == 'Y'));

    cout << "Thanks for playing!" << endl;
    return 0;
}
//****************************************************************************************************************
string GetUsername(string& Username)
{
    cout << "Enter Username: ";
    cin >> Username;
    cout << "Prepare yourself, " << Username << "." << endl << endl;

    return Username;
}
//****************************************************************************************************************
int GetNumbers(int& int1, int& int2, int& int3)
{
    cout << "Enter an integer: ";
    cin >> int1;
    cout << "Enter a second integer: ";
    cin >> int2;
    cout << "Enter a third integer: ";
    cin >> int3;

    return int1, int2, int3;
}
//****************************************************************************************************************
int GetSum(int int1, int int2, int int3, int& sum)
{
    sum = int1 + int2 + int3;

    return sum;
}
//****************************************************************************************************************
int GetAvereage(int int1, int int2, int int3, int sum, int& average)
{
    average = sum / 3;

    return average;
}
//****************************************************************************************************************
int GetMax(int int1, int int2, int int3, int& largest)
{
    int maxi = int1;

    if (int2 > maxi)
        maxi = int2;
    if (int3 > maxi)
        maxi = int3;

    largest = maxi;
    return largest;
}
//****************************************************************************************************************
int GetMin(int int1, int int2, int int3, int& smallest)
{
    int low = int1;

    if (int2 < low)
        low = int2;
    if (int3 < low)
        low = int3;

    smallest = low;
    return smallest;
}
//****************************************************************************************************************
int GetAnswers(int& Guess_sum, int& Guess_average, int& Guess_largest, int& Guess_smallest)
{
    cout << "Guess the sum: ";
    cin >> Guess_sum;
    cout << "Guess average: ";
    cin >> Guess_average;
    cout << "Guess largest number: ";
    cin >> Guess_largest;
    cout << "Guess smallest number: ";
    cin >> Guess_smallest;

    return Guess_sum, Guess_average, Guess_largest, Guess_smallest;
}
//****************************************************************************************************************
int ShowCorrectAnswers(string Username, int sum, int average, int largest, int smallest, int Guess_sum, int Guess_average, int Guess_largest, int Guess_smallest, int& track_sum, int& track_average, int& track_largest, int& track_smallest)
{
    if ((Guess_sum != sum) || (Guess_average != average) || (Guess_largest != largest) || (Guess_smallest != smallest))
        cout << "Sorry " << Username << endl;
    else if ((Guess_sum == sum) && (Guess_average == average) && (Guess_largest == largest) && (Guess_smallest == smallest))
        cout << "Good job " << Username << endl;

    if (Guess_sum == sum)
        track_sum++;
    else if (Guess_sum != sum)
        cout << "The correct answer for sum is: " << sum << endl;

    if (Guess_average == average)
        track_average++;
    else if (Guess_average != average)
        cout << "The correct answer for average is: " << average << endl;

    if (Guess_largest == largest)
        track_largest++;
    else if (Guess_largest != largest)
        cout << "The correct answer for largest is: " << largest << endl;

    if (Guess_smallest == smallest)
        track_smallest++;
    else if (Guess_smallest != smallest)
        cout << "The correct answer for largest is: " << smallest << endl;

    return track_sum, track_average, track_largest, track_smallest;
}
//****************************************************************************************************************
void ShowResults(int track_sum, int track_average, int track_largest, int track_smallest, int track_times)
{
    float percent = 0.0;

    //cout << setprecision(0) << fixed << showpoint;
    percent = (((float)(track_sum)) / ((float)(track_times))) * 100.0;
    cout << "sum correct " << track_sum << " out of " << track_times << " or " << (int)percent << "%" << endl;

    percent = (((float)(track_average)) / ((float)(track_times))) * 100.0;
    cout << "average correct " << track_average << " out of " << track_times << " or " << (int)percent << "%" << endl;

    percent = (((float)(track_largest)) / ((float)(track_times))) * 100.0;
    cout << "largest correct " << track_largest << " out of " << track_times << " or " << (int)percent << "%" << endl;

    percent = (((float)(track_smallest)) / ((float)(track_times))) * 100.0;
    cout << "smallest correct " << track_smallest << " out of " << track_times << " or " << (int)percent << "%" << endl;
}
//****************************************************************************************************************
