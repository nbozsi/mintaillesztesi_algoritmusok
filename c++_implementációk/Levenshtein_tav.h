#include <iostream>

using namespace std;

int Levenshtein_tavolsag(string s, string t)
{
    /* dinamikus programozással, n. sor m. hely tartalmazza az n, m hosszú kezdőszeletek levenshtein tavolságát,
        de csak két sorát tároljuk a mátrixnak, mivel nincs többre szükség*/
    int utolso[t.length() + 1];
    int aktualis[t.length() + 1];

    for (int i = 0; i < t.length() + 1; i++)
    {
        utolso[i] = i; // a 0 hosszú kezdőszelet és az i  hosszú távolsága i, mivel i hozzáadással tudjuk megkapni
    }
    int torles_ar;
    int beszuras_ar;
    int atiras_ar;
    for (int i = 0; i < s.length(); i++)
    {
        aktualis[0] = i + 1; // mivel i+1 karaktert kell törölni s-ből, hogy megkapjuk az üres stringet

        for (int j = 0; j < t.length(); j++)
        {
            torles_ar = utolso[j + 1] + 1; // mivel csak torlunk egyet az eggyel hosszabb kezdőszeletből
            beszuras_ar = aktualis[j] + 1; // mivel csak hozzáadunk egy betűt az eggyel rövidebb kezdőszelethez
            if (s[i] == t[j])
            {
                atiras_ar = utolso[j]; // mivel nem kell átírni kezdőszelet legutolsó betűjét, ezért annyi mint az eggyel rövidebb kezdőszeletek távolsága
            }
            else
            {
                atiras_ar = utolso[j] + 1; // mivel át kell írni a kezdőszelet legutolsó betűjét
            }
            int mizu = min(torles_ar, min(beszuras_ar, atiras_ar));
            aktualis[j + 1] = mizu;
        }
        for (int j = 0; j < t.length() + 1; j++)
        {
            utolso[j] = aktualis[j]; // lemásoljuk az aktuálisat az utolsóba
        }
    }
    return utolso[t.length()];
}