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
            if ((*helyzet).gyerek.find(mintak[i][j]) == (*helyzet).gyerek.end())
            {
                Node *csucs = new Node(mintak[i][j], (j == mintak[i].length() - 1));
                (*helyzet).gyerek.insert({mintak[i][j], csucs});
                helyzet = csucs;
            }
            else
            {
                helyzet = (*helyzet).gyerek[mintak[i][j]];
            }
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
    /*for (int i = 0; i < szint.size(); i++)
    {
        cout << szint[i]->betu << '-' << szint_szulo[i]->betu << ' ';
    }*/
    vector<Node *> kovetkezo = {};
    vector<Node *> kovetkezo_szulo = {};
    Node *helyzet;
    for (int i = 0; i < szint.size(); i++)
    {
        cout << szint[i]->betu;
        for (const auto &[key, value] : szint[i]->gyerek) // következő szintbe berakjuk a az ezen a szinten lévők gyerekeit
        {
            kovetkezo.push_back(value);
            kovetkezo_szulo.push_back(szint[i]);
        }
        helyzet = szint_szulo[i]->hiba; // addig lépkedünk amígnem tudunk egy valid faágon lépni
        cout << "\tszulo: " << szint_szulo[i]->betu;
        cout << "\tszulo hibaja: " << szint_szulo[i]->hiba->betu << '\t';
        while (helyzet->gyerek.find(szint[i]->betu) == helyzet->gyerek.end() && helyzet != helyzet->hiba)
        {
            cout << "i";
            helyzet = helyzet->hiba;
        }
        cout << "\thelyzet: " << helyzet->betu << "\thelyzet lepese: " << helyzet->lepes(szint[i]->betu)->betu;
        szint[i]->hiba = helyzet->lepes(szint[i]->betu);
        cout << "\thiba: " << szint[i]->hiba->betu << endl;
        // cout << szint[i]->hiba->betu;
    }
    if (kovetkezo.empty() == false)
    {
        hibael_kereses(kovetkezo, kovetkezo_szulo);
    }
}