#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> tav(string minta, string szoveg)
{
    unordered_map<char, int> E;
    for (int i = 0; i < szoveg.length(); i++)
    {
        E[szoveg[i]] = minta.length();
    }
    for (int i = 0; i < minta.length() - 1; i++)
    {
        E[minta[i]] = minta.length() - i - 1;
    }
    return E;
}
vector<int> Horspool(string minta, string szoveg, unordered_map<char, int> E)
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
        j = E[szoveg[j]] + j;
    }
    return talalatok;
}