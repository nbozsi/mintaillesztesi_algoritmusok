#include <iostream>
#include <unordered_map>

using namespace std;

void val2(string abc, int *min, int *max)
{
    *min = abc[0];
    *max = abc[0];
    for (int i = 0; i < abc.length(); i++)
    {
        if (abc[i] < *min)
        {
            *min = abc[i];
        }

        if (abc[i] > *max)
        {
            *max = abc[i];
        }
    }
}
vector<int> tav(string minta, string szoveg, int *shift)
{
    int y;
    val2(minta + szoveg, shift, &y);
    vector<int> E = {};
    for (int i = 0; i < *shift + y + 1; i++)
    {
        E.push_back(minta.length());
    }
    for (int i = 0; i < minta.length() - 1; i++)
    {
        E[minta[i] - *shift] = minta.length() - i - 1;
    }
    return E;
}
vector<int> Horspool(string minta, string szoveg, vector<int> E, int shift)
{
    int j = minta.length() - 1;
    bool jo;
    vector<int> talalatok;
    while (j < szoveg.length())
    {
        if (szoveg[j] == minta.back())
        {
            jo = true;
            for (int i = 0; i < minta.length(); i++)
            {
                if (szoveg[j - minta.length() + 1 + i] != minta[i])
                {
                    jo = false;
                    break;
                }
            }
            if (jo)
            {
                talalatok.push_back(j - minta.length() + 1);
            }
        }
        j = E[szoveg[j] - shift] + j;
    }
    return talalatok;
}