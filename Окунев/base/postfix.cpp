#include "postfix.h"
#include "stack.h"

const int OPER_IN_ALL = 6; //всего операций
const int PROH_ALL = 25; //всего проверок

bool TPostfix::IsCorrect(string &str) 
{
    if (!(str[0] == 40 || str[0] == 41 || 65 <= str[0] <= 90 || 97 <= str[0] <= 122)) // '(' ')' 'A'-'Z' 'a'-'z' 
        return 0;
    int a = str.length - 1;
    if (!(str[a] == 40 || str[a] == 41 || 65 <= str[a] <= 90 || 97 <= str[a] <= 122))
        return 0;
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
    string proh[PROH_ALL];
    proh[0] = "(+";
    proh[1] = "(-";
    proh[2] = "(*";
    proh[3] = "(/";
    proh[4] = "()";
    proh[5] = "++";
    proh[6] = "+-";
    proh[7] = "+*";
    proh[8] = "+/";
    proh[9] = "+)";
    proh[10] = "-+";
    proh[11] = "--";
    proh[12] = "-*";
    proh[13] = "-/";
    proh[14] = "-)";
    proh[15] = "*+";
    proh[16] = "*-";
    proh[17] = "**";
    proh[18] = "*/";
    proh[19] = "*)";
    proh[20] = "/+";
    proh[21] = "/-";
    proh[22] = "/*";
    proh[23] = "//";
    proh[24] = "/)";
    for (int i = 0; i < PROH_ALL; i++)
        if (str.find(proh[i]) != -1)
            return 0;
    return 1;
}

int TPostfix::TheTable(const string &str, int IsNeed) { 
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

void TPostfix::ToOpTable(string &str)
{
}

void TPostfix::ToStack(TStack<string> &stack, string &str) //стек операций
{
    if (str == "(")
        stack.PutIn(str);
    if (stack.IsEmpty() == 1)
    {
        stack.PutIn(str);
        return;
    }
    string LastOp = stack.GetValue();
    if (TheTable(str, 1) <= TheTable(LastOp, 1))
        while (TheTable(str, 1) <= TheTable(LastOp, 1))
        {
            postfix = postfix + LastOp + " ";
            LastOp = stack.GetValue();
        }
    else
    {
        stack.PutIn(str);
        return;
    }
    if (str == ")")
    {
        while (LastOp != "(")
        {
            postfix = postfix + LastOp + " ";
            LastOp = stack.GetValue();
        }
    }
}

void TPostfix::ToPostfix()
{
    TStack<string> stack;
    string str, tmp;
    for (int i = 0; i < infix.length; i++)
    {
        tmp = infix[i];
        if (TheTable(str, 0) == 1)
        {
            ToStack(stack, str);
            str.clear;
        }
        if (TheTable(tmp, 0) == 1)
        {
            ToStack(stack, tmp);
            ToOpTable(str);
            postfix = postfix + str + " ";
            str.clear;
        }
        else
            str = str + tmp;
        tmp.clear;
    }
}

double TPostfix::Calculate()
{
  return 0;
}
