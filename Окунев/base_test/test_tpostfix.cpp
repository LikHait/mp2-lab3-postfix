#include "postfix.h"
#include "postfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
    string str = "a+b";
    TPostfix postfix;
    ASSERT_NO_THROW(postfix = str);
}

TEST(TPostfix, can_not_create_postfix_without_operands)
{
    string str = "+*";
    TPostfix postfix;
    ASSERT_ANY_THROW(postfix = str);
}

TEST(TPostfix, can_return_infix)
{
    string str = "a+b*c";
    TPostfix postfix;
    postfix = str;
    EXPECT_EQ(postfix.GetInfix(), str);
}

TEST(TPostfix, can_return_postfix)
{
    string str = "a+b*c";
    TPostfix postfix;
    postfix = str;
    EXPECT_EQ(postfix.GetPostfix(), "a b c * + ");
}

TEST(TPostfix, can_calculate)
{
    string str = "3.14+65*12-36";
    TPostfix postfix;
    postfix = str;
    EXPECT_EQ(postfix.Calculate(), 747.14);
}

TEST(TPostfix, can_not_use_invalid_combination)
{
    string str = "a+*7";
    TPostfix postfix;
    ASSERT_ANY_THROW(postfix = str);
}

TEST(TPostfix, can_not_use_invalid_combination_2)
{
    string str = "a+)7";
    TPostfix postfix;
    ASSERT_ANY_THROW(postfix = str);
}

TEST(TPostfix, can_not_use_invalid_combination_3)
{
    string str = "a+-7";
    TPostfix postfix;
    ASSERT_ANY_THROW(postfix = str);
}

TEST(TPostfix, can_calculate_function)
{
    string str = "sqrt(9+7)";
    TPostfix postfix;
    postfix = str;
    EXPECT_EQ(postfix.Calculate(), 4);
}
