#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
  bool IsCorrect(string &str) { return 1; };
  void ToPostfix();
  int TheTable(const string &str, int IsNeed);
public:
  TPostfix(string &str);
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
