#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(CRYPT)
{
  RUN_TEST_CASE(CRYPT, CRYPT_XTEA_CALL_ENC);
  RUN_TEST_CASE(CRYPT, CRYPT_XTEA_CALL_DEC);

  RUN_TEST_CASE(CRYPT, CRYPT_TestAES_ENC_128);
  RUN_TEST_CASE(CRYPT, CRYPT_TestAES_DEC_128);
  RUN_TEST_CASE(CRYPT, CRYPT_TestAES_ENC_192);
  RUN_TEST_CASE(CRYPT, CRYPT_TestAES_DEC_192);
  RUN_TEST_CASE(CRYPT, CRYPT_TestAES_ENC_256);
  RUN_TEST_CASE(CRYPT, CRYPT_TestAES_DEC_256);

  RUN_TEST_CASE(CRYPT, CRYPT_TestBLOWFISH_ENC_128);
  RUN_TEST_CASE(CRYPT, CRYPT_TestBLOWFISH_DEC_128);
  RUN_TEST_CASE(CRYPT, CRYPT_TestBLOWFISH_ENC_192);
  RUN_TEST_CASE(CRYPT, CRYPT_TestBLOWFISH_DEC_192);
  RUN_TEST_CASE(CRYPT, CRYPT_TestBLOWFISH_ENC_256);
  RUN_TEST_CASE(CRYPT, CRYPT_TestBLOWFISH_DEC_256);
}