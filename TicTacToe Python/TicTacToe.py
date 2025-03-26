def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_win(board, player):
    for i in range(3):
        if all([board[i][j] == player for j in range(3)]) or \
           all([board[j][i] == player for j in range(3)]):
            return True
    if all([board[i][i] == player for i in range(3)]) or \
       all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

def tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    player1 = "X"
    player2 = "O"
    current_player = player1
    moves = 0

    print("Tic-Tac-Toe Game")
    print_board(board)

    while moves < 9:
        try:
            row = int(input(f"Player {current_player}, enter row (0-2): "))
            col = int(input(f"Player {current_player}, enter column (0-2): "))
        except ValueError:
            print("Invalid input. Please enter numbers between 0 and 2.")
            continue
        
        if 0 <= row <= 2 and 0 <= col <= 2 and board[row][col] == " ":
            board[row][col] = current_player
            print_board(board)
            moves += 1

            if check_win(board, current_player):
                print(f"Player {current_player} wins!")
                break

            current_player = player2 if current_player == player1 else player1
        else:
            print("Invalid move. Try again.")

    if moves == 9 and not check_win(board, player1) and not check_win(board, player2):
        print("It's a tie!")

tic_tac_toe()