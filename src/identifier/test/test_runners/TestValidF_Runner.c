#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ValidF)
{
  RUN_TEST_CASE(ValidF, TestValidF1);
  RUN_TEST_CASE(ValidF, TestValidF2);
}
