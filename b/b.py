keyboard = {'q':[0,0], 'w':[0,1], 'e':[0,2], 'r':[0,3], 't':[0,4], 'y':[0,5], 'u':[0,6], 'i':[0,7], 'o':[0,8], 'p':[0,9],
            'a':[1,0], 's':[1,1], 'd':[1,2], 'f':[1,3], 'g':[1,4], 'h':[1,5], 'j':[1,6], 'k':[1,7], 'l':[1,8],
            'z':[2,0], 'x':[2,1], 'c':[2,2], 'v':[2,3], 'b':[2,4], 'n':[2,5], 'm':[2,6]}
keylen = [10, 9, 7]

n = int(input(''))
for i in range(n):
    st = input('')
    st = st.split(' ')
    l = int(st[1])
    st = st[0]
    lst = []
    distance = {}
    for j in range(l):
        lst.append(input(''))
    small = float("inf")
    for itm in lst:
        dist = 0
        for x in range(len(itm)):
            dist += abs(keyboard[itm[x]][0] - keyboard[st[x]][0])
            dist += abs(keyboard[itm[x]][1] - keyboard[st[x]][1])
        distance[itm] = dist
    slist = sorted(distance, key=lambda x : (distance[x], x) )
    for x in slist:
        print(x + ' ' + str(distance[x]))
