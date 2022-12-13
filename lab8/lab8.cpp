#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Student
{
    string FirstName = "";
    string LastName = "";
    int math = 0;
    int physics = 0;
    double getAverageScore()
    {
        return (math + physics) / 2.;
    }
};
void WriteFile(string file);
void ReadFile(string file);

int SizeOfStudent = sizeof(Student);
int arrLengt;
Student* arr;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "ВВедите длинну списка:" << endl;
    cin >> arrLengt;

    arr = new Student[arrLengt];

    for (int i = 0; i < arrLengt; i++)
    {
        cout << "Name:" << endl;
        cin >> arr[i].FirstName;
        cout << "LastName:" << endl;
        cin >> arr[i].LastName;
        cout << "math:" << endl;
        cin >> arr[i].math;
        cout << "physics:" << endl;
        cin >> arr[i].physics;
    }
    int ch = 0;
    cin >> ch;
    switch (ch)
    {
    case 1:
        WriteFile("\Zap1");
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    return 0;
}

void WriteFile(string file)
{
    FILE* f;
    fopen_s(&f, (file + ".txt").c_str(), "w+");
    //FILE* binf = fopen(file.c_str(), "w+");
    if (f)
    {
        cout << "файл не найден. Будет создан новый!"<< endl;
        for (int i = 0; i < arrLengt; i++)
        {
            fprintf_s(f, "\n %s , %s , %d , %d , %f .", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].math, arr[i].physics, arr[i].getAverageScore());


        }
        fclose(f);
    }
    else
    {

    }
   
}
void ReadFile(string file)
{
}