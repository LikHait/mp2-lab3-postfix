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
