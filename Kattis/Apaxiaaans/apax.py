
def main():
    name = input('')
    name = list(name)
    newname = []
    prev = ''
    for letter in name:
        if letter != prev:
            newname.append(letter)
        prev = letter
    print(''.join(newname))

if __name__ == '__main__':
    main()
