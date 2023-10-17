#include <iostream>
using namespace std;

//Задание 1. Дополните свою библиотеку функций реализациями нижеследующих функций:

int mystrcmp(const char* str1, const char* str2);//— функция сравнивает две строки, и, если строки равны
                                                 //возвращает 0, если первая строка больше второй, то
                                                 //возвращает 1, иначе –1.
int StringToNumber(char* str1);                  //— функция конвертирует строку в число и возвращает это число.
char* NumberToString(int number);                // — функция конвертирует число в строку и возвращает указатель на эту строку.
char* Uppercase(char* str4);                     //— функция преобразует строку в верхний регистр.
char* Lowercase(char* str4);                    // — функция преобразует строку в нижний регистр
char* mystrrev(char* str5);                     // — функция реверсирует строку и возвращает указатель на новую строку.

int main() {

    int choice;
    int i = 6;
    while (i<=6) {
        cout << "\n\nChoose an option:\n";
        cout << "1. Compare two strings\n";
        cout << "2. Convert a string to a number\n";
        cout << "3. Convert a number to a string\n";
        cout << "4. Convert a string to uppercase\n";
        cout << "5. Convert a string to lowercase\n";
        cout << "6. Reverse a string\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n\n";

        switch (choice) {
        case 1: {
            char str1[25];
            char str2[25];
            cout << "Enter first string: ";
            cin >> str1;
            cout << "Enter second string: ";
            cin >> str2;
            int result = mystrcmp(str1, str2);
            if (result == 0) {
                cout << "1st string = 2nd string\n";
            }
            else if (result < 0) {
                cout << "1st string < 2nd string\n";
            }
            else {
                cout << "1st string > 2nd string\n";
            }
            break;
        }
        case 2: {
            char str1[25];
            cout << "Enter a string to convert to a number: ";
            cin >> str1;
            int result = StringToNumber(str1);
            if (result != 0) {
                cout << "Converted number: " << result << endl;
            }
            else {
                cout << "Error\n";
            }
            break;
        }
        case 3: {
            int number;
            cout << "Enter a number to convert to a string: ";
            cin >> number;
            char* str3 = NumberToString(number);
            cout << "Converted string: " << str3 << endl;
            delete[] str3;
            break;
        }
        case 4: {
            char str4[25];
            cout << "Enter a string to convert to uppercase: ";
            cin >> str4;
            char* capitalized = Uppercase(str4);
            cout << "Capitalized text: " << capitalized << endl;
            break;
        }
        case 5: {
            char str4[25];
            cout << "Enter a string to convert to lowercase: ";
            cin >> str4;
            char* lowercased = Lowercase(str4);
            cout << "Lowercased text: " << lowercased << endl;
            break;
        }
        case 6: {
            char str5[25];
            cout << "Enter a string to reverse: ";
            cin >> str5;
            char* reversedStr = mystrrev(str5);
            cout << "Reversed line: " << reversedStr << endl;
            break;
        }
        case 0:
            return 0;
        default:
            cout << "Try again.\n";
        }
    }
}


int mystrcmp(const char* str1, const char* str2) {

    int count1 = 0;
    int count2 = 0;
    for (int i = 0; str1[i] != '\0'; i++) {

        count1++;
    }

    for (int i = 0; str2[i] != '\0'; i++) {

        count2++;
    }

    if (count1 < count2) {
        return -1;
    }
    else if (count1 > count2) {
        return 1;
    }

    return 0;
}



int StringToNumber(char* str1) {

    int len = 0;

    for (int i = 0; str1[i] != '\0'; i++)
    {
        len++;
    }


    if (len > 0 && str1[len - 1] == '\n') {//fgets в C считывает символ новой строки ('\n') и мы что 
        str1[len - 1] = '\0';              //бы конвертировать символы в число убираем его так как он не являеться цифрой
    }


    int result = 0;
    int sign = 1;


    if (*str1 == '-') {//проверяем является ли число позитивным
        sign = -1;
        str1++;//ели число негативное то начинаем конвертацию в число со 2 индекса
    }

    for (int i = 0; str1[i] != '\0'; i++) {

        if (str1[i] >= '0' && str1[i] <= '9') {//поверяем являеться символ в диапазоне от 0 до 9

            result = result * 10 + (str1[i] - '0');//(str1[i] - '0')- ввычитаем и находим разницу между юникод символами, что бы получить число 
            //умножая на *10 мы сдвигаем десяток что бы перейти к следущему числу
        }
        else {

            return 0;//если буду найдены символы которые не являються числом функция вернет 0, в main() пропишеться ошибка
        }
    }
    return result * sign;//если число отрицательное присваеваем ему знак 
}



char* NumberToString(int number) {

    int maxDigits = 12;  //примерная длина строки 
    char* str = new char[maxDigits];


    int pos = 0;//текущий индекс

    if (number < 0) {// если число отрицательное то добавляем знак минус

        str[pos] = '-';
        number = -number;
        pos++;
    }

    // Определяем длину числа
    int length = 1;
    int temp = number;
    while (temp >= 10) {//как толлько число приделение становиться меньше 10 то цикл прекращаеться( то есть с десятков мы переходим на единицы)

        temp /= 10;
        length++;
    }

    // Преобразуем число в строку, начиная с конца
    for (int i = pos + length - 1; i >= pos; i--) {

        str[i] = '0' + (number % 10);//с помощбью юникода преобразуем числа в символы 
        //('0' равен 48 отнимая от него число мы получаем код нужного символа)
        number /= 10;
    }

    str[pos + length] = '\0';// добавляем нуль-терминатор

    return str;
}


char* Uppercase(char* str4) {

    for (int i = 0; str4[i] != '\0'; i++)
    {
        if (str4[i] >= 'a' && str4[i] <= 'z') {
            // Преобразуем строчную букву в верхний регистр
            str4[i] = char(str4[i] - ('a' - 'A'));// находим разницу между большой и маленькой буквой в юникоде и отнемаем его 
        }                                        //от значения и получаем большую букву
    }

    return str4;

}


char* Lowercase(char* str4) {

    for (int i = 0; str4[i] != '\0'; i++)
    {
        if (str4[i] >= 'A' && str4[i] <= 'Z') {

            str4[i] = char(str4[i] + ('a' - 'A'));
        }

    }
    return str4;
}


char* mystrrev(char* str5) {
    int length = 0;
    while (str5[length] != '\0') {//определяем длину строки
        length++;
    }

    char* reversedStr = new char[length + 1]; // создаем новую строку для результата 

    for (int i = 0; i < length; i++) {

        reversedStr[i] = str5[length - i - 1]; // копируем символы в обратном порядке
    }

    reversedStr[length] = '\0';

    return reversedStr;
}
