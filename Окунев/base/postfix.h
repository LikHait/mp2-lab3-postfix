#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <vector>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
  vector<string> OpTable;

  //служебные методы
  bool IsCorrect(string &str);  //проверка на корректность введённой строки
  void ToOpTable(string &str);
  void ToStack(TStack<string> &stack, string &str); //работа со стеком операций
  void ToPostfix();
  int TheTable(const string &str, int IsNeed); //таблица операций, их приоритетов, количество операндов
public:
  TPostfix();
  TPostfix(string &str);
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
