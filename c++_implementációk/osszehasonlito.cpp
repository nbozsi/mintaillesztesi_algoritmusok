#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
#include "RabinKarp.h"

using namespace std;
using namespace std::chrono;

void timeit(vector<int> (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P, int); // function overloading, hogy mindre működjön
void timeit(vector<int> (*func)(string, string, vector<int>, int), string minta, string szoveg, vector<int> tavok, int, int);
void timeit(vector<int> (*func)(string, string, int, int, long long int), string minta, string szoveg, int alap, int val, long long int mintahash, int);
void timeit(vector<int> (*func)(string, string), string minta, string szoveg, int);

int main(int argc, char *argv[])
{
    string minta(argv[1]); // beolvasás
    string szoveg(argv[2]);
    int probak = 10;

    vector<int> P = labfej(minta); // előfeldolgozás
    int sh;
    vector<int> tavok = tav(minta, szoveg, &sh);
    int x, y;
    val(minta + szoveg, &x, &y);
    long long int mintahash = myhash(minta, y - x + 1, x);

    cout << "brute_force" << '\t';
    timeit(&brute_force, minta, szoveg, probak);
    cout << '\n';

    cout << "Horspool" << '\t';
    timeit(&Horspool, minta, szoveg, tavok, sh, probak);
    cout << '\n';

    cout << "KMP" << '\t';
    timeit(&KMP, minta, szoveg, P, probak);
    cout << '\n';

    cout << "Rabin-Karp" << '\t';
    timeit(&RabinKarp, minta, szoveg, y, x, mintahash, probak);
    return 0;
}

void timeit(vector<int> (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P, int n)
{
    vector<int> pos;
    double min = 1000;
    for (int i = 0; i < n; i++) // n-szer futtatjuk és a futásidők átlagát vesszük
    {
        auto t1 = high_resolution_clock::now(); // kezdő időpont
        pos = func(minta, szoveg, P);
        auto t2 = high_resolution_clock::now(); // végző időpont
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}
void timeit(vector<int> (*func)(string, string, vector<int>, int), string minta, string szoveg, vector<int> tavok, int shift, int n)
{
    vector<int> pos;
    double min = 1000;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg, tavok, shift);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}
void timeit(vector<int> (*func)(string, string), string minta, string szoveg, int n)
{
    vector<int> pos;
    double min = 1000;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}
void timeit(vector<int> (*func)(string, string, int, int, long long int), string minta, string szoveg, int alap, int val, long long int mintahash, int n)
{
    vector<int> pos;
    double min = 1000;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg, alap, val, mintahash);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}