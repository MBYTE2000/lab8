#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Train
{
    int Date = 0;
    string EndPoint = "";
    int time = 0;
    int numberOfSeats = 0;
};

int main()
{
    // Инициализация:
    int lastTrainIndex = -1;

    int numberOfTrains = 0;

    int Date = 0;
    string EndPoint = "";
    int time = 0;
    int numberOfSeats = 0;


    cout << "Date: " << endl; cin >> Date;
    cout << "Endpoint: " << endl; cin >> EndPoint;
    cout << "Time: " << endl; cin >> time;
    cout << "Numbers of seats: " << endl; cin >> numberOfSeats;

    cout << "Enter number of trains: "; cin >> numberOfTrains; cout << "\n";
    Train* trains = new Train[numberOfTrains];

    // Ввод:
    for (int i = 0; i < numberOfTrains; i++)
    {

        cout << i + 1 << ". Date: "; cin >> trains[i].Date;
        cout << "Seats: "; cin >> trains[i].numberOfSeats; cout << "\n";
        cout << "Endpoint: "; cin >> trains[i].EndPoint; cout << "\n";
        cout << "Time: "; cin >> trains[i].time; cout << "\n";
    }

    cout << "////////////////////////////////////////////////////////////" << endl;
    bool flag = false;
    for (int i = 0; i < numberOfTrains; i++)
    {
        if ((trains[i].Date == Date) && (trains[i].EndPoint==EndPoint) && (trains[i].time <= time) && (trains[i].numberOfSeats >= numberOfSeats))
        {
            cout << i + 1 << "Date: " << trains[i].Date << endl;
            cout << "Seats: " << trains[i].numberOfSeats << endl;
            cout << "Endpoint: " << trains[i].EndPoint << endl;
            cout << "Time: " << trains[i].time << endl;
            flag = true;
        }
    }
    if (flag == false)cout << "Таких поездов нет" << endl;
    cout << endl;
    delete[]trains;
    return 0;
}