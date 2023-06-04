#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
#include "RabinKarp_plus.h"
#include "AhoCorasick.h"

using namespace std;
using namespace std::chrono;

void timeit(vector<int> (*func)(string, string, vector<int>), vector<int> (*func2)(string), string minta[], string szoveg, int, int);                     // KMP
void timeit(vector<int> (*func)(int, string, int, int, unordered_map<int, string>), int, int, int, unordered_map<int, string>, string szoveg, int);       // Karp-Rabin
void timeit(vector<int> (*func)(string, string, vector<int>, int), vector<int> (*func2)(string, string, int *), string minta[], string szoveg, int, int); // Horspool
void timeit(vector<int> (*func)(string, string), string minta[], string szoveg, int, int);                                                                // brute_force
void timeit(vector<int> (*func)(string, Node *), string szoveg, Node *gyoker, int);                                                                       // aho-corasick

int main(int argc, char *argv[])
{
    string mintak[argc - 2]; // beolvasás
    for (int i = 0; i < argc - 2; i++)
    {
        mintak[i] = argv[i + 1];
    }
    string szoveg(argv[argc - 1]);

    int probak = 10;
    // előfeldolgozás
    Node *gyok = epites(mintak, argc - 2);
    int x, y;
    val(szoveg, &x, &y);
    unordered_map<int, string> table = my_hashes(mintak, argc - 2, y, x);

    cout << "brute_force" << '\t';
    timeit(&brute_force, mintak, szoveg, argc - 2, probak);
    cout << '\n';

    cout << "Horspool" << '\t';
    timeit(&Horspool, &tav, mintak, szoveg, argc - 2, probak);
    cout << '\n';

    cout << "KMP" << '\t';
    timeit(&KMP, &labfej, mintak, szoveg, argc - 2, probak);
    cout << '\n';

    cout << "Karp-Rabin" << '\t';
    timeit(&RabinKarp_plus, mintak[0].length(), y, x, table, szoveg, probak);
    cout << '\n';

    cout << "Aho-Corasick" << '\t';
    timeit(&AhoCorasick, szoveg, gyok, probak);

    return 0;
}

void timeit(vector<int> (*func)(string, Node *), string szoveg, Node *gyoker, int n)
{
    vector<int> pos;
    double min = 10000;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(szoveg, gyoker);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}
void timeit(vector<int> (*func)(string, string, vector<int>), vector<int> (*func2)(string), string minta[], string szoveg, int tombmeret, int n)
{
    vector<int> pos;
    int talalat_counter = 0;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        vector<int> P = func2(minta[j]);
        double min = 10000;
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg, P);
            auto t2 = high_resolution_clock::now();
            talalat_counter += pos.size();
            duration<double, std::milli> ms_double = t2 - t1;
            if (min > ms_double.count())
            {
                min = ms_double.count();
            }
        }
        sum = sum + min;
    }
    cout << talalat_counter / 10 << '\t' << sum;
}
void timeit(vector<int> (*func)(int, string, int, int, unordered_map<int, string>), int mintahossz, int alap, int val, unordered_map<int, string> table, string szoveg, int n)
{
    vector<int> pos;
    double min = 10000;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(mintahossz, szoveg, alap, val, table);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}
void timeit(vector<int> (*func)(string, string, vector<int>, int), vector<int> (*func2)(string, string, int *), string minta[], string szoveg, int tombmeret, int n)
{
    vector<int> pos;
    int talalat_counter = 0;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        double min = 10000;
        int x;
        vector<int> tavok = func2(minta[j], szoveg, &x);
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg, tavok, x);
            auto t2 = high_resolution_clock::now();
            talalat_counter += pos.size();
            duration<double, std::milli> ms_double = t2 - t1;
            if (min > ms_double.count())
            {
                min = ms_double.count();
            }
        }
        sum = sum + min;
    }
    cout << talalat_counter / 10 << '\t' << sum;
}
void timeit(vector<int> (*func)(string, string), string minta[], string szoveg, int tombmeret, int n)
{
    vector<int> pos;
    int talalat_counter = 0;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        double min = 10000;
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg);
            auto t2 = high_resolution_clock::now();
            talalat_counter += pos.size();
            duration<double, std::milli> ms_double = t2 - t1;
            if (min > ms_double.count())
            {
                min = ms_double.count();
            }
        }
        sum = sum + min;
    }
    cout << talalat_counter / 10 << '\t' << sum;
}