#include "RabinKarp.h"
#include <unordered_map>

using namespace std;

unordered_map<int, string> my_hashes(string mintak[], int k, int val)
{
    unordered_map<int, string> my_hashes;
    for (int i = 0; i < k; i++)
    {
        my_hashes.insert({myhash(mintak[i], val), mintak[i]});
    }
    return my_hashes;
}

vector<int> RabinKarp_plus(int mintahossz, string szoveg, int val, unordered_map<int, string> table)
{
    vector<int> talalatok;
    int alap = 64;
    // int alap = E.size() + 1; // szamrendszer alapszama
    const int M = 1000000007; // ez egy nagyon nagy prímszám
    int maxh = 1;
    long long int vizsgalthash = 0;
    for (int i = 0; i < mintahossz; i++)
    {
        vizsgalthash = (vizsgalthash * alap + szoveg[i] - val) % M; // szoveg első substringének kiszámítása
    }
    for (int i = 0; i < mintahossz - 1; i++)
    {
        maxh = (maxh * alap) % M; // legnagyobb helyiérték kiszámítása
    }
    if (table.find(vizsgalthash) != table.end())
    {
        talalatok.push_back(0); // azaz a szoveg a mintával kezdődik
    }
    for (int i = 1; i <= szoveg.length() - mintahossz; i++)
    {
        vizsgalthash = (vizsgalthash - (szoveg[i - 1] - val) * maxh) % M; // betű eltávolítása az elejéről
        if (vizsgalthash < 0)                                             // negatív maraékot pozitívra hozzuk
        {
            vizsgalthash = vizsgalthash + M;
        }
        vizsgalthash = (vizsgalthash * alap + (szoveg[i + mintahossz - 1] - val)) % M; // betű hozzáadása a végéhez
        auto t = table.find(vizsgalthash);
        if (t != table.end())
        {
            bool jo = true;
            for (int j = 0; j < mintahossz; j++)
            {
                if (t->second[j] != szoveg[i + j])
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
    }
    return talalatok;
}
