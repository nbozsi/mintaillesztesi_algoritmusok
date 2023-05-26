#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
#include "RabinKarp.h"
#include "AhoCorasick.h"

using namespace std;
using namespace std::chrono;

void timeit(int (*func)(string, string, vector<int>), vector<int> (*func2)(string), string minta[], string szoveg, int, int);               // KMP
void timeit(int (*func)(string, string, map<char, int>), map<char, int> (*func2)(string), string minta[], string szoveg, int, int);         // Rabin-Karp
void timeit(int (*func)(string, string, map<char, int>), map<char, int> (*func2)(string, string), string minta[], string szoveg, int, int); // Horspool
void timeit(int (*func)(string, string), string minta[], string szoveg, int, int);                                                          // brute_force
void timeit(vector<int> (*func)(string, Node *), string szoveg, Node *gyoker, int);                                                         // aho-corasick

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

    cout << "brute_force" << '\t';
    timeit(&brute_force, mintak, szoveg, argc - 2, probak);

    cout << "Horspool" << '\t';
    timeit(&Horspool, &tav, mintak, szoveg, argc - 2, probak);

    cout << "KMP" << '\t';
    timeit(&KMP, &labfej, mintak, szoveg, argc - 2, probak);

    cout << "Rabin-Karp" << '\t';
    timeit(&RabinKarp, &charvalue, mintak, szoveg, argc - 2, probak);

    cout << "Aho-Corasick" << '\t';
    timeit(&AhoCorasick, szoveg, gyok, probak);

    return 0;
}

void timeit(vector<int> (*func)(string, Node *), string szoveg, Node *gyoker, int n)
{
    vector<int> pos;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(szoveg, gyoker);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    cout << pos.back() << '\t' << sum / n << endl;
}
void timeit(int (*func)(string, string, vector<int>), vector<int> (*func2)(string), string minta[], string szoveg, int tombmeret, int n)
{
    int pos;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        vector<int> P = func2(minta[j]);
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg, P);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            sum = sum + ms_double.count();
        }
    }
    cout << pos << '\t' << sum / n << endl;
}
void timeit(int (*func)(string, string, map<char, int>), map<char, int> (*func2)(string), string minta[], string szoveg, int tombmeret, int n)
{
    int pos;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        map<char, int> E = func2(minta[j]);
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg, E);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            sum = sum + ms_double.count();
        }
    }
    cout << pos << '\t' << sum / n << endl;
}
void timeit(int (*func)(string, string, map<char, int>), map<char, int> (*func2)(string, string), string minta[], string szoveg, int tombmeret, int n)
{
    int pos;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        map<char, int> tavok = func2(minta[j], szoveg);
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg, tavok);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            sum = sum + ms_double.count();
        }
    }
    cout << pos << '\t' << sum / n << endl;
}
void timeit(int (*func)(string, string), string minta[], string szoveg, int tombmeret, int n)
{
    int pos;
    double sum = 0;
    for (int j = 0; j < tombmeret; j++)
    {
        for (int i = 0; i < n; i++)
        {
            auto t1 = high_resolution_clock::now();
            pos = func(minta[j], szoveg);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            sum = sum + ms_double.count();
        }
    }
    cout << pos << '\t' << sum / n << endl;
}