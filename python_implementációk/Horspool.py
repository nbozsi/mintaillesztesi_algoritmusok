def tav(minta, abc):
    E = {betu: len(minta) for betu in abc}
    for i, betu in enumerate(minta[:-1]):
        E[betu] = len(minta) - i - 1
    return E


def Horspool(minta, szoveg, abc, E=[]):
    if not E:
        E = tav(minta, abc)
        print("E legenerálva")
    j = len(minta) - 1
    while j < len(szoveg):
        if szoveg[j] == minta[-1]:
            if szoveg[j - len(minta) + 1 : j + 1] == minta:
                return j - len(minta) + 1
        j = E[szoveg[j]] + j
    return -1


if __name__ == "__main__":
    while True:
        minta = input()
        szoveg = input()
        print(Horspool(minta, szoveg, set(szoveg)))
