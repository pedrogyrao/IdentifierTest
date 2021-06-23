#include "unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(XTEA);
  RUN_TEST_GROUP(AES);
  RUN_TEST_GROUP(BLOWFISH);
  RUN_TEST_GROUP(CRYPT);

}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
