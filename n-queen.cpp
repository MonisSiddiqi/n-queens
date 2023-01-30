#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
int count = 0;
bool isSafe(vector<string> &board, int row, int col)
{   
    int tRow = row;
    int tCol = col;

    //We only need to check 3 dicections
    //1.Checking upper left diagonal
    while(tRow>=0 && tCol>=0)
    {
        if(board[tRow--][tCol--]=='Q')
         return false;
    }
   
    tRow = row;
    tCol = col;
    //Checking columns of same row
    while(tCol>=0)
    {
        if(board[tRow][tCol--]=='Q')
         return false;
    }

    tRow = row;
    tCol = col;
    //Checking lower left diagonal
    while(tCol>=0 && tRow<board.size())
    {
        if(board[tRow++][tCol--]=='Q')
         return false;
    }

    return true;
}
void queen(vector<string> &board, vector<vector<string>> &ans, int col)
{ 
  if(col==board.size())
  {
    ans.push_back(board);
    count++;
    return;
  }
  for(int row=0; row<board.size(); row++)
  {
    if(isSafe(board,row,col))
    {
        board[row][col]='Q';
        queen(board,ans,col+1);
        board[row][col]='.';
    }
  }
}
int main()
{   
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cout<<"Enter the board size\n";
    int n;
    cin>>n;

    vector<vector<string>> ans;

    vector<string> board(n);

    string s(n,'.');
    for(int i=0; i<n; i++)
     board[i]=s;
    
    queen(board,ans,0);
    
    //Printing the solutions
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            for(int k=0; k<ans[i][j].size(); k++)
            {
                cout<<ans[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"Total solutions = "<<count<<endl;
    getch();
}