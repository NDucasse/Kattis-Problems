
def main():
    num = input('')
    for i in range(int(num)):
        line = [int(x) for x in input('').split(' ')]
        prev = line[1]
        line = line[2:-1]
        i = 2
        for gnome in line:
            if not gnome == (prev + 1):
                print(i)
                break
            i += 1
            prev = gnome

if __name__ == '__main__':
    main()
