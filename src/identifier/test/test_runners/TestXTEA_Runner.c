#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(XTEA)
{
  RUN_TEST_CASE(XTEA, XTEA_ENC);
  RUN_TEST_CASE(XTEA, XTEA_DEC);
  RUN_TEST_CASE(XTEA, XTEA_CALL_ENC);
  RUN_TEST_CASE(XTEA, XTEA_CALL_DEC);
}
