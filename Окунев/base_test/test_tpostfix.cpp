#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
    string str = "a+b";
    TPostfix postfix;
    postfix = str;
    ASSERT_NO_THROW();
}

