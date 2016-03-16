// I did the code in code blocks because i don't have internet access at home and i don't have Visual Basics
//Which is why I have a few commits
#include <iostream>

using namespace std;

class TicTacToe
{
private:
	char arr[5][5];
	char player;
	int moves;
public:
	TicTacToe();
	void Reset();
	void print();
	int move(int row, int col);
	void makeMove(int row, int col);
	int results(int p);
	int getMoves();
	void setPlayer();
	char getPlayer();
	void over();
	~TicTacToe();
};

TicTacToe::TicTacToe()
{
	setPlayer();
	Reset();
}

void TicTacToe::over()
{
	if (results('O') == 1)
	{
		cout << "Player O Wins" << endl;
	}
	else if (results('X') == 1)
	{
		cout << "Player X Wins" << endl;
	}
	else if (results('X') == 10)
	{
		cout << "It's a draw";
	}
	else{
		cout << "Game is still in Progress";
	}
}

int TicTacToe::getMoves()
{
	return moves;
}

char TicTacToe::getPlayer()
{
	return player;
}
void TicTacToe::makeMove(int row, int col)
{
	if (move(row, col) == 1)
	{
		arr[row][col] = player;
		setPlayer();
		moves++;
	}
	else{
		cout << "invalide move, re-play" << endl;
	}
}
void TicTacToe::setPlayer()
{
	if (player == 'O')
	{
		player = 'X';
	}
	else{
		player = 'O'; //capital letter
	}
}
// 1 the player won : 0 the player didn't win : 10 draw
int TicTacToe::results(int p)// change p to currentPlayer
{
	if (arr[0][0] == p && arr[2][0] == p && arr[4][0] == p)
	{
		return 1;
	}
	else if (arr[0][0] == p && arr[0][2] == p && arr[0][4] == p)
	{
		return 1;
	}
	else if (arr[0][0] == p && arr[2][2] == p && arr[4][4] == p)
	{
		return 1;
	}
	else if (arr[0][2] == p && arr[2][2] == p && arr[4][2] == p)
	{
		return 1;
	}
	else if (arr[2][0] == p && arr[2][2] == p && arr[2][4] == p)
	{
		return 1;
	}
	else if (arr[0][4] == p && arr[2][2] == p && arr[4][0] == p)
	{
		return 1;
	}
	else if (arr[0][4] == p && arr[2][4] == p && arr[4][4] == p)
	{
		return 1;
	}
	else if (arr[4][0] == p && arr[4][2] == p && arr[4][4] == p)
	{
		return 1;
	}
	else if (moves == 9)
	{
		return 10;
	}
	else return 0;
}
int TicTacToe::move(int row, int col)//returns 1 if its a valid move
{
	if (arr[row][col] == ' ')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void TicTacToe::Reset()
{
	int i, j;
	for (i = 0; i <= 4; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			if (i == 0 || i == 2 || i == 4)
			{
				if (j == 1 || j == 3)
				{
					arr[i][j] = '|';
				}
				else
				{
					arr[i][j] = ' ';
				}
			}
			else if (i == 1 || i == 3)
			{
				arr[i][j] = '-';
			}
			else
			{
				arr[i][j] = ' ';
			}
		}
	}
	moves = 0;
}

void TicTacToe::print()
{
	cout << arr[0][4] << endl;
	int i, j;
	for (i = 0; i <= 4; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
TicTacToe::~TicTacToe()
{

}
int main()
{
	TicTacToe obj;
	//senario 1: x wins
	obj.makeMove(0, 0); //x
	obj.print();
	obj.makeMove(0, 0); //y invalid move
	obj.print();
	obj.makeMove(4, 2);//y
	obj.print();
	obj.makeMove(2, 0);//x
	obj.print();
	obj.makeMove(2, 2);//y
	obj.print();
	obj.over();
	obj.makeMove(4, 0);//x
	obj.print();
	cout << "New Game \n\n" << endl;
	obj.over();
	//senario 2: draw
	obj.Reset();
	obj.makeMove(0, 0); //x
	obj.print();
	obj.makeMove(0, 0); //y invalid move
	obj.print();
	obj.makeMove(2, 0);//y
	obj.print();
	obj.makeMove(4, 0);//x
	obj.print();
	obj.makeMove(0, 2);//y
	obj.print();
	obj.makeMove(0, 4); //x
	obj.print();
	obj.makeMove(2, 2); //y
	obj.print();
	obj.makeMove(4, 2);//x
	obj.print();
	obj.makeMove(4, 4);//y
	obj.print();
	obj.makeMove(2, 4);//x
	obj.print();
	obj.over();

	/* cout << "New Game\nFirst Player is O\n Enter row and column 1-5\nEnter 9,1 for display\nEnter 9,2 for results"<< endl;
	while(obj.getMoves() !=9)
	{
	cout << "Player " << obj.getPlayer() << endl;
	cin >>row;
	cin >>col;
	if(row ==9)
	{
	if(col ==1)
	obj.print();
	else
	cout<< obj.results(obj.getPlayer())<< endl;
	}
	else
	{
	obj.makeMove(row,col);
	}
	}

	*/
	//Short commings :only checks game status if requested
	// so the game continues even if one player has won
	// Solution : for every move call the results() if its 1(player wins) then call over() which will show that a player has won
	//should the reset be immedietly after a player has won /draw?
	//should the print be called before reseting data?
}
