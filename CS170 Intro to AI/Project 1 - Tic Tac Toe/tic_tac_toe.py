import random

class TTT_cs170_judge:
    def __init__(self):
        self.board = []
        
    def create_board(self, n):
        for i in range(n):
            row = []
            for j in range(n):
                row.append('-')
            self.board.append(row)
            
    def display_board(self):
        for row in self.board:
            print(" ".join(row))
        print()
            
    def is_winner(self, player):
        # Check rows
        for row in self.board:
            if all([cell == player for cell in row]):
                return True
        
        # Check columns
        for col in range(len(self.board)):
            if all([self.board[row][col] == player for row in range(len(self.board))]):
                return True
        
        # Check diagonals
        if all([self.board[i][i] == player for i in range(len(self.board))]):
            return True
        if all([self.board[i][len(self.board) - i - 1] == player for i in range(len(self.board))]):
            return True
        
        return False
    
    def is_board_full(self):
        return all([cell in ['X', 'O'] for row in self.board for cell in row])
    

class Player_1:
    def __init__(self, judge):
        self.board = judge.board
    
    def my_play(self):
        while True:
            row, col = map(int, input("Enter the row and column numbers separated by space: ").split())
            
            if 1 <= row <= len(self.board) and 1 <= col <= len(self.board[0]):
                self.board[row-1][col-1] = 'X'
                break
            else:
                print("Wrong coordination!")


class Player_2:
    def __init__(self, judge):
        self.judge = judge
        self.board = judge.board
    
    def my_play(self):
        # Minimax for AI
        minPoints = float('-inf')
        coordx = 0
        coordy = 0
        for i in range(len(self.board)):
            for j in range(len(self.board[0])):
                if self.board[i][j] == '-':
                    self.board[i][j] = 'O'
                    tempPoints = self.MiniMax(self.board, False, float('-inf'), float('inf'))
                    self.board[i][j] = '-'
                    if tempPoints > minPoints:
                        minPoints = tempPoints
                        coordx = i
                        coordy = j
        self.board[coordx][coordy] = 'O'
        
                    
    def MiniMax(self, tempBoard, isMax, alpha, beta):
        if self.judge.is_winner('O'):
            return 1
        elif self.judge.is_winner('X'):
            return -1
        elif self.judge.is_board_full():
            return 0
        if isMax:
            maxPoints = float('-inf')
            for i in range(len(self.board)):
                for j in range(len(self.board[0])):
                    if tempBoard[i][j] == '-':
                        tempBoard[i][j] = 'O'
                        maxPoints = max(maxPoints, self.MiniMax(tempBoard, False, alpha, beta))
                        tempBoard[i][j] = '-'
                        alpha = max(alpha, maxPoints)
                        if beta <= alpha:
                            break
            return maxPoints
        else:
            minPoints = float('inf')
            for i in range(len(self.board)):
                for j in range(len(self.board[0])):
                    if tempBoard[i][j] == '-':
                        tempBoard[i][j] = 'X'
                        minPoints = min(minPoints, self.MiniMax(tempBoard, True, alpha, beta))
                        tempBoard[i][j] = '-'
                        beta = min(beta, minPoints)
                        if beta <= alpha:
                            break
            return minPoints

# Main Game Loop
def game_loop():
    n = 3  # Board size
    game = TTT_cs170_judge()
    game.create_board(n)
    
    starter = random.randint(0, 1)
    win = False
    
    player1 = Player_1(game)
    player2 = Player_2(game)
    
    if starter == 0:
        print("Player 1 starts.")
        while not win:
            game.display_board()
            player1.my_play()
            win = game.is_winner('X')
            game.display_board()
            if win:
                print("Player 1 wins!")
                break
            if game.is_board_full():
                print("It's a tie!")
                break

            game.display_board()
            player2.my_play()
            win = game.is_winner('O')
            game.display_board()
            if win:
                print("Player 2 wins!")
                break
            if game.is_board_full():
                print("It's a tie!")
                break
    else:
        print("Player 2 starts.")
        while not win:
            game.display_board()
            player2.my_play()
            win = game.is_winner('O')
            game.display_board()
            if win:
                print("Player 2 wins!")
                break
            if game.is_board_full():
                print("It's a tie!")
                break
            
            game.display_board()
            player1.my_play()
            win = game.is_winner('X')
            game.display_board()
            if win:
                print("Player 1 wins!")
                break
            if game.is_board_full():
                print("It's a tie!")
                break

#game_loop()
