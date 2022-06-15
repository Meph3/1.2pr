#include <iostream>
#include <cmath>
#include "Queue.cpp"

DataType input_term(double, double);
void Go(Abstrack_Queue*);
int main(int argc, const char* argv[]) {//меню 
    setlocale(LC_ALL, "Russian");
    char menu;
    puts("1. Vector implementation");
    puts("2. List implementation");
    menu = getchar();

    while (!(menu == '1' || menu == '2'))//выбор структур
    {
        puts("1. Vector implementation");
        puts("2. List implementation");
        menu = getchar();
    }
    switch (menu)
    {
    case '1':// 
    {
        Abstrack_Queue* p;
        Queue_Mas object;
        p = &object;
        Go(p);
        break;
    }
    case '2'://
    {
        Abstrack_Queue* p;
        Queue_List object;
        p = &object;
        Go(p);
    }
    }
    return 0;
}
DataType input_term(double factor, double rate) {//обьявление переменных
    DataType data = DataType();
    data.factor = factor;
    data.rate = rate;
    return data;
};

void Go(Abstrack_Queue* queue) {//запись и считывание многочлена
    char str[80] = "", temp[10] = "";
    int i = 0, j = 0, count = 0;
    double factor = 0, rate = 999999;
    cout << "Введите многочлен: ";
    cin >> str;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 48 && str[i] <= 57 || str[i] == 43 || str[i] == 45) {//считывание число до х, затем считывается до знака(+-*:)
            temp[j++] = str[i];
        }
        if (str[i] == 'x') {
            factor = atof(temp);
            while (j > 0) {
                temp[j--] = '\0';
            }
            i++;
        }
        if (str[i + 1] == 43 || str[i + 1] == 45 || str[i + 1] == '\0') {//проверка на правельность многочлена
            if (atof(temp) >= rate) {
                cout << "Неверно введен многочлен" << endl;
                return;
            }
            else {
                rate = atof(temp);
                while (j > 0) {
                    temp[j--] = '\0';
                }
                cout << factor << "x^" << rate << endl;//вывод многочлена
                queue->EnQueue(input_term(factor, rate));
                count++;
            }
        }
    }
    int menu;
    DataType k;// диффиринциация 
    do {
        cout << "Дифферинцируем?" << endl;
        cout << "1.Да" << endl;
        cout << "2.Нет" << endl;
        cin >> menu;
        switch (menu) {
        case 1:
            for (i = 0; i < count; i++) {
                k = queue->DeQueue();
                if (k.factor != 0) {//само действие диффиринцирования 
                    k.factor *= k.rate;
                    k.rate--;
                    if (k.factor == 0) {// удаление последнего элемента, если он 0
                        cout << k.factor;
                        count--;
                    }
                    else if (k.rate == 0) {//вывод x только с коэффициентом
                        cout << k.factor;
                    }
                    else {
                        cout << k.factor << "x^" << k.rate;//вывод х с  коэффициентом и степенью
                    }
                    if (count - 1 != i && k.factor != 0)//удаление +, если последний был 0
                    {
                        cout << "+";
                    }
                    if (k.factor != 0) {
                        queue->EnQueue(input_term(k.factor, k.rate));
                    }
                }
            }
            cout << endl;
            break;
        }
    } while (menu != 2);
};