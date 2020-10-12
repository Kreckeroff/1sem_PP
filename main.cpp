//
//  main.cpp
//  1day
//
//  Created by Egor Grebennikov on 20.09.2020.
//  Copyright © 2020 Egor Grebennikov. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void sort(char *i, int n) {
    int a, b;
    char t;
    for(a=0; a < n; a++)
        for(b=n-1; b >= a; b--) {
            if(i[b-1] > i[b]) {
                t = i[b-1];
                i[b-1] = i[b];
                i[b] = t;
                
            }
            
        }
    
}

int Inputint(int m, int M) {
    for (;;) {
        float valuea;
        std::cout<<"Введите число. \n";
        if ((std::cin >> valuea).good() && (m <= valuea) && (valuea <= M)&&(floor(valuea)==valuea)){
            return valuea;
            break;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите. \n";
            
        }
        else {
            std::cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
            
        }
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    }
}
double Inputfloat(int m, int M) {
    for (;;) {
        float valuea;
        cout<<"Введите число. \n";
        if ((cin >> valuea).good() && (m <= valuea) && (valuea <= M)){
            return valuea;
            break;
        }
        if (cin.fail()) {
            cin.clear();
            cout << "Неверный ввод, повторите. \n";
            
        }
        else {
            cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
            
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    }
}

void day1() {
    bool a = true;
    int m = 0;
    int M = 5;
    cin.clear();
    do {
        cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
        cout << endl;
        cout << "№1 - задание \"Имя\"\n";
        cout << "№2 - задание \"Арифметика\" \n";
        cout << "№3 - задание \"Уравнение\" \n";
        cout << "№4 - задание \"Ещё уравнение\" \n";
        cout << "№5 - задание \"Лампа со шторой\" \n\n";
        cout << "№0 - выйти из программы \n";
        int t = Inputint(m,M);
        switch(t){
            case 1:{
                cout <<"Данная программа спрашивает имя пользователя и выводит его на экран. \n";
                setlocale(LC_ALL, "Russian");
                string name;
                cout << "What is your name? ";
                cin>> name;
                cout << "Hello, " << name << "!\n";
                break;

            }
            case 2: {
                bool f = false;
                do{
                    cout<<"Данная программа решает простые арифметические действия. \n";
                    float  c = 0;
                    char sign;
                    int m = -2147483648, M = 2147483647;
                    cout<<"Введите число a \n";
                    float a = Inputfloat(m, M);
                    cout<<"Введите число b \n";
                    float b = Inputfloat(m, M);
                    cout <<" Введите '+', чтобы посчитать a + b = c. \n Введите '-', чтобы посчитать a - b = c. \n Введите '*', чтобы посчитать a * b = c. \n Введите '+/', чтобы посчитать a / b = c. \n Напишите '0' чтобы выйти из программы в меню. \n";
                    cin >> sign;
                    try {
                        if(!(sign == '+' or sign == '-' or sign == '/' or sign == '*') and sign == 0)
                            throw 120;
                            
                    }
                    catch (int q) {
                        cout<<"Ошибка № "<<q<<"! Вы ввели неправильно знак. Вас вернут обратно в программу\n";
                        f = true;
                        continue;
                            
                    }
                    switch(sign) {
                        case'+': {
                            c = a + b;
                            cout << "a + b = " << c<<endl;
                            break;
                            
                        }
                        case'-': {
                            c = a - b;
                            cout << "a - b = " <<c<<endl;
                            break;
                            
                        }
                        case'*': {
                            c = a * b;
                            cout << "a * b = " << c<<endl;
                            break;
                                    
                        }
                        case'/': {
                            try {
                                if(b == 0)
                                    throw 121;
                                
                            } catch (int q) {
                                cout<<"Ошибка № "<<q<<"! Делить на 0 нельзя. \n";
                                break;
                                
                            }
                            c = a / b;
                            cout << "a / b = " <<c<<endl;
                            break;
                            
                        }
                        case'0': {
                            break;
                        }
                    }
                    
                }while(f);
                break;
            }
            case 3: {
                cout <<"эта программа находит значение x в уравнениях типа bx + c = 0"<<endl;
                float x = 0;
                int m = -2147483648;
                int M = 2147483647;
                cout<<"Введите число 'b' \n";
                float b = Inputfloat(m,M);
                cout<<"Введите число 'c' \n";
                float c = Inputfloat(m,M);
                try {
                    if (b == 0 and c != 0){
                        throw 130;
                        
                    }
                        
                }
                catch (int q){
                    cout<< "результат будет недействителен, "<<"Ошибка № "<<q<<" - на 0 делить нельзя!"<<endl;
                    break;
                    
                }
                if( b == 0 and c == 0){
                    cout<<"x может принимать любые значения"<<endl;
                    break;
                    
                }
                x = (-c)/b;
                cout <<"x = "<<x<<endl;
                break;
                
            }
            case 4:{
                cout<<"Данная программа находит значение x в уравнениях типа ax^2 + bx + c = 0 \n" ;
                float d,x1,x2;
                int m = -2147483648;
                int M = 2147483647;
                cout<<"Введите число 'a' \n";
                float a = Inputfloat(m,M);
                cout<<"Введите число 'b' \n";
                float b = Inputfloat(m,M);
                cout<<"Введите число 'c' \n";
                float c = Inputfloat(m,M);
                if(a == 0) {
                    try {
                        if (b == 0 and c != 0) {
                            throw 140;
                            
                        }
                        
                    }
                    catch (int q){
                        cout<< "результат будет недействителен, "<<"Ошибка № "<<q<<" - на 0 делить нельзя! \n"<<endl;
                        break;
                        
                    }
                    if( b == 0 and c == 0) {
                        cout<<"x может принимать любые значения \n"<<endl;
                        break;
                        
                    }
                    x1 = (-c)/b;
                    cout <<"x1 = "<<x1<<endl;
                    break;
                    
                }
                d = pow(b,2) - 4 * a * c;
                if (d > 0) {
                    x1 = ((-b) + sqrt(d)) / (2 * a);
                    x2 = ((-b) - sqrt(d)) / (2 * a);
                    cout << "x1 = " << x1 << endl;
                    cout << "x2 = " << x2 << endl;
                        
                }
                if (d == 0) {
                    x1 = -(b / (2 * a));
                    cout << "x1 = x2 = " << x1 << endl;
                    
                }
                if (d < 0)
                    cout << "D < 0, Действительных корней не существует \n";
                break;
                
            }
            case 5: {
                int lamp;
                int sun;
                int curtain;
                cout<<"эта программа определяет светло или темно в комнате \n";
                cout << "введите первым действием работает ли лампа, вторым открыты или закрыты шторы,последним светло или темно на улице, 1 вариант ответа принимается под цифрой 1, второй под цифрой 0\n";
                cin >>lamp>>curtain>>sun;
                try {
                    if((lamp != 0 and lamp != 1) or (curtain != 0 and curtain != 1) or (sun != 0  and sun != 1))
                        throw 150;
                    
                }
                catch(int q){
                    cout<<"вы ввели неправильное значение переменных "<<"Ошибка № "<<q<<" допустим ввод только цифр 1/0"<<endl;
                    break;
                    
                }
                if (lamp == 1 or (curtain == 1 and sun == 1))
                    cout << "в комнате светло\n";
                else
                    cout << "в комнате темно\n";
                break;
                
            }
            case 0: {
                cout<<"Выход в меню \n";
                a = false;
                continue;
                
            }
                
        }
                
    }while(a);
    
}

void day2() {
    int m = 0;
    int M = 5;
    bool f = true;
    do{
        std::cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
        cout << endl;
        cout << "№1 - задание \"Конус\"\n";
        cout << "№2 - задание \"Разветвление\" \n";
        cout << "№3 - задание \"Функция\" \n";
        cout << "№4 - задание \"Порядок\" \n";
        cout << "№5 - задание \"Табуляция\" \n\n";
        cout << "№0 - выйти из программы \n";
        int t = Inputint(m,M);
        switch(t){
            case 1:{
                cout<<"Данная программа считает объем и полную поверхность усеченного конуса"<<endl;
                int m = 1, M = 2147483647;
                double V, S;
                cout<<"Введите число 'h' \n";
                float h = Inputfloat(m,M);
                cout<<"Введите число 'l' \n";
                float l = Inputfloat(m,M);
                cout<<"Введите число 'R' \n";
                float R = Inputfloat(m,M);
                cout<<"Введите число 'r' \n";
                float r = Inputfloat(m,M);
                try {
                    if(R == r)
                        throw 210;
                    if(l <= h)
                        throw 211;
                } catch (int q) {
                    if(q == 210) {
                        cout<<"ошибка, вы ввели не усеченный конус \n";
                        break;
                    }
                    if(q == 211)
                    {
                        cout<<"ошибка, вы ввели не усеченный конус \n";
                        break;
                    }
                    
                }
                V = ((1/(3 * M_PI * h))*((pow(R,2) + R * r + pow(r,2))));
                S = M_PI * (pow(R,2) + (R + r)* l + pow(r,2));
                cout <<"Объем фигуры равен: \n";
                cout << V << endl;
                cout << "полная поверхность фигуры равна: \n";
                cout << S << endl;
                break;
            }
            case 2: {
                cout<<"Данная программа считает систему уравнений \n";
                int m = -2147483648, M = 2147483647;
                float result;
                cout<<"Введите число 'a' \n";
                float a = Inputfloat(m,M);
                cout<<"Введите число 'x' \n";
                float x = Inputfloat(m,M);
                if (abs(x)< 1) {
                    if(x > 0) {
                        result = a*log(abs(x));
                        cout <<"W = "<<result<<endl;
                        break;
                            
                    }
                    else {
                        try {
                            if(x <= 0)
                                throw 220;
                                
                        }
                        catch (int q) {
                            cout<<"Ошибка № "<<q<<" логарифм не может быть отрицательным или равен 0 \n";
                            break;
                                
                        }
                        
                    }
                    
                }
                else
                    try {
                        if( a < pow(x, 2)){
                            throw 221;
                                
                        }
                            
                    }
                    catch (int q) {
                        cout<<"Ошибка № "<<q<<" под корнем не может быть отрицательное число \n"<<endl;
                        break;
                        
                }
                result = sqrt(a - pow(x, 2));
                cout << "W = ";
                cout << result << endl;
                break;
                
            }
            case 3: {
                cout<<"Данная программа находить значение 'z' в уравнение \n";
                int m = -2147483648, M = 2147483647;
                float result;
                cout<<"Введите число 'x' \n";
                float x = Inputfloat(m,M);
                cout<<"Введите число 'b' \n";
                float b = Inputfloat(m,M);
                cout<<"Введите число 'y' \n";
                float y = Inputfloat(m,M);
                try {
                    if(b <= y and b < x) {
                        throw 232;
                            }
                        
                    if(b < x ) {
                        throw 230;
                            
                    }
                    if(b <= y) {
                        throw 231;
                            
                    }
                        
                }
                catch (int q) {
                    if( q == 230)
                        cout<<"Ошибка № "<<q<< " под корнем не может быть отрицательное число"<< endl;
                    else if(q == 231)
                        cout<<"Ошибка №"<<q<<" логарифм не определен"<< endl;
                    else
                        cout<<"Ошибка № "<<q<< " под корнем не может быть отрицательное число и логарифм не определен"<< endl;
                    break;
                        
                }
                result = log(b - y) * sqrt(b - x);
                cout << "z = "<< result << endl;
                break;
                
            }
            case 4: {
                int m = 0, M = 2147483636;
                int N = Inputint(m,M);
                for(int i = 10 ; i > 0 ; i --) {
                    N++;
                    cout<< N << endl;
                            
                }
                break;
            }
            case 5: {
                float x = -4;
                float result;
                for(int i = 0; i < 17; i++) {
                    if(x - 1 != 0){
                        result =(pow(x,2) - 2 * x + 2)/(x - 1);
                        cout<< "результат для x = "<< x << endl <<"равен: "<< result<<endl<<endl;
                        
                    }
                    try {
                        if (x - 1 == 0){
                            throw 250;
                            
                        }
                        
                    }
                    catch(int q) {
                        cout <<"результат для x = 1\n"<<"Ошибка №" << q << " - на 0 делить нельзя!!!!" <<endl<<endl;
                        
                    }
                    x = x + 0.5;
                    
                }
                break;
            }
            case 0: {
                cout<<"Выход в меню \n";
                f = false;
                continue;
            }
                
        }
        
    }while(f);
    
}
void day3(){
    int m = 0;
    int M = 5;
    bool f = true;
    do{
        std::cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
        cout << endl;
        cout << "№1 - задание \"Заем\"\n";
        cout << "№2 - задание \"Ссуда\" \n";
        cout << "№3 - задание \"Копирование файла\" \n";
        cout << "№4 - задание \"Фильтр\" \n";
        cout << "№5 - задание \"Сортировка букв\" \n\n";
        cout << "№0 - выйти из программы \n";
        int t = Inputint(m,M);
        switch(t){
            case 1: {
                std::cout<<"вы выбрали №1 - задание 'Заем' \n";
                float result;
                cout<<"Введите S: \n";
                int S = Inputint(1, 2000000);
                cout<<"Введите n: \n";
                int n = Inputint(1, 2000000);
                cout<<"Введите p: \n";
                float p = Inputfloat(1, 2000000);
                result = (S*(p/100)*pow(1+(p/100), n))/(12*(pow(1+(p/100), n)-1));
                cout<<"m = "<<result<<endl;
                break;
            
            }
            case 2: {
                std::cout<<"вы выбрали №2 - задание 'Ccуда' \n";
                std::cout<<"Введите S \n";
                float S = Inputint(1, 2000000);
                std::cout<<"Введите n \n";
                float n = Inputint(1, 2000000);
                std::cout<<"Введите m \n";
                float m = Inputint(1, 2000000);
                double result = ((pow(((12 * m * n)/S),1 / n)-1)*100);
                std::cout<<"Процент p = \n"<<result<<std::endl;
                break;
            
            }
            case 3: {
                std::cout<<"вы выбрали №3 - задание 'Копирование файла' \n";
                char buff[50];
                std::string y;
                std::cout<<"Введите с клавиатуры число/слово чтобы его записать в файл \n";
                std::getline(std::cin, y);
                std::cout<<y<<std::endl;
                std::ofstream in;
                in.open("task3.3.txt");
                in << y;
                in.close();
                std::ifstream out("task3.3.txt");
                out.getline(buff,50);
                std::cout << buff;
                out.close();
                break;
            
            }
            case 4: {
                std::cout<<"вы выбрали №4 - задание 'Фильтр' \n";
                std::cout<<"Введите с клавиатуры число/слово чтобы его записать в файл \n";
                char y[50];
                std::cin>>y;
                char buff[100];
                char result [100];
                std::ofstream test;
                test.open("text.html");
                test <<y<<std::endl;
                test.close();
                std::ifstream text("text.html");
                text.getline(buff,100);
                for(int i = 0, j=0; i < 100; i++)
                    if(buff[i] != '\0')
                        result[j++] = buff[i];
                std::cout << buff<<std::endl;
                text.close();
                for (int i=0; i<100;i++){
                    if ((buff[i]>47&&buff[i]<58)||buff[i]==32)
                        std::cout<<buff[i];
                    if(buff[i] == '\0'){
                        break;
                        
                    }
                    
                }
                std::cout<<'\n';
                break;
                
            }
            case 5: {
                std::cout<<"вы выбрали №5 - задание 'Сортировка букв' \n";
                bool q = true;
                while(q){
                char s[80];
                printf("Введите строку длинной 30 символов: \n");
                cin>>s;
                unsigned long i = strlen(s);
                    if(i < 30){
                        q = false;
                        sort(s, i);
                        printf("Отсортированная строка : %s\n", s);
                        break;
                        
                    }
                    cout<<"вы ввели строку длинной не 30 символов! \n";
                    
                }
                break;
                
            }
            case 0:{
                std::cout<<"Выход в меню \n";
                f = false;
                continue;
                
            }
            default:{
                std::cout<<"Неверный ввод, попробуйте еще раз \n";
                
            }
                
        }
        
    }while(f);
    
}
void day4(){
    int m = 0;
    int M = 9;
    bool f = false;
    do{
        std::cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
        cout << endl;
        cout << "№1 - задание \"Файл\"\n";
        cout << "№2 - задание \"Знак числа\" \n";
        cout << "№3 - задание \"Геометрические фигуры\" \n";
        cout << "№4 - задание \"Былая слава\" \n";
        cout << "№5 - задание \"Синусоида\" \n\n";
        cout << "№6 - задание \"Автоматный распознаватель\" \n";
        cout << "№7 - задание \"Генератор случайных чисел\" \n";
        cout << "№8 - задание \"Умножение матриц\" \n\n";
        cout << "№9 - задание \"Системы счисления\" \n\n";
        cout << "№0 - выйти из программы \n";
        int t = Inputint(m,M);
        switch(t){
            case 1: {
                break;
            
            }
            case 2: {
                break;
            
            }
            case 3: {
                break;
            
            }
            case 4: {
                break;
            
            }
            case 5: {
                break;
            
            }
            case 6: {
                break;
            
            }
            case 7: {
                break;
            
            }
            case 8: {
                break;
                
            }
            case 9: {
                break;
                               
            }
                
        }
        
    }while(f);
    
}
    
    
int main() {
    setlocale(LC_ALL, "Russian");
    char q ;
    while(true) {
        cout << "Для просмотра заданий введите номер задания (1-5) \n \n";
        cout << "№1 - задания 1 недели \n";
        cout << "№2 - задания 2 недели \n";
        cout << "№3 - задания 3 недели \n";
        cout << "№4 - задания 4 недели \n";
        cout << "№0 - выйти из программы \n";
        cin >> q;
        switch(q) {
            case '1' : {
                day1();
                break;
            
            }
            case '2' : {
                day2();
                break;
                
            }
            case '3' : {
                day3();
                break;
            }
            case '0' : exit(0);
            default: {
                cout<<"неверный ввод"<<endl;
            
            }
            
        }
        
    }
        
}
