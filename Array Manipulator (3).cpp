#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
//MD MONIRUL ISLAM

using namespace std;

double calculate(int& maxi, int& mini, int& sum, double& avg, int arr[], int SIZE);
int repetition(int arr[], int SIZE, int& repeat, int repeat_num);
int insertion(int arr[], int& SIZE, int insert_position, int num_insert);
int deletion(int delete_position, int arr[], int& SIZE);

int main()
{
    int maxi = 0, mini = 0, sum = 0, repeat_num = 0, repeat = 0, insert_position = 0, num_insert = 0, delete_position = 0;\
    int delete_num = 0;
    double avg = 0.0;
    int SIZE = 5;
    int arr[SIZE];

    cout << "Enter -1 to stop inputing integers. You may input a maximum of 5 integers." << endl << endl;

    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> arr[i];
        while (arr[0] == -1)
        {
            cout << "Invalid Input. Please enter another integer: ";
            cin >> arr[i];
        }
        if (arr[i] == -1)
            break;
    }

    SIZE = i;
    cout << endl << endl;

    cout << "Your set is: " << endl;
    for (int j = 0; j < SIZE; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    calculate(maxi, mini, sum, avg, arr, SIZE);
    cout << setprecision(2) << fixed << showpoint;
    cout << "The maximum is: " << maxi << endl;
    cout << "The minimum is: " << mini << endl;
    cout << "The sum is: " << sum << endl;
    cout << "The average is: " << avg << endl;

    cout << "Enter an integer to see how many times it shows up in your set: ";
    cin >> repeat_num;
    repetition(arr, SIZE, repeat, repeat_num);
    cout << repeat_num << " appears " << repeat << " times." << endl << endl;

    cout << "Enter a position that you want to insert an integer at: ";
    cin >> insert_position;
    while ((insert_position > SIZE) || (insert_position < 1))
    {
        cout << "That position is not available. Please try again: ";
        cin >> insert_position;
    }
    cout << "Enter the integer you want to insert: ";
    cin >> num_insert;
    insertion(arr, SIZE, insert_position, num_insert);
    cout << "Your set is: " << endl;
    for (int j = 0; j < SIZE; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl << endl;


    cout << "Enter a position you want to delete: ";
    cin >> delete_position;
    while ((delete_position > SIZE) || (delete_position < 1))
    {
        cout << "That position is not available. Please try again: ";
        cin >> delete_position;
    }
    deletion(delete_position, arr, SIZE);
    cout << "Your set is: " << endl;
    for (int j = 0; j < SIZE; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    return 0;
}

double calculate(int& maxi, int& mini, int& sum, double& avg, int arr[], int SIZE)
{
    int high = arr[0];
    for (int j = 1; j < SIZE; j++)
    {
        if (arr[j] > high)
            high = arr[j];
    }
    maxi = high;

    int low = arr[0];
    for (int j = 1; j < SIZE; j++)
    {
        if (arr[j] < low)
            low = arr[j];
    }
    mini = low;

    int total = 0;
    for (int j = 0; j < SIZE; j++)
        total = total + arr[j];

    sum = total;

    avg = (((double)total) / ((double)SIZE));
}

int repetition(int arr[], int SIZE, int& repeat, int repeat_num)
{
    for (int j = 0; j < SIZE; j++)
    {
        if (arr[j] == repeat_num)
            repeat++;
    }
}

int insertion(int arr[], int& SIZE, int insert_position, int num_insert)
{
    int arr_copy[SIZE];
    for (int j = 0; j < SIZE; j++)
        arr_copy[j] = arr[j];

    for (int z = (insert_position - 1); z < SIZE; z++)
    {
        arr[z + 1] = arr_copy[z];
    }
    arr[(insert_position - 1)] = num_insert;
    SIZE++;
    if (SIZE > 5)
        SIZE = 5;
}

int deletion(int delete_position, int arr[], int& SIZE)
{
    int arr_copy[SIZE];
    for (int j = 0; j < SIZE; j++)
        arr_copy[j] = arr[j];

    for (int z = (delete_position - 1); z < SIZE; z++)
    {
        arr[z] = arr_copy[z + 1];
    }
    SIZE--;
    if (SIZE < 1)
        SIZE = 1;
}
