#include <iostream>
#include "Queue.hpp"

using namespace std;

Queue_List::Queue_List() : Abstrack_Queue() {
    front = rear = nullptr; //обнуление указателей
}
Queue_List::~Queue_List() {
    element * temp = front;
    while (front) //удаление всех элементов
    {
          temp = front;
          front = front->next;
          delete temp;
    }
}
bool Queue_List::Empty() {
    return this->front==nullptr; //проверка на пустоту
}
bool Queue_List::Full() {
    element *temp = new (std::nothrow) element;
    if (temp==NULL) return false; //проверка на полноту
    delete temp;
    return true;
}
void Queue_List::EnQueue (DataType x) { //добавление элемента
   element * temp = new (std::nothrow) element;
   if (temp==NULL)
       return;
   temp->data = x; //присваивание значения для data
   temp->next = NULL; //обнуление указателя на след элемент
   if (this->Empty()) //проверка на пустоту
      this->front = this->rear = temp;
   else { //добавление элемента в конце
      this->rear->next = temp;
      this->rear = this->rear->next;
   }
}
DataType Queue_List::DeQueue() {
   DataType temp = this->front->data; //получение информации запроса
   element * tmp = this->front; //получение указателя на элемент
   this->front = this->front->next; //смещение указателя на след элемент
   delete tmp; //удаление указателя элемента
   return temp; //вывод информации запроса
}
DataType Queue_List::Front() {
    return this->front->data; //чтение первого элемента
}
