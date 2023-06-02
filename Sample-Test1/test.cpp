#include "pch.h"
#include "../TDD_StringSimilarityChecker/StringSimilarityChecker.cpp"
#include <string>

using namespace std;

TEST(TestCaseName, GetTotalPoint_NoString1) 
{
    StringSmilarityChecker cChecker;

    string sString1 = "";
    string sString2 = "qwer";
    
    EXPECT_THROW(cChecker.GetTotalPoint(sString1, sString2), invalid_argument);
}

TEST(TestCaseName, GetTotalPoint_NoString2)
{
    StringSmilarityChecker cChecker;

    string sString1 = "asdf";
    string sString2 = "";

    EXPECT_THROW(cChecker.GetTotalPoint(sString1, sString2), invalid_argument);
}

TEST(TestCaseName, GetTotalPoint_NoStrings)
{
    StringSmilarityChecker cChecker;

    string sString1 = "";
    string sString2 = "";

    EXPECT_THROW(cChecker.GetTotalPoint(sString1, sString2), invalid_argument);
}