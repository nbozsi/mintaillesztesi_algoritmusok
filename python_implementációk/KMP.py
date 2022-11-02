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


def KMP(m, s, P=[]):
    if not P:
        P = labfej(m)
        print("labfej tömb legenerálva")
    i = 0
    j = 0
    counter = 0
    while i + j < len(s):
        counter += 1
        if j == len(m):
            return i
        # print(s)
        # print(" " * (i + j) + "^")
        # print(" " * i + m)
        if s[i + j] == m[j]:
            j += 1
        else:
            if j == 0:
                i += 1
            else:
                i = i + j - P[j]
                j = P[j]
    print(counter)
    if j == len(m):
        return i
    return -1


if __name__ == "__main__":
    while True:
        minta = input()
        print(KMP(minta, input()))
