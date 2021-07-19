#include "CppUTest/CommandLineTestRunner.h"

int main()
{
    const int argc = 2;
    const char* argv[] = {"", "-gLedDriver"};
    return RUN_ALL_TESTS(argc, argv);
}
