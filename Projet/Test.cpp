#include <gtest/gtest.h>
#include "FileTest.h"
#include "ListeTest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}