#include <iostream>
#include <string>
using namespace std;

//Задача.Данный текстовый файл.Необходимо создать новый файл и записать в него следующую статистику по исходному файлу :
//■ Количество символов;
//■ Количество строк;
//■ Количество гласных;
//■ Количество согласных;
//■ Количество цифр.

void counter(char ch, int& numcharacters, int& numLines, int& numVowels, 
    int& numConsonants, int& numDigits) {
    numcharacters++;

    if (numLines == 0) {
        numLines++;
    }
    if (ch == '\n')
    {
        numLines++;
    }

    bool checkConsonants = true;
    char vowels[] = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y' };
    for (char _ch : vowels) {
        if (ch == _ch)
        {
            numVowels++;
            break;
        }
    }

    if (checkConsonants)
    {
        numConsonants++;
    }

    if ((int)ch > 47 && (int)ch < 58)
    {
        numDigits++;
    }
}

void getRsult(char *str, int& numcharacters, int& numLines, int& numVowels,
    int& numConsonants, int& numDigits) {
}

int main()
{
    
    std::cout << "Hello World!\n";
    int numcharacters=0, numLines=0, numVowels=0, numConsonants=0, numDigits=0;


    FILE* pf;
    fopen_s(&pf, "some_file.txt", "rt");
    if (pf != nullptr)
    {
        //считывание файла посимвольно
        char ch;
        while ((ch = fgetc(pf)) != EOF)
        {
            counter(ch, numcharacters, numLines, numVowels, numConsonants, numDigits);
        }

        fclose(pf);
        cout << "file readed" << endl;
    }
    else {
        cout << "error read file" << endl;
    }

    FILE* pfw;
    fopen_s(&pfw, "some_other_file.txt", "wt");
    if (pfw != nullptr)
    {
        string str = "numcharacters=" + to_string(numcharacters) + '\n' +
            "numLines=" + to_string(numLines) + '\n' +
            "numVowels=" + to_string(numVowels) + '\n' +
            "numConsonants" + to_string(numConsonants) + '\n' +
            "numDigits" + to_string(numDigits) + '\n';
        fputs(str.c_str(), pfw);
    }
    else {
        cout << "error write file" << endl;
    }
}