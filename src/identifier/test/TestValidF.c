#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ValidF);

TEST_SETUP(ValidF)
{
}

TEST_TEAR_DOWN(ValidF)
{
}

TEST(ValidF, TestValidF1)
{
  TEST_ASSERT_EQUAL(1, valid_f('a'));
  TEST_ASSERT_EQUAL(1, valid_f('Z'));
  TEST_ASSERT_EQUAL(1, valid_f('1'));
  TEST_ASSERT_EQUAL(1, valid_f('9'));
}

TEST(ValidF, TestValidF2)
{
  TEST_ASSERT_EQUAL(0, valid_f('.'));
  TEST_ASSERT_EQUAL(0, valid_f('~'));
}
