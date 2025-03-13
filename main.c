#include <stdio.h>

#include <stdio.h>

// Function to display the board
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
            if (board[i][j] == playernum + '0') { // Convert playernum to character
                board[i][j] = symbol;
            }
        }
    }
}

// Function to check for a win
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
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

    // Game loop
    while (1) {
        displayBoard(board);

        // Input player number and symbol
        if (turn % 2 == 0) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }

        printf("Player %d (%c), enter a number (1-9): ", turn % 2 + 1, symbol);
        scanf("%d", &playernum);

        // Update the board based on the input
        updateBoard(board, playernum, symbol);

        // Check for a win
        if (checkWin(board)) {
            displayBoard(board);
            printf("Player %d (%c) wins!\n", turn % 2 + 1, symbol);
            break;
        }

        // Increment turn
        turn++;

        // Check for a draw
        if (turn == 9) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

/*
		printf(" %d | %d | %d  \n" , array[0][0] , array[0][1] , array[0][2]);
		printf("------------\n");
		printf(" %d | %d | %d  \n" , array[1][0] , array[1][1] , array[1][2]);
		printf("------------\n");
		printf(" %d | %d | %d  \n" , array[2][0] , array[2][1] , array[2][2]);*/
		