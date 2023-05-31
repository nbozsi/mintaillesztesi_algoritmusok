#include <iostream>
#include <vector>

using namespace std;

vector<int> Levenshtein_tavolsag(string s, string t, int k)
{
    vector<int> talalatok;
    /* dinamikus programozással, n. sor m. hely tartalmazza az n, m hosszú kezdőszeletek levenshtein tavolságát,
        de csak két sorát tároljuk a mátrixnak, mivel nincs többre szükség*/
    vector<int> utolso(t.length() + 1);
    vector<int> aktualis(t.length() + 1);

    for (int i = 0; i < t.length() + 1; i++)
    {
        utolso[i] = 0; // a 0 hosszú kezdőszelet és az i  hosszú távolsága i, mivel i hozzáadással tudjuk megkapni
    }
    int torles_ar;
    int beszuras_ar;
    int atiras_ar;
    for (int i = 0; i < s.length(); i++)
    {
        aktualis[0] = i + 1; // mivel i+1 karaktert kell törölni s-ből, hogy megkapjuk az üres stringet

        for (int j = 0; j < t.length(); j++)
        {
            if (s[i] == t[j])
            {
                aktualis[j + 1] = utolso[j]; // mivel nem kell átírni kezdőszelet legutolsó betűjét, ezért annyi mint az eggyel rövidebb kezdőszeletek távolsága
            }
            else
            {
                torles_ar = utolso[j + 1] + 1; // mivel csak torlunk egyet az eggyel hosszabb kezdőszeletből
                beszuras_ar = aktualis[j] + 1; // mivel csak hozzáadunk egy betűt az eggyel rövidebb kezdőszelethez

                atiras_ar = utolso[j] + 1; // mivel át kell írni a kezdőszelet legutolsó betűjét
                aktualis[j + 1] = min(torles_ar, min(beszuras_ar, atiras_ar));
            }
        }
        for (int j = 0; j < t.length() + 1; j++)
        {
            utolso[j] = aktualis[j]; // lemásoljuk az aktuálisat az utolsóba
        }
    }
    for (int i = 0; i < t.length() + 1; i++)
    {
        if (utolso[i] <= k)
        {
            talalatok.push_back(i);
        }
    }
    return talalatok;
}