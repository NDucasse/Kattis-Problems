
def main():
    first = list(input(''))
    second = list(input(''))
    i, j, k, l = 0, 0, 0, 0
    trigger = False
    while i < len(first) and j < len(second) and first[i] == second[j]:
        i += 1
        j += 1
    k = i + 1
    i = len(first) - 1
    j = len(second) - 1
    while i > -1 and j > -1 and first[i] == second[j]:
        i -= 1
        j -= 1
    l = j
    print(l - k)

if __name__ == '__main__':
    main()
