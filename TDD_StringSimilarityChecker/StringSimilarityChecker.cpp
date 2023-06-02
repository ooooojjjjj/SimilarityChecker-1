#include <string>
#include <stdexcept>

using namespace std;

#define MAX_ALPHABET_COUNT (26)

class StringSmilarityChecker
{
public:
    int GetTotalPoint(string sString1, string sString2)
    {
        if (IsInputEmpty(sString1, sString2))
            throw invalid_argument("값을 넣어야 합니다.");

        if (IsNotAllCapital(sString1 + sString2))
            throw invalid_argument("대문자만 입력 가능합니다.");

        return GetLengthPoint(sString1, sString2) + GetAlphaPoint(sString1, sString2);
    }

    bool IsInputEmpty(string sString1, string sString2)
    {
        if (0 == sString1.size() || 0 == sString2.size())
            return true;

        return false;
    }

    bool IsNotAllCapital(string sString)
    {
        for (char cEach : sString)
        {
            if (cEach < 'A' || cEach > 'Z')
                return true;
        }

        return false;
    }

    int GetLengthPoint(string sString1, string sString2)
    {
        CompareLength(sString1, sString2);

        return CalculateLengthPoint();
    }

    void CompareLength(string sString1, string sString2)
    {
        if (sString1.size() > sString2.size())
        {
            nLongLength = sString1.size();
            nShortLength = sString2.size();
        }
        else
        {
            nLongLength = sString2.size();
            nShortLength = sString1.size();
        }

        nDiffLength = nLongLength - nShortLength;
    }

    int CalculateLengthPoint()
    {
        if (nLongLength >= 2 * nShortLength) return 0;
        return (nShortLength - nDiffLength) * MAX_LENGTH_POINT / nShortLength;
    }

    int GetAlphaPoint(string sString1, string sString2)
    {
        CompareAlpha(sString1, sString2);

        return CalculateAlphaPoint();
    }

    void CompareAlpha(string sString1, string sString2)
    {
        bool anAlphbetMap1[MAX_ALPHABET_COUNT] = { 0 };
        bool anAlphbetMap2[MAX_ALPHABET_COUNT] = { 0 };

        for (int i = 0; i < sString1.size(); i++)
        {
            anAlphbetMap1[sString1[i] - 'A'] = true;
        }

        for (int i = 0; i < sString2.size(); i++)
        {
            anAlphbetMap2[sString2[i] - 'A'] = true;
        }

        for (int i = 0; i < MAX_ALPHABET_COUNT; i++)
        {
            if (anAlphbetMap1[i] && anAlphbetMap2[i])
            {
                nSameCount++;
            }

            if (anAlphbetMap1[i] || anAlphbetMap2[i])
            {
                nTotalCount++;
            }
        }
    }

    int CalculateAlphaPoint()
    {
        return MAX_ALPHA_POINT * nSameCount / nTotalCount;
    }

private:
    const int MAX_LENGTH_POINT = 60;
    int nLongLength = 0;
    int nShortLength = 0;
    int nDiffLength = 0;

    const int MAX_ALPHA_POINT = 40;
    int nSameCount = 0;
    int nTotalCount = 0;
};