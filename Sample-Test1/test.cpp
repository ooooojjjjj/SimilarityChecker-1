#include "pch.h"
#include "../TDD_StringSimilarityChecker/StringSimilarityChecker.cpp"
#include <string>

using namespace std;

class StringSimilarityCheckerFixture : public testing::Test
{
public:
    StringSmilarityChecker cChecker;
};

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoString1)
{
    EXPECT_THROW(cChecker.GetTotalPoint("", "QWER"), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoString2)
{
    EXPECT_THROW(cChecker.GetTotalPoint("ASDF", ""), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoStrings)
{
    EXPECT_THROW(cChecker.GetTotalPoint("", ""), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoCaptial1)
{
    EXPECT_THROW(cChecker.GetTotalPoint("asdf", "ASDF"), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoCaptial2)
{
    EXPECT_THROW(cChecker.GetTotalPoint("ASDF", "asdf"), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoCaptials)
{
    EXPECT_THROW(cChecker.GetTotalPoint("asdf", "asdf"), invalid_argument);
}
TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_1)
{
    EXPECT_EQ(60, cChecker.GetLengthPoint("ASDF", "QWER"));
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_2)
{
    EXPECT_EQ(45, cChecker.GetLengthPoint("ASDFE", "QWER"));
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_3)
{
    EXPECT_EQ(45, cChecker.GetLengthPoint("ASDF", "QWERT"));
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_4)
{
    EXPECT_EQ(0, cChecker.GetLengthPoint("ASDF", "QWERTYQWERTY"));
}

