# Operating-system-project
OS project 


<br><h1>About Project</h1>
<h3>Phase I (Ludo board game)	</h3>
 
Ludo is a strategy board game for two to four players, in which the players race their four tokens from start to finish according to the rolls of a single dies. This project consists of designing a multithreaded application of Ludo for four players each having maximum four tokens. Two, three or four can play, without partnerships. At the beginning of the game, each player’s tokens are out of play and staged in the player's yard (one of the large corner areas of the board in the player's color). When able to, the players will enter their tokens one per time on their respective starting squares, and proceed to race them clockwise around the board along the game track (the path of squares not part of any player’s home column).  When reaching the square below his home column, a player continues by moving tokens up the column to the finishing square. 


<h3>Rules: </h3>
<br> 
•	Each player rolls the die. 
<br>•	Players take turns sequentially 
<br>•	To enter a token into play from its yard to its starting square, a player must roll a 6. If the player has no tokens yet in play and rolls other than a 6, the turn passes to the next player. Once a player has one or more tokens in play, he selects a token and moves it forwards along the track the number of squares indicated by the die. Players must always move a token according to the die value rolled. 
<br>•	Passes are not allowed; if no move is possible, the turn moves to the next player.  
<br>•	A player will keep on throwing the dice if six comes. 
<br>•	Three consecutive sixes will result in loss of turn and all his numbers in that turn will  be discarded. 
<br>•	When a 6 is rolled, the player may choose to advance a token already in play, or may enter another staged token to its starting square. Rolling a 6 earns the player an additional or "bonus" roll in that turn. If the bonus rolls results in a 6 again, the player earns an additional bonus roll. If the third roll is also a 6, the player may not move and the turn immediately passes to the next player. 
<br>•	Players may not end their move on a square they already occupy. If the advance of a token ends on a square occupied by an opponent's token, the opponent token is returned to its owner's yard. The returned token can be reentered into play only when the owner rolls a 6. 
<br>•	There are some "safe" squares on the game track which protect a player's tokens from being returned. They are shown in the board with player colors. A player's home column squares are always safe, however, since no opponent may enter them. 
<br>•	If a piece lands upon a piece of the same color, this forms a block. This block cannot be passed or landed on by any opposing piece. 
<br>•	When a piece has circumnavigated the board, it proceeds up the home column. A piece can only be moved onto the home triangle by an exact throw. 
<br>•	A player should not be allowed to enter into his Home column until he has removed at least one opposing piece. 
<br>•	The first person to move all 4 pieces into the home triangle wins. 
<br>There are several different ways of multithreading this application. One suggested strategy is to create threads that check the following criteria: 
 
<br>•	Four threads are created and will be assigned to each player. 
<br>•	A thread to check each row and column of the grid to find out the token and player to be passed for completion. This thread should run randomly to check the hitting token and victim player. 
<br>•	One thread known as “Master thread” should track for all four players of hit record as no token can enter into its home column if its hit rate is 0. The property of this thread is it can cancel all the other four threads in certain situations. For example: The stopping criteria or thread cancelation will be as follows:
<br>o	For consecutive 20 turns if any player can’t get a 6 in a die or cannot hit any opponent player, he/she will be kicked out from the game. (Cancelled by this thread). 
<br>o	When all tokens of a player reach its home, it will send the signal to this master thread about its completion. The master thread will verify and the kill the respective thread after calculating its position. 
