#include<iostream>
using namespace std;

void DisplayBoard(char arr[][3])
{
	system("cls");
 	cout << "     |     |     " << endl;
    cout << "  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << arr[2][0]<< "  |  " << arr[2][1] << "  |  " << arr[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

bool match(char arr[][3], int &player1, int &player2)
{
	bool match=false;
	//First row
	if(arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X')
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Second Row
	else if(arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X')
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Third Row
	else if(arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X')
	{
		match=true;
		player1=1;
		return match;
	}
	
	//First Column
	else if(arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X')
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Second Column
	else if(arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X')
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Third Column
	else if(arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X')
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Diagonal down right
	else if((arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X') || (arr[2][2]=='X'  && arr[1][1]=='X' && arr[0][0]=='X' )) 
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Diagonal down left
	else if((arr[0][2]=='X' && arr[1][1]=='X' && arr[2][2]=='X') || (arr[2][2]=='X' && arr[1][1]=='X' && arr[0][2]=='X'))
	{
		match=true;
		player1=1;
		return match;
	}
	
	//Player 2
	
	//First row
	if(arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O')
	{
		match=true;
		player2=2;
		return match;
	}
	
	//Second Row
	else if(arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O')
	{
		match=true;
		player2=2;
		return match;
	}
	
	//Third Row
	else if(arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O')
	{
		match=true;
		player2=2;
		return match;
	}
	
	//First Column
	else if(arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O')
	{
		match=true;
		player2=2;
		return match;
	}
	
	//Second Column
	else if(arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O')
	{
		match=true;
		player2=2;
		return match;
	}
	
	//Third Column
	else if(arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O')
	{
		match=true;
		player2=2;
		return match;
	}
	
		
	//Diagonal down right
	else if((arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O') || (arr[2][2]=='O'  && arr[1][1]=='O' && arr[0][0]=='O'))
	{
		match=true;
		player2=2;
		return match;
	}
	
	//Diagonal down left
	else if((arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O') || (arr[2][0]=='O' && arr[1][1]=='O' && arr[0][2]=='O'))
	{
		match=true;
		player2=2;
		return match;
	}
	else 
	{
		return match; 
	}
}

int main()
{
	char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}},choice_p1,choice_p2;
	int count=0,check=0;
	int player1=0, player2=0;
	
	bool flag=false;
	
	
	DisplayBoard(arr);
	cout<<"\n PLayer 1 is X and Player 2 is O:";
	cout<<"\nEnter choice between 1 and 9";
	
	
	while(flag != true)
	{
		if(flag==true)
		{
			break;
		}
		else
		{
		cout<<"\nPlayer 1 turn:";
		cin>>choice_p1;

		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(choice_p1==arr[i][j])
				{
					arr[i][j]='X';
					DisplayBoard(arr);
					flag=match(arr, player1, player2);
					break;
				}
			}
		}

		}
		
		
		//P1 Turn
		count++;
		
		//At this point 9 turns have taken place so Draw function is declared here
		if(count==9 && flag!=true)
		{
		cout<<"DRAW !!!";
		exit(0);
		}	
		
		if(flag==true)
		{
			break;
		}
		else
		{
		cout<<"\nPlayer 2 turn:";
		cin>>choice_p2;
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(choice_p2==arr[i][j])
				{
					arr[i][j]='O';
					DisplayBoard(arr);
					flag=match(arr, player1, player2);
					break;
				}
			}
		}

	}
		//P2 Turn
		count++;
			
}
	
	//Winner check
	if(flag==true && player1==1)
	{
		cout<<"\nPLayer 1 Wins !!!";
	}
	else if(flag==true && player2==2)
	{
		cout<<"\nPlayer 2 Wins !!!";
	}

	
	
}
