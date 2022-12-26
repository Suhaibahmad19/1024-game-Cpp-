
1024
You will implement a single player game “1024” in C++. 
Step1:
At start of the game, a 2D grid of 4 x 4 cells will appear, with any two cells initialized to 1 or 2 and the rest of the cells will be empty.

Sample grid 1:							Sample grid 2:
                                                         

Now, the player has 4 options:
⦁	Swipe left (letter key l)
⦁	Swipe right (letter key r)
⦁	Swipe up (letter key u)
⦁	Swipe down (letter key d)
Step 2:
In the sample grid 1 if the player moves towards left, all the cells will be shifted towards left and a random new cell will be initialized with 1 or 2 as shown in the figure below:
 
Similarly, in the sample grid 2, if the player moves downwards, all the cells will be shifted downwards and a random new cell will be initialized with 1 or 2 as shown in the figure below:
 

Step 3:
Now in sample grid 2, if the player moves towards right, all values will move towards right and similar values will be combined and replaced by their sum, and a random new cell will be initialized with 1 or 2 as shown below:
 
The game can end in either of the following two scenarios:
⦁	The value of one of the cells becomes 1024, in which case the player wins, as shown in the figure below:

 

⦁	The whole grid is filled with numbers and no two adjacent cells have same value, in which case the player loses, as shown in the figure below:
 


Task:
Your task is to implement this single player game. Keep in mind that after every move, the screen must be cleared and new grid will be printed. You can implement this project with or without graphics. 

Evaluation:
Your logic will be evaluated via your code and a viva. If code is plagiarized, the whole group will be awarded F grade. Each member should do his/her own share of work in the project otherwise he/she will be singled out during viva and will not be given same marks as the other group members.

You can play this game here to get a better understanding:
https://1024game.org/


Good Luck
