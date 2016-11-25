#include "postfix.h"
#include "stack.h"

const int OPER_IN_ALL = 6; //всего операций
const int PROH_ALL = 25; //всего проверок

bool IsCorrect(string &str) 
{
    int left = 0;
    int right = 0;
    for (int i; i < str.length; i++)
    {
        if (str[i] == '(')
            left++;
        if (str[i] == ')')
            right++;
    }
    if (left != right)
        return 0;
    string proh[2][PROH_ALL];
    proh[0][0] = "(+";
    proh[0][1] = "(-";
    proh[0][2] = "(*";
    proh[0][3] = "(/";
    proh[0][4] = "()";
    proh[0][5] = "++";
    proh[0][6] = "+-";
    proh[0][7] = "+*";
    proh[0][8] = "+/";
    proh[0][9] = "+)";
    proh[0][10] = "-+";
    proh[0][11] = "--";
    proh[0][12] = "-*";
    proh[0][13] = "-/";
    proh[0][14] = "-)";
    proh[0][15] = "*+";
    proh[0][16] = "*-";
    proh[0][17] = "**";
    proh[0][18] = "*/";
    proh[0][19] = "*)";
    proh[0][20] = "/+";
    proh[0][21] = "/-";
    proh[0][22] = "/*";
    proh[0][23] = "//";
    proh[0][24] = "/)";
    for (int i = 0; i < PROH_ALL; i++)
        if (str.find(proh[0][i]) != -1)
            return 0;
    return 1;
}

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

	int TNumberOfOperands[OPER_IN_ALL]; //операнды
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
