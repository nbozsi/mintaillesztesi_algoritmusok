from KMP import KMP, labfej
from Horspool import Horspool, tav
from brute_force import brute_force
from teszt_generator import teszteset
import time


def futasido(func, *args):
    print(f"{func.__name__:^20}")
    start = time.perf_counter()
    print(func(*args))
    print(f"{time.perf_counter()-start:>20.6f}")
    print("-" * 20)


def osszehasonlit(minta, szoveg, abc):
    futasido(KMP, minta, szoveg)
    P = labfej(minta)
    futasido(KMP, minta, szoveg, P)
    futasido(Horspool, minta, szoveg, abc)
    E = tav(minta, abc)
    futasido(Horspool, minta, szoveg, abc, E)
    futasido(brute_force, minta, szoveg)


if __name__ == "__main__":
    while True:
        teszt_params = (int(p) for p in input().split(" "))  # mintahossz szöveghossz abcméret
        eset = teszteset(*teszt_params)
        eset=("baaaaaaaaa","a"*10**7+"b",['a','b'])
        osszehasonlit(*eset)
