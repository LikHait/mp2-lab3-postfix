#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, cant_create_too_large_stack)
{
  ASSERT_ANY_THROW(TStack<int> s(102401));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> s(-1));
}

TEST(TStack, can_check_is_full_false)
{
  TStack<int> s(5);
  EXPECT_EQ(0, s.IsFull());
}

TEST(TStack, can_add_element)
{
  TStack<int> s(5);
  ASSERT_NO_THROW(s.PutIn(1));
}

TEST(TStack, can_check_is_full_true)
{
  TStack<int> s(5);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  EXPECT_EQ(1, s.IsFull());
}

TEST(TStack, can_check_is_empty_true)
{
  TStack<int> s(5);
  EXPECT_EQ(1, s.IsEmpty());
}

TEST(TStack, can_check_is_empty_false)
{
  TStack<int> s(5);
  s.PutIn(1);
  EXPECT_EQ(0, s.IsEmpty());
}

TEST(TStack, can_extract_element)
{
  TStack<int> s(5);
  s.PutIn(1);
  ASSERT_NO_THROW(s.PutOut());
}

TEST(TStack, after_extract_all_element_stack_is_empty)
{
  TStack<int> s(5);
  s.PutIn(1);
  s.PutOut();
  EXPECT_EQ(1, s.IsEmpty());
}

TEST(TStack, stack_can_add_lenght)
{
  TStack<int> s(5);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(5);
  EXPECT_EQ(0, s.IsFull());
}

TEST(TStack, stack_can_add_lenght_2)
{
  TStack<int> s(5);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(1);
  s.PutIn(5);
  EXPECT_EQ(5, s.PutOut());
}
