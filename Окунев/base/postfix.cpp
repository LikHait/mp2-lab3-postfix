#include "postfix.h"
#include "stack.h"

const int OPER_IN_ALL = 6;

int TheTable(const string &str, int IsNeed) { 
	/* Таблица операций
	IsNeed =	0 - является ли переименной, 1 - приоритет, 2 - количество переменных	*/
	string TOperations[OPER_IN_ALL]; //операции
	TOperations[0] = '+';	
	TOperations[1] = '-';
	TOperations[2] = '*';
	TOperations[3] = '/';
	TOperations[4] = '(';
	TOperations[5] = ')';

	int TPriority[OPER_IN_ALL];		//приоритет
	TPriority[0] = 1;
	TPriority[1] = 1;
	TPriority[2] = 2;
	TPriority[3] = 2;
	TPriority[4] = 0;

	int TNumberOfOperands[OPER_IN_ALL];
	TPriority[0] = 2;
	TPriority[1] = 2;
	TPriority[2] = 2;
	TPriority[3] = 2;

	switch ( IsNeed )
	{
		case '0':  
			for (int i = 0; i < OPER_IN_ALL; i++)
				if (str == TOperations[i])
					return 1;
			return 0;
			break;
		case '1':
			for (int i = 0; i < OPER_IN_ALL; i++)
				if (str == TOperations[i])
					return TPriority[i];
			return -1;			//не является операцией
			break;
		case '2':
			for (int i = 0; i < OPER_IN_ALL; i++)
				if (str == TOperations[i])
					return TNumberOfOperands[i];
			break;
		default:
			throw("Invalid second variable in the function TheTable"); //assert???
	}
}

TPostfix::TPostfix(string &str) {
	if (!IsCorrect(str))
		throw("String is not correct");
	infix = str;
	ToPostfix();
}

void TPostfix::ToPostfix()
{
}

double TPostfix::Calculate()
{
  return 0;
}
