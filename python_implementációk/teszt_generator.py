import random

abc = [
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
    'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
    'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', '.', '?', '!', ',', ':', '=', '<', '>', '+', '-', '/', '*', ' '
]


def teszteset(minta_hossz=5, szoveg_hossz=20, abc_meret=26, benne_van=True):
    szoveg = ''.join(random.choices(abc[:abc_meret], k=szoveg_hossz))
    if benne_van:
        megfejtes = random.randint(0, szoveg_hossz - minta_hossz) #lehetséges, hogy korábban előfordul, de ez egyszerűen kiszűrhető
        minta = szoveg[megfejtes:megfejtes + minta_hossz]
        return minta, szoveg, abc[:abc_meret], megfejtes
    minta = ''.join(random.choices(abc[:abc_meret], k=minta_hossz))
    return minta, szoveg, abc[:abc_meret], -1


if __name__ == "__main__":
    params = (int(p) for p in input().split(' '))
    print(teszteset(*params))