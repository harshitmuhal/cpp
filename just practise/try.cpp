#include<iostream>
#include<math.h>
using namespace std;


bool canplace(int board[20][20],int i,int j,int no,int n){
    
    //horizontal
    for(int k=0;k<n;k++){
        if(board[i][k]==no){
            return false;
        }
    }
    //vertical
    for(int k=0;k<n;k++){
        if(board[k][j]==no){
            return false;
        }
    }
    //subgrid
    int s=sqrt(n);
    int sx=(i/s)*s;
    int sy=(j/s)*s;
    for(int k=sx;k<sx+s;k++){
        for(int x=sy;x<sy+s;x++){
            if(board[k][j]==no){
                return false;
            }
        }
    }
    return true;
}



void solvesudoku(int board[20][20],int i,int j,int n){
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    
    if(j==n){
        solvesudoku(board,i+1,0,n);
    }
    
    if(board[i][j]!=0){
        solvesudoku(board,i,j+1,n);
    }
    
    for(int no=1;no<=n;no++){
        if(canplace(board,i,j,no,n)){
            board[i][j]=no;
            solvesudoku(board,i,j+1,n);
            board[i][j]=0;
        }
    }
    
}



int main()
{
    int n;
    cin>>n;
    int board[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    solvesudoku(board,0,0,n);
    
    return 0;
}
