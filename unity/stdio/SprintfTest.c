#include "unity_fixture.h"
#include <stdio.h>
#include <memory.h>

TEST_GROUP(sprintf);

TEST_SETUP(sprintf)
{
}

TEST_TEAR_DOWN(sprintf)
{
}

TEST(sprintf, NoFormatOperations)
{
    char output[5] = "";

    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}

TEST(sprintf, NoFormatOperations2)
{
    char output[20] = "";

    LONGS_EQUAL(12, sprintf(output, "%s\n", "Hello World"));
    STRCMP_EQUAL("Hello World\n", output);
}
