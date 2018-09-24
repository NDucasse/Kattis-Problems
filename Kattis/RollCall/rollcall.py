import sys, collections
def main():
    names = {}
    firstnames = {}
    for line in sys.stdin:
        line = line.split(' ')
        if line[1][:-1] not in names:
            names[line[1][:-1]] = []
        if line[0] not in firstnames:
            firstnames[line[0]] = 0
        names[line[1][:-1]].append(line[0])
        firstnames[line[0]] += 1
    last = sorted([x for x in names])
    
    for name in last:
        firsts = sorted([x for x in names[name]])
        for first in firsts:
            if firstnames[first] == 1:
                print(first)
            else:
                print(first + ' ' + name)
                
    

if __name__ == '__main__':
    main()
