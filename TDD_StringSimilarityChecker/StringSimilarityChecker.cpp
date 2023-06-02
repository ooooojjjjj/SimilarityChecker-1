#include <string>
#include <stdexcept>

using namespace std;

class StringSmilarityChecker
{
public:
    int GetTotalPoint(string sString1, string sString2)
    {
        if (false == CheckInputValidity(sString1, sString2))
            throw invalid_argument("값을 넣어야 합니다.");

        return 0;
    }

    bool CheckInputValidity(string& sString1, string& sString2)
    {
        if (0 == sString1.size() || 0 == sString2.size())
            return false;
    }
};