class Solution:

    num_unions = 0

    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:

        def get_adj(i, j):
            adj = []
            i_vals = [0]
            j_vals = [0]

            if i - 1 >= 0:
                i_vals.append(-1)
            if i + 1 < m:
                i_vals.append(1)
            if j - 1 >= 0:
                j_vals.append(-1)
            if j + 1 < n:
                j_vals.append(1)

            for k in i_vals:
                for l in j_vals:
                    if abs(k) == abs(l):
                        continue
                    adj.append([i + k, j + l])
            return adj

        def calculate_index(i, j):
            return i * n + j

        def find_parent(parent, x):
            if parent[x] == -1 or parent[x] == x:
                return x

            result = find_parent(parent, parent[x])
            parent[x] = result
            return result

        def union(parent, x, y):
            set_x = find_parent(parent, x)
            set_y = find_parent(parent, y)
            parent[set_x] = set_y
            if set_x != set_y:
                self.num_unions += 1

        output = []

        grid = []
        for i in range(m):
            grid.append([0] * n)

        parent = [-1] * n * m
        num_changing_operations = 0
        for position in positions:
            i = position[0]
            j = position[1]
            if grid[i][j] == 1:
                output.append(output[-1])
                continue
            num_changing_operations += 1
            grid[i][j] = 1
            c_idx = calculate_index(i, j)
            parent[c_idx] = c_idx
            for k, l in get_adj(i, j):
                if grid[k][l] == 1:
                    union(parent, c_idx, calculate_index(k, l))
            output.append(num_changing_operations - self.num_unions)

        return output