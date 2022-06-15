#ifndef Queue_cpp
#define Queue_cpp
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct term {
    double factor;
    double rate;
} DataType;
DataType input_term();
class Abstrack_Queue { //абстрактный класс
public:
    virtual bool Empty() = 0; //проверка пустоты очереди
    virtual bool Full() = 0; //проверка на полноту очереди
    virtual void EnQueue(DataType x) = 0; //добавление элемента
    virtual DataType DeQueue() = 0; //извлечение элемента
    virtual DataType Front() = 0; //неразрушимое чтение элемента
    virtual ~Abstrack_Queue() {};
};
class Queue_List : public Abstrack_Queue { //связный список СХ
    struct element {
        DataType data;
        element *next; //указатель на следующий элемент
    } *front, *rear;
public:
    Queue_List(); //конструктор без параметров
    ~Queue_List() override; //деструктор
    bool Empty() override;
    bool Full() override;
    void EnQueue(DataType x) override;
    DataType DeQueue() override;
    DataType Front() override;
};
class Queue_Mas : public Abstrack_Queue { //векторная СХ
    int front, rear;
    int maxlength;
    DataType *data;
public:
    Queue_Mas(int n=10); //конструктор с параметром кол-ва элементов
    ~Queue_Mas() override; //деструктор
    bool Empty() override;
    bool Full() override;
    void EnQueue(DataType x) override;
    DataType DeQueue() override;
    DataType Front() override;
};
#endif /* Queue_cpp */
