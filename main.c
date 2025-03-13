#include <stdio.h>

#include <stdio.h>

void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n-----------\n");
    }
    printf("\n");
}

// Function to update the board based on player's input
void updateBoard(char board[3][3], int playernum, char symbol) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == playernum + '0') 
	    {
                board[i][j] = symbol;
            }
        }
    }
}
int checkWin(char board[3][3]) {
	
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int playernum;
    char symbol;
    int turn = 0;

    
    while (1) {
        displayBoard(board);

        if (turn % 2 == 0) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }

        printf("Player %d (%c), enter a number (1-9): ", turn % 2 + 1, symbol);
        scanf("%d", &playernum);

        updateBoard(board, playernum, symbol);

        if (checkWin(board)) {
            displayBoard(board);
            printf("Player %d (%c) wins!\n", turn % 2 + 1, symbol);
            break;
        }

        turn++;
	    
        if (turn == 9) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
		
