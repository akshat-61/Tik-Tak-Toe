import random

def printboard(board):
    for row in range(3):
        print(" | ".join(board[row]))
        if row < 2:
            print("-" * 5)

def checkwinner(board, player):
    for row in range(3):
        if all([board[row][col] == player for col in range(3)]):
            return True
    for col in range(3):
        if all([board[row][col] == player for row in range(3)]):
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

def boardfull(board):
    return all([board[row][col] != " " for row in range(3) for col in range(3)])

def minimax(board, depth, is_maximizing):
    if checkwinner(board, "O"):
        return 10 - depth
    if checkwinner(board, "X"):
        return depth - 10
    if boardfull(board):
        return 0
    
    if is_maximizing:
        best = -float('inf')
        for row in range(3):
            for col in range(3):
                if board[row][col] == " ":
                    board[row][col] = "O"
                    best = max(best, minimax(board, depth + 1, False))
                    board[row][col] = " "
        return best
    else:
        best = float('inf')
        for row in range(3):
            for col in range(3):
                if board[row][col] == " ":
                    board[row][col] = "X"
                    best = min(best, minimax(board, depth + 1, True))
                    board[row][col] = " "
        return best

def bestmove(board):
    bestval = -float('inf')
    move = (-1, -1)
    for row in range(3):
        for col in range(3):
            if board[row][col] == " ":
                board[row][col] = "O"
                moveval = minimax(board, 0, False)
                board[row][col] = " "
                if moveval > bestval:
                    bestval = moveval
                    move = (row, col)
    return move

def play_game():
    board = [[" " for _ in range(3)] for _ in range(3)]
    while True:
        printboard(board)
        
        print("Your turn (X). Enter row and column (0-2) separated by space:")
        row, col = map(int, input().split())
        if board[row][col] != " ":
            print("Invalid move! Try again.")
            continue
        board[row][col] = "X"
        
        if checkwinner(board, "X"):
            printboard(board)
            print("Congratulations, you win!")
            break
        
        if boardfull(board):
            printboard(board)
            print("It's a draw!")
            break
        
        print("AI's turn (O)...")
        row, col = bestmove(board)
        board[row][col] = "O"
        
        if checkwinner(board, "O"):
            printboard(board)
            print("AI wins!")
            break
        
        if boardfull(board):
            printboard(board)
            print("It's a draw!")
            break

if __name__ == "__main__":
    play_game()
