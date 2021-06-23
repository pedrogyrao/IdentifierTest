#include "crypt.h"
#include "unity.h"
#include "unity_fixture.h"


TEST_GROUP(AES);

TEST_SETUP(AES)
{
}

TEST_TEAR_DOWN(AES)
{
}
/*128 block*/
TEST(AES, TestAES_ENC_128)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };
  aes(key, plan, 1, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0x237549D4);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0xCDCEA7BE);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0x0FE7D162);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0xCC9161D3);
}

TEST(AES, TestAES_DEC_128)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xEBB4CD9E, 0xDA7CBDE0, 0x9E520F4C, 0x54BE5A98};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };
  aes(key, plan, 1, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xFE67E73E);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0xB109395B);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0x9C4B5367);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x05723D0D);
}

/*192 block*/
TEST(AES, TestAES_ENC_192)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[6] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L
  };
  aes(key, plan, 2, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xEBB4CD9E);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0xDA7CBDE0);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0x9E520F4C);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x54BE5A98);
}

TEST(AES, TestAES_DEC_192)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xEBB4CD9E, 0xDA7CBDE0, 0x9E520F4C, 0x54BE5A98};
  unsigned int key[6] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L
  };
  aes(key, plan, 2, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5A);
}

/*256 block*/
TEST(AES, TestAES_ENC_256)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };
  aes(key, plan, 3, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0x206BF119);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x7A085AC8);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xB31B2AD0);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x4843FFC1);
}

TEST(AES, TestAES_DEC_256)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0x206BF119, 0x7A085AC8, 0xB31B2AD0, 0x4843FFC1};
  unsigned int key[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };
  aes(key, plan, 3, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5A);
}
