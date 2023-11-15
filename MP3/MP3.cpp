// MP3 
// Wesley Casselman
// November 13th of 2023
// 
// This program allows two players to play tic-tac-toe using the numeric keypad on the keyboard.
// The program keeps track of the score of the games and players can play until they see fit.

// Include necessary libraries and use standard namespace
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// Initialize constant for board size
const int SIZE = 9;

// Define function prototypes for the compiler's sake
int getPlayerInput(string playerName);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);
void displayGameStats(int ties, int player1Score, int player2Score, string player1Name, string player2Name);
bool playerMove(char marker, string playerName, int& playerScore, char board[]);

// Define the main funciton
int main(void)
{
	// Initialize the board
	char board[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	// Initialize score totals to zero
	int player1Score = 0;
	int player2Score = 0;
	int ties = 0;

	// Initialize variable for which player will start; player 1 is false, player 2 is true
	bool startingTurn = false;

	// Ask for user input for the names of the players
	cout << "Enter player 1 name: ";
	string player1;
	cin >> player1;
	cout << "Enter player 2 name: ";
	string player2;
	cin >> player2;

	// Loop for games
	while (true)
	{
		// Initialize moves to zero for this game
		int matchMoves = 0;
		// Initialize the player turn to be whoever will start; player 1 is false, player 2 is true
		bool playerTurn = startingTurn;

		// Loop for turns
		while (true)
		{
			system("cls");
			// If it is player 1's turn
			if (!playerTurn)
			{
				// If player 1's move causes him to win
				if ( /* update turn for player 1 */ playerMove('X', player1, player1Score, board))
				{
					// Display that player 1 won
					system("cls");
					displayBoard(board);
					cout << player1 << " wins!" << endl;
					break;
				}
			}
			else
			{
				// If player 2's move causes him to win
				if ( /* update turn for player 2 */ playerMove('O', player2, player2Score, board))
				{
					// Display that player 2 won
					system("cls");
					displayBoard(board);
					cout << player2 << " wins!" << endl;
					break;
				}
			}
			// Switch whose turn it is
			playerTurn = !playerTurn;
			// Add a move to the total
			matchMoves++;
			// If 9 moves occured all squares are necessarily filled
			if (matchMoves >= 9)
			{
				// Add one to the amount of ties
				ties++;
				// Display that it was a Cat's game
				system("cls");
				displayBoard(board);
				cout << "It's a Cat's game..." << endl;
				break;
			}
			system("pause");
		}

		// Reset the board array and display the statistics
		system("pause");
		clearBoard(board);
		displayGameStats(ties, player1Score, player2Score, player1, player2);

		// Switch who will start the next game
		startingTurn = !startingTurn;

		// Accept user input on whether to continue playing
		cout << "Continue playing (Y or N)? ";
		string word;
		cin >> word;

		// If Y for yes is entered
		if (word == "Y" || word == "y")
		{
			// Continue the game loop
			continue;
		}
		else
		{
			// Leave the game loop
			break;
		}
	}

	return 0;
}

int getPlayerInput(string playerName)
{
	cout << playerName << ", choose your move. ";
	while (true)
	{
		int move;
		cin >> move;
		if (move >= 1 && move <= 9)
		{
			return move;
		}
		cout << "Invalid move...try again. ";
	}
}
/*
	getPlayerInput - obtains the current player's input on which square to play; the square must be valid but not necessarily legal
		parameters:
			playerName - a string for the current player's name
		return:
			an integer, 1 through 9, that was entered
*/

bool isLegalMove(char board[], int location)
{
	if (location == int(board[location - 1]) - 48)
		return true;
	return false;
}
/*
	isLegalMove - determines whether at the current location, a move can be played legally
		parameters:
			board[] - a pointer to a character array that represents the squares on the board as characters
			location - an integer value of the chosen location on the board
		return:
			returns true if the location entered is legal
			returns false if the location entered is illegal
*/

void placeMarkOnBoard(char board[], char playerMark, int location)
{
	board[location - 1] = playerMark;
	return;
}
/*
	placeMarkOnBoard - marks a position on the board with the current player's marker in the board array
		parameters:
			board[] - a pointer to a character array that represents the squares on the board as characters
			playerMark - a character that is the current player's marker
			location - an integer value of the chosen location on the board
		return:
			void
*/

void clearBoard(char board[])
{
	for (int i = 0; i < SIZE; i++)
	{
		board[i] = char(i + 49);
	}
}
/*
	clearBoard - resets the board to its beginning-of-game state
		parameters:
			board[] - a pointer to a character array that represents the squares on the board as characters
		return:
			void
*/

bool hasThreeInRow(char board[], char playerMark)
{
	if (board[0] == playerMark && board[1] == playerMark && board[2] == playerMark) return true;
	if (board[3] == playerMark && board[4] == playerMark && board[5] == playerMark) return true;
	if (board[6] == playerMark && board[7] == playerMark && board[8] == playerMark) return true;
	if (board[0] == playerMark && board[3] == playerMark && board[6] == playerMark) return true;
	if (board[1] == playerMark && board[4] == playerMark && board[7] == playerMark) return true;
	if (board[2] == playerMark && board[5] == playerMark && board[8] == playerMark) return true;
	if (board[0] == playerMark && board[4] == playerMark && board[8] == playerMark) return true;
	if (board[2] == playerMark && board[4] == playerMark && board[6] == playerMark) return true;
	return false;
}
/*
	hasThreeInRow - determines whether the current marker is in three squares that make a row
		parameters:
			board[] - a pointer to a character array that represents the squares on the board as characters
			playerMark - a character that is the current player's marker
		return:
			return true if the current marker completes a row
			return false otherwise
*/

void displayBoard(char board[])
{
	printf(" %c | %c | %c \n---+---+---\n %c | %c | %c \n---+---+---\n %c | %c | %c \n\n", board[6], board[7], board[8], board[3], board[4], board[5], board[0], board[1], board[2]);
	return;
}
/*
	displayBoard - displays the current state of the board in the console window
		parameters:
			board[] - a pointer to a character array that represents the squares on the board as characters
		return:
			void
*/

void displayGameStats(int ties, int player1Score, int player2Score)
{
	printf("\nPlayer 1 score: %i\nPlayer 2 score: %i\nCat's games:    %i\n\n", player1Score, player2Score, ties);
}
/*
	displayGameStats - displays the current number of player 1 wins, player 2 wins, and ties
		parameters:
			ties - an integer count of the current number of ties
			player1Score - an integer count of the current number of player 1 wins
			player2Score - an integer count of the current number of player 2 wins
		return:
			void

		note:
			this is the function required by the project instructions and it works as intended; however, another function with
			the same name, but two extra parameters was used to be able to display the player names along with scores (see below)
*/

void displayGameStats(int ties, int player1Score, int player2Score, string player1Name, string player2Name)
{
	cout << endl << "Score for " << player1Name << ": " << player1Score << endl << "Score for " << player2Name << ": " << player2Score << endl << "Cat's games: " << ties << endl << endl;
}
/*
	displayGameStats - displays the current number of player 1 wins, player 2 wins, and ties
		parameters:
			ties - an integer count of the current number of ties
			player1Score - an integer count of the current number of player 1 wins
			player2Score - an integer count of the current number of player 2 wins
			player1Name - a string of player 1's name
			player2Name - a string of player 2's name
		return:
			void
*/

bool playerMove(char marker, string playerName, int& playerScore, char board[])
{
	int move;
	while (true)
	{
		displayBoard(board);		
		move = getPlayerInput(playerName);
		if (isLegalMove(board, move))
		{
			break;
		}
		cout << "Illegal move!" << endl;
		system("pause");
		system("cls");
	}
	placeMarkOnBoard(board, marker, move);
	if (hasThreeInRow(board, marker))
	{
		playerScore += 1;
		return true;
	}
	return false;
}
/*
	playerMove - executes the steps necessary for a player move to occur
				   - input will be provided
				   - legality of the move will be checked
				   - if legal marker will be placed on the board
				   - if the player won, one point will be added to his score
		parameters:
			marker - a character value for the current player's marker
			playerName - a string of the current player's name
			playerScore - a pointer to the current player's score
			board[] - a pointer to a character array that represents the squares on the board as characters
		return:
			return true if the current player has three in a row
			return false otherwise
*/