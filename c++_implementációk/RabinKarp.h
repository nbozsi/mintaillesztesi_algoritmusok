#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

unordered_map<char, int> charvalue(string szoveg)
{
    unordered_map<char, int> E;
    int next = 1;
    pair<unordered_map<char, int>::iterator, bool> ret;
    for (int i = 0; i < szoveg.length(); i++)
    {
        ret = E.insert({szoveg[i], next});
        if (ret.second)
        {
            next++;
        }
    }
    return E;
}
void val(string abc, int *min, int *max)
{
    vector<char> vesztesek;
    vector<char> nyertesek;
    for (int i = 0; i < abc.length() - 1; i += 2)
    {
        if (abc[i] < abc[i + 1])
        {
            vesztesek.push_back(abc[i]);
            nyertesek.push_back(abc[i + 1]);
        }
        else
        {
            nyertesek.push_back(abc[i]);
            vesztesek.push_back(abc[i + 1]);
        }
    }
    if (abc.length() % 2 == 1)
    {
        vesztesek.push_back(abc.back());
        nyertesek.push_back(abc.back());
    }
    *min = vesztesek[0];
    *max = nyertesek[0];
    for (int i = 0; i < nyertesek.size(); i++)
    {
        if (*max < nyertesek[i])
        {
            *max = nyertesek[i];
        }
        if (*min > vesztesek[i])
        {
            *min = vesztesek[i];
        }
    }
}
vector<int> RabinKarp(string minta, string szoveg, int alap, int val)
{
    vector<int> talalatok;
    // int alap = E.size() + 1; // szamrendszer alapszama
    int M = 1000000007; // ez egy nagyon nagy prímszám
    int maxh = 1;
    long long int mintahash = 0;
    long long int vizsgalthash = 0;
    for (int i = 0; i < minta.length(); i++)
    {
        mintahash = (mintahash * alap + minta[i] - val) % M;        // minta hashének kiszámítása
        vizsgalthash = (vizsgalthash * alap + szoveg[i] - val) % M; // szoveg első substringének kiszámítása
    }
    for (int i = 0; i < minta.length() - 1; i++)
    {
        maxh = (maxh * alap) % M; // legnagyobb helyiérték kiszámítása
    }
    if (mintahash == vizsgalthash)
    {
        talalatok.push_back(0); // azaz a szoveg a mintával kezdődik
    }
    for (int i = 1; i <= szoveg.length() - minta.length(); i++)
    {
        vizsgalthash = (vizsgalthash - (szoveg[i - 1] - val) * maxh) % M; // betű eltávolítása az elejéről (hozzáadunk M-t hogy pozitív maradék legyen)
        if (vizsgalthash < 0)                                             // negatív maraékot pozitívra hozzuk
        {
            vizsgalthash = vizsgalthash + M;
        }
        vizsgalthash = (vizsgalthash * alap + (szoveg[i + minta.length() - 1] - val)) % M; // betű hozzáadása a végéhez
        if (vizsgalthash == mintahash)
        {
            talalatok.push_back(i);
        }
    }
    return talalatok;
}