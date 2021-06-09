#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ValidS);

TEST_SETUP(ValidS)
{
}

TEST_TEAR_DOWN(ValidS)
{
}

TEST(ValidS, TestValidS1)
{
  TEST_ASSERT_EQUAL(1, valid_s('a'));
  TEST_ASSERT_EQUAL(1, valid_s('Z'));
}

TEST(ValidS, TestValidS2)
{
  TEST_ASSERT_EQUAL(0, valid_s('.'));
  TEST_ASSERT_EQUAL(0, valid_s('~'));
}
