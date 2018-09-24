import fileinput

NUMDAYS = [-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 29]

def main():
    for line in fileinput.input():
        date = line
        break
    line = date.split('/')

    nums = [int(i) for i in line]

    ret = partition(nums)
    if ret is not None and not ret:
        print('/'.join(line)[:-1] + ' is illegal')

def partition(md):
    md.sort()
    yr, mon, day = md[0], md[1], md[2]
    if day > 2999 or yr < 0 or mon <= 0:
        return False
    
    if mon == 2:
        if (isleap(yr) and day <= NUMDAYS[-1]) or (not isleap(yr) and day <= NUMDAYS[mon]):
            printyr(yr, mon, day)
            return
    elif mon > 0 and mon < 13 and day <= NUMDAYS[mon]:
        printyr(yr, mon, day)
        return
    yr, mon, day = md[0], md[2], md[1]
        
    if mon == 2 :
        if (isleap(yr) and day <= NUMDAYS[-1]) or (not isleap(yr) and day <= NUMDAYS[mon]):
            printyr(yr, mon, day)
            return
    elif mon > 0 and mon < 13 and day <= NUMDAYS[mon]:
        printyr(yr, mon, day)
        return
    yr, mon, day = md[1], md[0], md[2]
        
    if mon == 2:
        if (isleap(yr) and day <= NUMDAYS[-1]) or (not isleap(yr) and day <= NUMDAYS[mon]):
            printyr(yr, mon, day)
            return
    elif mon > 0 and mon < 13 and day <= NUMDAYS[mon]:
        printyr(yr, mon, day)
        return
    yr, mon, day = md[1], md[2], md[0]
        
    if mon == 2:
        if (isleap(yr) and day <= NUMDAYS[-1]) or (not isleap(yr) and day <= NUMDAYS[mon]):
            printyr(yr, mon, day)
            return
    elif mon > 0 and mon < 13 and day <= NUMDAYS[mon]:
        printyr(yr, mon, day)
        return
    yr, mon, day = md[2], md[0], md[1]
        
    if mon == 2:
        if (isleap(yr) and day <= NUMDAYS[-1]) or (not isleap(yr) and day <= NUMDAYS[mon]):
            printyr(yr, mon, day)
            return
    elif mon > 0 and mon < 13 and day <= NUMDAYS[mon]:
        printyr(yr, mon, day)
        return
    yr, mon, day = md[2], md[1], md[0]
        
    if mon == 2:
        if (isleap(yr) and day <= NUMDAYS[-1]) or (not isleap(yr) and day <= NUMDAYS[mon]):
            printyr(yr, mon, day)
            return
    elif mon > 0 and mon < 13 and day <= NUMDAYS[mon]:
        printyr(yr, mon, day)
        return
    return False

def isleap(yr):
    ret = yr % 4 == 0 and not (yr % 100 == 0 and not yr % 400 == 0)
    #print(ret)
    return ret
    
def printyr(yr, mon, day):
    if yr < 2000:
        yr += 2000
    print('%04d-%02d-%02d' % (yr, mon, day))

if __name__ == '__main__':
    main()
