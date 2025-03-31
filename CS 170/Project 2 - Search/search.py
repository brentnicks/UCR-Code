from typing import List, Tuple
from queue import PriorityQueue
from collections import deque
import heapq

class SearchAlgorithm:

    # Implement Uniform search
    @staticmethod
    def uniform_search(grid: List[List[str]]) -> Tuple[int, List[List[str]]]:
        start = None
        target = None
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 's':
                    start = (i, j)
                if grid[i][j] == 't':
                    target = (i, j)
        if start == None or target == None:
            return -1, grid
        
        
        currMove = 1
        pq = []
        visited = []
        heapq.heappush(pq, (0,start))
        visited.append((start[0], start[1]))
        while len(pq) > 0:
            (priority1, coord) = heapq.heappop(pq)
            i = coord[0]
            j= coord[1]
            if grid[i][j] == 't':
                return 1, grid
            elif grid[i][j] == '0':
                grid[i][j] = str(currMove)
                currMove += 1
            if j + 1 < len(grid[0]) and (i,j + 1) not in visited and (grid[i][j + 1] == '0' or grid[i][j + 1] == 't'): #right
                heapq.heappush(pq, (priority1 + 1, (i, j + 1)))
                visited.append((i, j + 1))
            if i + 1 < len(grid) and (i + 1,j) not in visited and (grid[i + 1][j] == '0' or grid[i + 1][j] == 't'): #down
                heapq.heappush(pq, (priority1 + 1, (i + 1, j)))
                visited.append((i + 1, j))
            if j - 1 >= 0 and (i,j - 1) not in visited and (grid[i][j - 1] == '0' or grid[i][j - 1] == 't'): #left
                heapq.heappush(pq, (priority1 + 1, (i, j - 1)))
                visited.append((i, j - 1))
            if i - 1 >= 0 and (i - 1,j) not in visited and (grid[i - 1][j] == '0' or grid[i - 1][j] == 't'): #up
                heapq.heappush(pq, (priority1 + 1, (i - 1, j)))
                visited.append((i - 1, j))
        return -1, grid
        
        

    # Implement Depth First Search
    @staticmethod
    def dfs(grid: List[List[str]]) -> Tuple[int, List[List[str]]]:
        start = None
        target = None
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 's':
                    start = (i, j)
                elif grid[i][j] == 't':
                    target = (i, j)
        
        if start == None or target == None:
            return -1, grid
        
        currMove = 1
        stack = deque()
        stack.append(start)
        #print(start, target)
        while len(stack) > 0:
            (i, j) = stack.pop()
            if (i, j) == target:
                return 1, grid
            if (i, j) != start and grid[i][j] == '0':
                grid[i][j] = str(currMove)
                currMove += 1
            if j + 1 < len(grid[0]) and (grid[i][j + 1] == '0' or grid[i][j + 1] == 't'): #right
                stack.append((i, j + 1))
            if i + 1 < len(grid) and (grid[i + 1][j] == '0' or grid[i + 1][j] == 't'): #down
                stack.append((i + 1, j))
            if j - 1 >= 0 and (grid[i][j - 1] == '0' or grid[i][j - 1] == 't'): #left
                stack.append((i, j - 1))
            if i - 1 >= 0 and (grid[i - 1][j] == '0' or grid[i - 1][j] == 't'): #up
                stack.append((i - 1, j))
        return -1, grid
            
    
    # Implement Breadth First Search
    @staticmethod
    def bfs(grid: List[List[str]]) -> Tuple[int, List[List[str]]]:
        start = None
        target = None
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 's':
                    start = (i, j)
                elif grid[i][j] == 't':
                    target = (i, j)
                    
        if start == None or target == None:
            return -1, grid
        
        currMove = 1
        stack = deque()
        stack.append(start)
        #print(start, target)
        while len(stack) > 0:
            (i, j) = stack.popleft()
            if (i, j) == target:
                return 1, grid
            if (i, j) != start and grid[i][j] == '0':
                grid[i][j] = str(currMove)
                currMove += 1
            if j + 1 < len(grid[0]) and (grid[i][j + 1] == '0' or grid[i][j + 1] == 't'): #right
                stack.append((i, j + 1))
            if i + 1 < len(grid) and (grid[i + 1][j] == '0' or grid[i + 1][j] == 't'): #down
                stack.append((i + 1, j))
            if j - 1 >= 0 and (grid[i][j - 1] == '0' or grid[i][j - 1] == 't'): #left
                stack.append((i, j - 1))
            if i - 1 >= 0 and (grid[i - 1][j] == '0' or grid[i - 1][j] == 't'): #up
                stack.append((i - 1, j))
        return -1, grid
    
    # Implement Best First Search
    @staticmethod
    def best_first_search(grid: List[List[str]]) -> Tuple[int, List[List[str]]]:
        start = None
        target = None
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 's':
                    start = (i, j)
                if grid[i][j] == 't':
                    target = (i, j)
        
        if start == None or target == None:
            return -1, grid
        
        currMove = 1
        pq = PriorityQueue()
        pq.put((0, start))
        while pq.qsize() > 0:
            (filler, coord) = pq.get()
            i = coord[0]
            j= coord[1]
            
            if grid[i][j] == 't':
                return 1, grid
            elif grid[i][j] == '0':
                grid[i][j] = str(currMove)
                currMove += 1
            if i - 1 >= 0 and (grid[i - 1][j] == '0' or grid[i - 1][j] == 't'): #up
                pq.put((abs(i - 1 - target[0]) + abs(j - target[1]), (i - 1, j)))
            if j + 1 < len(grid[0]) and (grid[i][j + 1] == '0' or grid[i][j + 1] == 't'): #right
                pq.put((abs(i - target[0]) + abs(j + 1 - target[1]), (i, j + 1)))
            if i + 1 < len(grid) and (grid[i + 1][j] == '0' or grid[i + 1][j] == 't'): #down
                pq.put((abs(i + 1 - target[0]) + abs(j - target[1]), (i + 1, j)))
            if j - 1 >= 0 and (grid[i][j - 1] == '0' or grid[i][j - 1] == 't'): #left
                pq.put((abs(i - target[0]) + abs(j - 1 - target[1]), (i, j - 1)))
                
        return -1, grid
    
    # Implement A* Search
    @staticmethod
    def a_star_search(grid: List[List[str]]) -> Tuple[int, List[List[str]]]:
        start = None
        target = None
        distGrid = []
        for i in range(len(grid)):
            distGridRow = []
            for j in range(len(grid[0])):
                
                if grid[i][j] == 's':
                    start = (i, j)
                    distGridRow.append(0)
                elif grid[i][j] == 't':
                    target = (i, j)
                    distGridRow.append(float('inf'))
                else:
                    distGridRow.append(float('inf'))
            distGrid.append(distGridRow)
        
        if start == None or target == None:
            return -1, grid
        
        currMove = 1
        pq = PriorityQueue()
        pq.put((0, start, 0))
        while pq.qsize() > 0:
            (priority, coord, distFromS) = pq.get()
            i = coord[0]
            j= coord[1]
            
            if grid[i][j] == 't':
                return 1, grid
            elif grid[i][j] == '0':
                grid[i][j] = str(currMove)
                currMove += 1
            if i - 1 >= 0 and distFromS + 1 < distGrid[i - 1][j] and ((not grid[i - 1][j] == '-1' and not grid[i - 1][j] == 's') or grid[i - 1][j] == 't'): #up
                distGrid[i - 1][j] = distFromS + 1
                pq.put((distGrid[i - 1][j] + abs(i - 1 - target[0]) + abs(j - target[1]), (i - 1, j), distFromS + 1))
            if j + 1 < len(grid[0]) and distFromS + 1 < distGrid[i][j + 1] and ((not grid[i][j + 1] == '-1' and not grid[i][j + 1] == 's') or grid[i][j + 1] == 't'): #right
                distGrid[i][j + 1] = distFromS + 1    
                pq.put((distGrid[i][j + 1] + abs(i - target[0]) + abs(j + 1 - target[1]), (i, j + 1), distFromS + 1))
            if i + 1 < len(grid) and distFromS + 1 < distGrid[i + 1][j] and ((not grid[i + 1][j] == '-1' and not grid[i + 1][j] == 's') or grid[i + 1][j] == 't'): #down
                distGrid[i + 1][j] = distFromS + 1
                pq.put((distGrid[i + 1][j] + abs(i + 1 - target[0]) + abs(j - target[1]), (i + 1, j), distFromS + 1))
            if j - 1 >= 0 and distFromS + 1 < distGrid[i][j - 1] and ((not grid[i][j - 1] == '-1' and not grid[i][j - 1] == 's') or grid[i][j - 1] == 't'): #left
                distGrid[i][j - 1] = distFromS + 1
                pq.put((distGrid[i][j - 1] + abs(i - target[0]) + abs(j - 1 - target[1]), (i, j - 1), distFromS + 1))
                
        return -1, grid
    
    # Implement Greedy Search
    @staticmethod
    def greedy_search(grid: List[List[str]]) -> Tuple[int, List[List[str]]]:
        start = None
        target = None
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 's':
                    start = (i, j)
                elif grid[i][j] == 't':
                    target = (i, j)
        
        if start == None or target == None:
            return -1, grid
        
        currMove = 1
        currentPos = list(start)
        while True:
            if grid[currentPos[0]][currentPos[1]] == 't': #target found
                return 1, grid
            elif grid[currentPos[0]][currentPos[1]] == '0': #update grid
                grid[currentPos[0]][currentPos[1]] = str(currMove)
                currMove += 1
            if currentPos[1] < target[1] and (grid[currentPos[0]][currentPos[1] + 1] == '0' or grid[currentPos[0]][currentPos[1] + 1] == 't'): #need to move right
                currentPos[1] += 1
            elif currentPos[0] < target[0] and (grid[currentPos[0] + 1][currentPos[1]] == '0' or grid[currentPos[0] + 1][currentPos[1]] == 't'): #need to move down
                currentPos[0] += 1
            elif currentPos[1] > target[1] and (grid[currentPos[0]][currentPos[1] - 1] == '0' or grid[currentPos[0]][currentPos[1] - 1] == 't'): #need to move left
                currentPos[1] -= 1
            elif currentPos[0] > target[0] and (grid[currentPos[0] - 1][currentPos[1]] == '0' or grid[currentPos[0] - 1][currentPos[1]] =='t'): #need to move up
                currentPos[0] -= 1
            else:
                return -1, grid
                
        

if __name__ == "__main__":

    
    example = [
        ['0', '0', '0', '0', '0', '0', '0', '-1', '0', '0'],
        ['0', '0', '-1', '0', '0', '0', '0', '0', '0', '-1'],
        ['0', '-1', '-1', '0', '-1', '-1', '-1', '0', '-1', '0'],
        ['0', '0', '0', '0', '-1', '0', '0', '0', '-1', '0'],
        ['0', '-1', 't', '0', '0', '0', '-1', '-1', '0', '-1'],
        ['0', '0', '-1', '0', '-1', '0', '0', '0', '0', '0'],
        ['0', '0', '0', '0', '-1', '0', '-1', '0', '0', '0'],
        ['0', '0', '0', '0', '0', '0', '0', '-1', '0', '0'],
        ['0', 's', '-1', '0', '-1', '0', '0', '0', '0', '0'],
        ['-1', '0', '0', '0', '0', '-1', '-1', '-1', '0', '-1']
    ]
    
    example = [
        ['0', '0', '-1', '0', '0', '0', '0', '0', '0', '-1'],
        ['-1', '0', '-1', '0', 't', '-1', '0', '0', '-1', '-1'],
        ['-1', '0', '-1', '0', '0', '0', '0', '-1', '0', '0'],
        ['-1', '0', '0', '0', '0', '0', '0', '-1', '0', '-1'],
        ['-1', '0', '-1', '0', '-1', '-1', '0', '-1', '-1', '-1'],
        ['-1', '0', '0', '0', '-1', '0', '0', '-1', '0', '-1'],
        ['-1', '0', '-1', '-1', '-1', '-1', '0', '0', '0', '-1'],
        ['-1', '0', '0', '-1', 's', '0', '0', '0', '-1', '0'],
        ['0', '-1', '0', '0', '0', '0', '0', '-1', '-1', '0'],
        ['0', '-1', '0', '0', '0', '0', '0', '0', '0', '0']
    ]
    
    
    
    input_string = """0 0 -1 0 0 0 0 0 0 -1
-1 0 -1 0 t -1 0 0 -1 -1
-1 0 -1 0 0 0 0 -1 0 0
-1 0 0 0 0 0 0 -1 0 -1
-1 0 -1 0 -1 -1 0 -1 -1 -1
-1 0 0 0 -1 0 0 -1 0 -1
-1 0 -1 -1 -1 -1 0 0 0 -1
-1 0 0 -1 s 0 0 0 -1 0
0 -1 0 0 0 0 0 -1 -1 0
0 -1 0 0 0 0 0 0 0 0  """

    # Split the input string into rows
    rows = input_string.split('\n')

    # Split each row into individual elements and replace numbers with -1 with 0
    two_d_array = [[x if x in ['s', 't', '-1'] else '0' for x in row.split()] for row in rows]

    # Print the resulting 2D array
    for row in two_d_array:
        #print(row)
        pass


    #found, final_state = SearchAlgorithm.uniform_search(example)
    #found, final_state = SearchAlgorithm.dfs(example)
    #found, final_state = SearchAlgorithm.bfs(example)
    #found, final_state = SearchAlgorithm.best_first_search(example)
    found, final_state = SearchAlgorithm.a_star_search(example)
    #found, final_state = SearchAlgorithm.greedy_search(example)
    
    if found == 1:
        print("Target found!")
    else:
        print("Target not found.")

    for row in final_state:
        print(' '.join(row))
