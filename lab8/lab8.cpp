#include <iostream>
#include <string>
#include <stdio.h>
#include <io.h>

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
void EditFile(string file);
void Sort(string Sortedfile);

int SizeOfStudent = sizeof(Student);
Student* arr;

FILE* f;
FILE* binf;

int main()
{
    setlocale(LC_ALL, "ru");
    
    while (true) 
    {
        cout << "\n1-создание; 2-чтение; 3 -добавить; 4 -изменить; 5 -сортировка" << endl;
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
            EditFile("\Zap1");
            break;
        case 5:
            Sort("\Zap1");
        default:
            break;
        }
    }
    return 0;
}

void CreateFile(string file)
{
    int arrLength;
    cout << "Сколько студентов добавить в файл?" << endl;
    cin >> arrLength;

    arr = new Student[arrLength];

    for (int i = 0; i < arrLength; i++)
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
    fopen_s(&binf, file.c_str(), "wb+");

    if (f == NULL && binf == NULL) {
        puts("\n Create ERROR!");
        return;
    }

    for (int i = 0; i < arrLength; i++)
    {
        fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
    }
    fwrite(arr, SizeOfStudent, arrLength, binf);
    fclose(f);
    fclose(binf);
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
    ReadFile("\Zap1");
    // Вывод пердыдущих дынных.

#pragma region ReadBIN
        fopen_s(&binf, file.c_str(), "rb+");
        int arrLength = (_filelength(_fileno(binf)) / SizeOfStudent);
        fread(arr, SizeOfStudent, arrLength, binf);
        fclose(binf);
#pragma endregion

    fopen_s(&binf, file.c_str(), "wb+");

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

        

    //заполнение нового студента
        fwrite(arr, SizeOfStudent, arrLength, binf); //запись нового студента в бинарный файл
        fwrite(&newStud, SizeOfStudent, 1, binf);
        fopen_s(&f, (file + ".txt").c_str(), "w+");
        for (int i = 0; i < arrLength; i++)
        {
            fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
        }

        fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", newStud.FirstName.c_str(), newStud.LastName.c_str(), newStud.group, newStud.math, newStud.physics, newStud.getAverageScore());
        //запись нового студента в текстовый файл
    fclose(f);
    fclose(binf);
}
void EditFile(string file)
{
#pragma region ReadBIN

    fopen_s(&binf, file.c_str(), "rb+");
    if (binf == NULL) {
        puts("\n ERROR!");
        return;
    }

    int arrLength = _filelength(_fileno(binf)) / SizeOfStudent;
    arr = new Student[arrLength];
    fread(arr, SizeOfStudent, arrLength, binf);

    cout << "\n\n\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "студент номер "<< i << endl << endl;
        cout << "Name: "<< arr[i].FirstName << endl;
        cout << "LastName: "<< arr[i].LastName << endl;
        cout << "Group :"<< arr[i].group << endl;
        cout << "math: "<< arr[i].math << endl;
        cout << "physics: "<< arr[i].physics << endl;
        cout << "------------------------------" << endl;
    }
    fclose(binf);
#pragma endregion

    fopen_s(&binf, file.c_str(), "wb+");
    int n;
    cout << "Введите номер редактируемого студента" << endl;
    cin >> n;

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
    //заполнение нового студента
    arr[n] = newStud;


    fwrite(arr, SizeOfStudent, arrLength, binf); //запись нового студента в бинарный файл

    fopen_s(&f, (file + ".txt").c_str(), "w+");
    for (int i = 0; i < arrLength; i++)
    {
        fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
    }
    //запись нового студента в текстовый файл
    fclose(binf);
    fclose(f);
}


void Sort(string file)
{
#pragma region ReadBIN
    fopen_s(&binf, file.c_str(), "rb+");
    int arrLength = (_filelength(_fileno(binf)) / SizeOfStudent);
    fread(arr, SizeOfStudent, arrLength, binf);
    fclose(binf);
#pragma endregion
    fopen_s(&f, (file + "_sort.txt").c_str(), "w+");
    //fopen_s(&binf, file.c_str(), "wb+");

    double GlobaleAvrScore = 0;
    int GroupLength = 0;

    if (f == NULL) {
        puts("\n ERROR!");
        return;
    }
    int group = 1;
    cout << "Введите группу" << endl;
    cin >> group;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i].group == group) {
            GlobaleAvrScore += arr[i].getAverageScore();
            GroupLength++;
             }
    }
    GlobaleAvrScore /= GroupLength;
    for (int i = 0; i < GroupLength; i++)
    {
        if (arr[i].getAverageScore()>GlobaleAvrScore) {
            fprintf_s(f, "\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
            printf_s("\n %s , %s , %d, %d , %d , %f .\n", arr[i].FirstName.c_str(), arr[i].LastName.c_str(), arr[i].group, arr[i].math, arr[i].physics, arr[i].getAverageScore());
        }
    }
    fclose(f);
}

