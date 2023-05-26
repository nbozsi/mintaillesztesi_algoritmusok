#include <iostream>
#include <vector>

using namespace std;

vector<int> brute_force(string minta, string szoveg)
{
    vector<int> talalatok = {};
    bool jo;
    for (int i = 0; i <= szoveg.length() - minta.length(); i++)
    {
        jo = true;
        for (int j = 0; j < minta.length(); j++)
        {
            if (minta[j] != szoveg[i + j])
            {
                jo = false;
                break;
            }
        }
        if (jo)
        {
            talalatok.push_back(i);
        }
    }
    return talalatok;
}