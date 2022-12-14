#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Student
{
    string FirstName = "";
    string LastName = "";
    int group = 1;
    int math = 0;
    int physics = 0;
    double getAverageScore()
    {
        return (math + physics) / 2.;
    }
};
void CreateFile(string file);
void ReadFile(string file);
void AddToFile(string file);
void Sort(string Sortedfile);

int SizeOfStudent = sizeof(Student);
int arrLengt=10;
Student* arr;

FILE* f;
//FILE* binf;

int main()
{
    setlocale(LC_ALL, "ru");
    
    while (true) 
    {
        cout << "\n1-создание; 2-чтение; 3 -добавить; 4 -сортировка" << endl;
        int ch = 0;
        cin >> ch;
        switch (ch)
        {
        case 1:
            CreateFile("\Zap1");
            break;
        case 2:
            ReadFile("\Zap1");
            break;
        case 3:
            AddToFile("\Zap1");
            break;
        case 4:
            Sort("\Zap1");
            break;
        default:
            break;
        }
    }
    return 0;
}

void CreateFile(string file)
{
    /*fopen_s(&f, (file + ".txt").c_str(), "rb+");
    if (!f) {
        puts("Файл не обнаружен. Будет создан файл с указанным именем");
    }
    else
        puts("Файл существует и перезаписан");
    fclose(f);*/
    cout << "ВВедите длинну списка:" << endl;
    cin >> arrLengt;

    arr = new Student[arrLengt];

    for (int i = 0; i < arrLengt; i++)
    {
        cout << "Name:" << endl;
        cin >> arr[i].FirstName;
        cout << "LastName:" << endl;
        cin >> arr[i].LastName;
        cout << "Group:" << endl;
        cin >> arr[i].group;
        cout << "math:" << endl;
        cin >> arr[i].math;
        cout << "physics:" << endl;
        cin >> arr[i].physics;
    }


    fopen_s(&f, (file + ".txt").c_str(), "w+");
    //fopen_s(&binf, file.c_str(), "wb+");

    if (f == NULL) {
        puts("\n Create ERROR!");
        return;
    }

    for (int i = 0; i < arrLengt; i++)
    {
        fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
    }
    //fwrite(arr, SizeOfStudent, arrLengt, binf);
    fclose(f);
}
void ReadFile(string file)
{
    fopen_s(&f, (file + ".txt").c_str(), "r");
    if (f)
    {
        char cc[256];
        while ((fgets(cc, 256, f)) != NULL)
        {
            printf("%s", cc);
        }
    }
    fclose(f);
}
void AddToFile(string file)
{
    fopen_s(&f, (file + ".txt").c_str(), "r+");
    if (f)
    {
        char cc[256];
        while ((fgets(cc, 256, f)) != NULL)
        {
            printf("%s", cc);
        }

        Student newStud;
        cout << "Name:" << endl;
        cin >> newStud.FirstName;
        cout << "LastName:" << endl;
        cin >> newStud.LastName;
        cout << "Group:" << endl;
        cin >> newStud.group;
        cout << "math:" << endl;
        cin >> newStud.math;
        cout << "physics:" << endl;
        cin >> newStud.physics;

        //
        Student* buf = new Student[arrLengt+1];
        for (int i = 0; i < arrLengt; i++)
        {
            buf[i] = arr[i];
        }
        arrLengt++;
        buf[arrLengt-1] = newStud;
        delete[] arr;
        arr = buf;
        //

        fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", newStud.FirstName.c_str(), newStud.LastName.c_str(), newStud.group, newStud.math, newStud.physics, newStud.getAverageScore());
    }
    fclose(f);
}

void Sort(string file)
{
    fopen_s(&f, (file + "_sort.txt").c_str(), "w+");
    //fopen_s(&binf, file.c_str(), "wb+");

    if (f == NULL) {
        puts("\n Create ERROR!");
        return;
    }
    int group = 1;
    cout << "Введите группу" << endl;
    cin >> group;
    for (int i = 0; i < arrLengt; i++)
    {
        if(arr[i].group == group)
        fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
    }
    //fwrite(arr, SizeOfStudent, arrLengt, binf);
    fclose(f);
}