#include "crypt.h"
#include "unity.h"
#include "unity_fixture.h"


TEST_GROUP(BLOWFISH);

TEST_SETUP(BLOWFISH)
{
}

TEST_TEAR_DOWN(BLOWFISH)
{
}
/*128 block*/
TEST(BLOWFISH, TestBLOWFISH_ENC_128)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };
  blowfish_128(key, plan, 4, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0x24B9C5E1);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0xB06FBF71);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0x5527E5FA);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x3502EE1A);
}

TEST(BLOWFISH, TestBLOWFISH_DEC_128)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0x24B9C5E1, 0xB06FBF71, 0x5527E5FA, 0x3502EE1A};
  unsigned int key[4] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
  };
  blowfish_128(key, plan, 4, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5A);
}

/*192 block*/
TEST(BLOWFISH, TestBLOWFISH_ENC_192)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[6] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L
  };
  blowfish_128(key, plan, 5, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5E31925);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x25FE7048);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0x4254F298);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x4B71D955);
}

TEST(BLOWFISH, TestBLOWFISH_DEC_192)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5E31925, 0x25FE7048, 0x4254F298, 0x4B71D955};
  unsigned int key[6] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L
  };
  blowfish_128(key, plan, 5, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5A);
}

/*256 block*/
TEST(BLOWFISH, TestBLOWFISH_ENC_256)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  unsigned int key[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };
  blowfish_128(key, plan, 6, 1, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0x24B9C5E1);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0xB06FBF71);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0x5527E5FA);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x3502EE1A);
}

TEST(BLOWFISH, TestBLOWFISH_DEC_256)
{
  unsigned int cipher[4];
  unsigned int plan[4] = {  0x24B9C5E1, 0xB06FBF71, 0x5527E5FA, 0x3502EE1A};
  unsigned int key[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };
  blowfish_128(key, plan, 6, 0, cipher);
  TEST_ASSERT_EQUAL(0, cipher[0] != 0xA5A5A5A5);
  TEST_ASSERT_EQUAL(0, cipher[1] != 0x01234567);
  TEST_ASSERT_EQUAL(0, cipher[2] != 0xFEDCBA98);
  TEST_ASSERT_EQUAL(0, cipher[3] != 0x5A5A5A5A);
}
