
def main():
    num = int(input())
    nodemap = [[0 for i in range(num+1)] for j in range(num+1)]
    
    for i in range(num):
        road = input().split(' ')
        nodemap[int(road[1])][int(road[0])] += 1
        nodemap[int(road[0])][int(road[1])] += 1
    nodedegree = []
    used = []
    for i in range(len(nodemap)):
        nodes = 0
        for j in range(len(nodemap)):
            nodes += nodemap[i][j]
        nodedegree.append(nodes)
        
    currnode = 1
    
    # for i in range(len(nodemap)):
        # for j in range(len(nodemap)):
            # while(nodemap[i][j] != 0):
                # if i in used and not j in used:
                    # print(str(j) + ' ' + str(i))
                    # used.append(j)
                # elif j in used and not i in used:
                    # print(str(i) + ' ' + str(j))
                    # used.append(i)
                # elif nodedegree[i]%2 == nodedegree[j]%2 and nodedegree[j]%2 == 1 or nodedegree[j]%2 == 1:
                    # print(str(j) + ' ' + str(i))
                    # used.append(j)
                # else:
                    # print(str(i) + ' ' + str(j))
                    # used.append(i)
                # nodedegree[i] -= 1
                # nodedegree[j] -= 1
                # nodemap[i][j] -= 1
                # nodemap[j][i] -= 1
                
def DFS(currnode, nodemap, nodedegree, visited):
    done = False
    for i in nodemap[currnode]:
        
                
                
                
if __name__ == '__main__':
    main()
