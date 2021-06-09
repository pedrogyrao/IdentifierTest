#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"


TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, TestIdentifier1)
{
  char string[6] = "aaaaaa";
  TEST_ASSERT_EQUAL(1, identifier(string));
  char string1[1] = "a";
  TEST_ASSERT_EQUAL(1, identifier(string1));
  char string2[6] = "AAAAAA";
  TEST_ASSERT_EQUAL(1, identifier(string2));
  char string3[1] = "A";
  TEST_ASSERT_EQUAL(1, identifier(string3));
  char string4[6] = "a1a1a1";
  TEST_ASSERT_EQUAL(1, identifier(string4));
  char string5[2] = "a1";
  TEST_ASSERT_EQUAL(1, identifier(string5));
}

TEST(Identifier, TestIdentifier2)
{
  char string[6] = "111111";
  TEST_ASSERT_EQUAL(0, identifier(string));
  char string1[1] = "1";
  TEST_ASSERT_EQUAL(0, identifier(string1));
  char string2[7] = "aaaaaaa";
  TEST_ASSERT_EQUAL(0, identifier(string2));
}
