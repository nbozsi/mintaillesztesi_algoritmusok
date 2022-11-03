# KMP
def labfej(minta):
    P = [0] * (len(minta) + 1)
    for i in range(1, len(minta)):
        j = i
        while j > 0:
            if minta[P[j]] == minta[i]:
                P[i + 1] = P[j] + 1
                break
            else:
                j = P[j]
    return P


def KMP(minta, szoveg, P=[]):
    if not P:
        P = labfej(minta)
    i, j = 0,0
    while i + j < len(szoveg):
        if j == len(minta):
            return i
        # print(s)
        # print(" " * (i + j) + "^")
        # print(" " * i + m)
        if szoveg[i + j] == minta[j]:
            j += 1
        else:
            if j == 0:
                i += 1
            else:
                i = i + j - P[j]
                j = P[j]
    if j == len(minta):
        return i
    return -1


if __name__ == "__main__":
    while True:
        minta = input()
        print(KMP(minta, input()))
