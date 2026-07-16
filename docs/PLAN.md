Chess app:

- This is a rough plan to make the chess app
- Features to include:
	* Visual board - may need external language for frontend? Need to draw the board somehow, 
	something similar to Pygame but for cpp. Need to do this last as logic is more important


	* Use arrays to create board, or maybe vector as it's dynamic
	* Chess logic in backend php:
			>main.cpp
			>Piece.cpp/h
			>Board.cpp/h
			>game.cpp/h
	* Need database? For now, no, JSON is just fine


			 
	User Stories                  |                Acceptance test                          |				
As a user, when I open the app,	  |  When the user opens the app, the user gets an option to play,					
I will see a home menu.           |  change settings or exit.
								  |  


As a user, when I'm in the home    |When the user is in analysis mode, they can import PGN of games to analyse
menu, I can analyse my games with  |When the user is in analysis mode, they can see Stockfish analysis of game
the chess engine				   |When the user is NOT in analysis mode and press analyse game eternally
								   |they get redirected to analysis mode.


As a User, When I am in the menu  | When the user presses play, they get an option to play PVP, with a bot or Online (in the future) 
and press play,I want to choose   | When the user does not press play from the menu, they cannot choose these options.
how I play                  				  
 
As a User, I will have a choice of | When the user chooses the easiest mode - they will play a 500 ELO bot
bots to play against.			   | When the user presses chooses intermediate mode - they will play a 1000 elo bot
								   | When the user chooses hard they will play a 1500 elo bot
								   | When the user chooses master they will play a 2000 elo bot
								   | When the user chooses grandmaster they will play a 2500 elo bot
									 
As a user, I want to see the chess |
board so that I can play the game. |	When a game starts, an 8×8 board is displayed with all pieces in their 
								   |	starting positions.

As a user, I want to move chess    | When the user selects a valid piece and destination square, the piece moves.
pieces so that I can play chess.   | When the user attempts an illegal move, the piece does not move.
								   | The user receives feedback when a move is invalid.


As a user, I want the game to      | When a player makes a move, the turn changes to the opposing player.
manage turns so that players       | When it is not the user's turn, they cannot make a move.
cannot move out of order.          |


As a user, I want the game to      | When a king is under attack, the game displays that the player is in check.
detect check so that I know when   | When the player is no longer under attack, the check message is removed.
my king is threatened.             |


As a user, I want the game to      | When a player has no legal moves to escape check, the game ends.
detect checkmate so that I know    | The winning player is displayed.
when the game has finished.        | 


As a user, I want to save my        | When the user saves a game, the current board state and move history are stored.
games so that I can review them     | When the user loads a saved game, the previous board state is restored.
later.                              | Games are stored using JSON/PGN files.

As a user, I want to play en passant| When en passant conditions occur, the user can play the move
if it is legal.						|
		
As a user, I want to castle my king | When castling conditions occur, the user can play the move
if it is legal.						| If the user wants to castle, they can castle kingside or queenside
									|

As a user, I want my pawn to      | When a pawn reaches the opposite side of the board, the user can choose to promote
promote when it reaches the       | it into a queen, rook, bishop or knight.
end of the board.                 | The pawn is replaced with the selected piece.
                                  | Promotion can result in check or checkmate.


As a user, I want the game to     | When a player has no legal moves available but is not in check, the game
detect stalemate.                 | ends as a draw.
                                  | The game does not declare a winner.


As a user, I want the game to     | When neither player has enough material to achieve checkmate, the game
detect insufficient material.     | ends as a draw.
                                  | Examples include king vs king or king and bishop vs king.


As a user, I want the game to     | When the same board position occurs three times, the game can detect a
detect repeated positions.        | threefold repetition draw.
                                  | Previous board states are stored and compared.


As a user, I want the game to     | When 50 moves occur without a pawn move or capture, the game can detect
detect the fifty-move rule.       | a possible draw.
                                  | The move counter resets after a pawn move or capture.


As a user, I want the game to     | When I attempt to move my king into check, the move is rejected.
prevent illegal king moves.       | The user cannot move into a square controlled by an opponent piece.


As a user, I want pinned pieces   | When a piece is protecting the king, the user cannot move that piece if
to be handled correctly.          | it exposes the king to check.
                                  | The game prevents moves that leave the player's king in danger.


As a user, I want the game to     | When a player is in double check, only legal king moves are allowed.
handle double check situations.   | The player cannot block or capture one of the attacking pieces unless it
                                  | removes the check.


As a user, I want the game to     | When moving a piece reveals an attack on the opponent's king, the game
detect discovered checks.         | recognises it as check.
                                  | The opponent must respond to the check.


As a user, I want to undo moves   | When the user selects undo during analysis mode, the previous board state
during analysis.                  | is restored.
                                  | The move history is updated correctly after undoing.


As a user, I want saved games     | When the user loads a saved game, the board position, turn order, move
to restore correctly.             | history, castling rights and en passant availability are restored.
                                  | The game continues from the saved position.