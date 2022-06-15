#include "Queue.hpp"
#include <iostream>

using namespace std;

Queue_Mas::Queue_Mas(int n) : maxlength(n) { //конструктор без параметов
    this->data = new DataType[maxlength+1]; //создание массива данных
    this->front = 0; //постановка указателя на первый элемент
    this->rear = maxlength-1; //постановка указателя на последний элемент
}
Queue_Mas::~Queue_Mas() { //деструктор
    delete[] this->data; //удаление данных
}
bool Queue_Mas::Empty() {
    return (this->rear+1)%this->maxlength == front; //проверка пустоты
}
bool Queue_Mas::Full() {
    return (this->rear+2)%maxlength == front; //проверка полноты
}
void Queue_Mas::EnQueue(DataType x) { //добавление элемента
    if (this->Full()) return; //проверка на полноту
    this->rear = (this->rear+1)%this->maxlength; //смещение указателя на последний элемент
    this->data[this->rear] = x; //вставка данных
    return;
}
DataType Queue_Mas::DeQueue() { //вывод первого элемента данных
    int temp = this->front; //сохранение номера элемента
    this->front = (this->front+1)%this->maxlength; //смещение указателя первого элемента
    return this->data[temp]; //вывод данных
}
DataType Queue_Mas::Front() { //неразрушимое чтение 1 элемента
    return this->data[front];
}
