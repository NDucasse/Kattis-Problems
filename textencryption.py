import sys
def main():
    n = int(input())
    while n != 0:
        text = input()
        text = text.replace(' ', '')
        currin = 0
        curri = 0
        encrypt = [None] * len(text)
        for i in range(len(text)):
            encrypt[currin] = text[i].upper()
            if currin + n < len(text):
                currin = currin+n
            else:
                currin = curri + 1
                curri += 1
        for x in encrypt:
            print(x, end = '')
        print()
        n = int(input())

if __name__ == '__main__':
    main()