def brute_force(minta, szoveg):
    for i in range(0, len(szoveg) - len(minta) + 1):
        jo = True
        for j in range(len(minta)):
            if minta[j] != szoveg[i + j]:
                jo = False
                break
        if jo:
            return i
    return -1


if __name__ == "__main__":
    while True:
        minta = input()
        print(brute_force(minta, input()))
