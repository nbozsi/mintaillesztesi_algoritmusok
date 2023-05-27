#include "trie.h"
#include <string>
#include <vector>
#include <map>
void hibael_kereses(vector<Node *> szint, vector<Node *> szint_szulo);

Node *epites(string mintak[], int n)
{
    Node *gyoker = new Node();
    Node *helyzet;
    // a fa építése
    for (int i = 0; i < n; i++)
    {
        helyzet = gyoker;
        for (int j = 0; j < mintak[i].length(); j++)
        {
            if (helyzet->gyerek.find(mintak[i][j]) == helyzet->gyerek.end())
            {
                Node *csucs = new Node(mintak[i][j]);
                helyzet->gyerek.insert({mintak[i][j], csucs});
                helyzet = csucs;
            }
            else
            {
                helyzet = helyzet->gyerek[mintak[i][j]];
            }
        }
        if (mintak[i].length() > helyzet->szo_veg.length())
        {
            helyzet->szo_veg = mintak[i];
        }
    }
    vector<Node *> szint1;       // az első szint a fában
    vector<Node *> szint1_szulo; // a gyökér pointere sokszor
    for (const auto &[key, value] : gyoker->gyerek)
    {
        szint1.push_back(value);
        szint1_szulo.push_back(gyoker);
    }
    hibael_kereses(szint1, szint1_szulo);
    return gyoker;
}
void hibael_kereses(vector<Node *> szint, vector<Node *> szint_szulo)
{
    vector<Node *> kovetkezo = {};
    vector<Node *> kovetkezo_szulo = {};
    Node *helyzet = nullptr;
    for (int i = 0; i < szint.size(); i++)
    {
        for (const auto &[key, value] : szint[i]->gyerek) // következő szintbe berakjuk a az ezen a szinten lévők gyerekeit
        {
            kovetkezo.push_back(value);
            kovetkezo_szulo.push_back(szint[i]);
        }
        if (szint_szulo[i]->hiba == szint_szulo[i])
        {
            szint[i]->hiba = szint_szulo[i];
        }
        else
        {
            helyzet = szint_szulo[i]->hiba; // addig lépkedünk amíg nem tudunk egy valid faágon lépni
            while (helyzet->gyerek.find(szint[i]->betu) == helyzet->gyerek.end() && helyzet != (helyzet->hiba))
            {
                helyzet = helyzet->hiba;
            }
            szint[i]->hiba = helyzet->lepes(szint[i]->betu);
        }
    }
    if (kovetkezo.empty() == false) // rekurzívan meghívjuk a következő szintre is
    {
        hibael_kereses(kovetkezo, kovetkezo_szulo);
    }
}
vector<int> AhoCorasick(string szoveg, Node *gyoker)
{
    vector<int> elofordulasok = {};
    Node *helyzet = gyoker;
    for (int i = 0; i < szoveg.length(); i++)
    {
        if (helyzet->szo_veg.length() > 0)
        {
            // std::cout << helyzet->szo_veg << " megjelenik " << i - helyzet->szo_veg.length() << "-tol " << i << "-ig.\n";
            elofordulasok.push_back(i - helyzet->szo_veg.length());
        }
        helyzet = helyzet->lepes(szoveg[i]);
        if (helyzet->gyerek.find(szoveg[i]) == helyzet->gyerek.end() && helyzet != gyoker) // ha hibaélen lépünk akkor továbbra is az eddig vizsgált betűvel megyünk tovább, kivéve ha a gyökérben loopolunk
        {
            i--;
        }
    }
    return elofordulasok;
}