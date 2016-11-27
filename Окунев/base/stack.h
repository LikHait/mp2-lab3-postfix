#ifndef __STACK_H__
#define __STACK_H__

const int START_SIZE = 50;
const int MAX_SIZE = 102400;

template <class T>
class TStack
{
    T *pMem;
    int Size;
    int top;

    void AddSize();      //увеличение размера стека
public:
    TStack();
    TStack(int s);
    ~TStack();
    bool IsEmpty();      //проверка на пустоту
    bool IsFull();       //проверка на заполненность
    void PutIn(T val);   //добавление элемента в стек
    T PutOut();          //извлечение элемента из стека
    T GetValue();        //получить значение последнего в стеке элемента без извлечения
};

template <class T>
TStack<T>::TStack()
{
    pMem = new T[START_SIZE];
    if (pMem == nullptr)
        throw("Memory allocation error");
    Size = START_SIZE;
    top = -1;
}

template <class T>
TStack<T>::TStack(int s)
{
    if (s < 1 || s > MAX_SIZE)
        throw("Invalid size of the stack");
    pMem = new T[s];
    if (pMem == nullptr)
        throw("Memory allocation error");
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
    int tmpSize = 0;
    if (Size * 2 > MAX_SIZE){
        if (Size < MAX_SIZE)
            tmpSize = MAX_SIZE;
        else
            throw("Exceeding maximum size of the stack");
    }
    else 
        tmpSize = Size * 2;
    T* tmp = new T[tmpSize];
    if (tmp == nullptr)
        throw("Memory allocation error");
    for (int i = 0; i < Size; i++)
        tmp[i] = pMem[i];
    delete[] pMem;
    pMem = tmp;
    Size = tmpSize;
}

template <class T> //пустота
bool TStack<T>::IsEmpty()
{
    return top == -1;
}

template <class T> //заполненность
bool TStack<T>::IsFull()
{
    return top == Size - 1;
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
        throw("Extraction error. The stack is empty");
    return pMem[top--];
}

template <class T> //получение значения
T TStack<T>::GetValue()
{
    if (IsEmpty())
        throw("Extraction error. The stack is empty");
    return pMem[top];
}

#endif
