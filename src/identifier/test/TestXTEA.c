#include "xtea.h"
#include "unity.h"
#include "unity_fixture.h"


TEST_GROUP(XTEA);

TEST_SETUP(XTEA)
{
}

TEST_TEAR_DOWN(XTEA)
{
}

TEST(XTEA, XTEA_ENC)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };
  unsigned int* d[4];
  const unsigned int* v[4];
  const unsigned int* k[4];

  for(int i = 0; i < 4; i++) {
    d[i] = &cipher[3-i];
    v[i] = &plan[3-i];
    k[i] = &key[3-i];
  }
  xtea_enc(d, v, k);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0x089975E9);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x2555F334);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xCE76E4F2);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x4D932AB3);
}

TEST(XTEA, XTEA_DEC)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0x089975E9, 0x2555F334, 0xCE76E4F2, 0x4D932AB3};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };

  unsigned int* d[4];
  const unsigned int* v[4];
  const unsigned int* k[4];

  for(int i = 0; i < 4; i++) {
    d[i] = &cipher[3-i];
    v[i] = &plan[3-i];
    k[i] = &key[3-i];
  }
  xtea_dec(d, v, k);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5L);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567L);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98L);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5AL);
}

TEST(XTEA, XTEA_CALL_ENC)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };
  xtea(key, plan, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0x089975E9);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x2555F334);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xCE76E4F2);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x4D932AB3);
}

TEST(XTEA, XTEA_CALL_DEC)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0x089975E9, 0x2555F334, 0xCE76E4F2, 0x4D932AB3};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };

  xtea(key, plan, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5L);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567L);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98L);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5AL);
}
