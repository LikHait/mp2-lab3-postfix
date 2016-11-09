﻿#ifndef __STACK_H__
#define __STACK_H__

const int START_SIZE = 50;
const int MAX_SIZE = 100000;

template <class T>
class TStack
{
    T *pMem;
    int Size;
    int top;

    void AddSize();      //увеличение размера стека
    bool IsEmpty();      //проверка на пустоту
    bool IsFull();       //проверка на заполненность
public:
    TStack();
    TStack(int s);
    ~TStack;
    void PutIn(T val);   //добавление элемента в стек
    T PutOut();          //извлечение элемента из стека
};

template <class T>
TStack<T>::TStack()
{
    pMem = net T[START_SIZE];
    if (pMem == nullptr)
        throw('Memory allocation error');
    Size = START_SIZE;
    top = -1;
}

template <class T>
TStack<T>::TStack(int s)
{
    pMem = net T[s];
    if (pMem == nullptr)
        throw('Memory allocation error');
    Size = s;
    top = -1;
}

template <class T>
TStack<T>::~TStack()
{
    delete[] pMem;
}

template <class T>
void TStack<T>::AddSize()
{
    T tmp = new T[Size * 2];
    if (tmp == nullptr)
        throw('Memory allocation error');
    for (int i = 0; i < Size; i++)
        tmp[i] = pMem[i];
    delete[] pMem;
    pMem = tmp;
    Size = Size * 2;
}

template <class T> //пустота
bool TStack<T>::IsEmpty()
{
    return top == -1;
}

template <class T> //заполненность
bool TStack<T>::IsFull()
{
    return top == Sise - 1;
}

template <class T> //добавление
void TStack<T>::PutIn(T val)
{
    if (IsFull() )
        AddSize();
    pMem[++top] = val;
}

template <class T> //извлечение
T TStack<T>::PutOut()
{
    if (IsEmpty() )
        throw('Extraction error. The stack is empty');
    return pMem[top--];
}

#endif
