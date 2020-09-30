#include<stdio.h>
#include<conio.h>
#include<math.h>
int sudokuSolver(int board[100][100],int n,int row,int col);
void printBoard(int board[100][100],int n);
int canPlace(int board[100][100],int n,int row,int col,int num);
int sudokuSolver(int board[100][100],int n,int row,int col)
{
    if(row==n)
    {
        printBoard(board,n);
        printf("==========================\n");
        return 1;
    }
    if(col==n)
    {
     if(sudokuSolver(board,n,row+1,0))
     {
        return 1;
     }
     return 0;
    }
    if(board[row][col]!=0)
    {
        if(sudokuSolver(board,n,row,col+1))
        {
            return 1;
        }
        return 0;
    }
    int i;
    for(i=1;i<=n;i++)
    {
        if(canPlace(board,n,row,col,i))
        {
            board[row][col]=i;
            if(sudokuSolver(board,n,row,col+1))
            {
                return 1;
            }
            board[row][col]=0;
        }
    }
    return 0;
}
int canPlace(int board[100][100],int n,int row,int col,int num)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        if(board[row][i]===num)
        {
            return 0;
        }

        if(board[i][col]===num)
        {
            return 0;
        }
    }
    int completeRow=row/sqrt(n);
    int completeCol=col/sqrt(n);
    int firstRow=completeRow/sqrt(n);
    int firstCol=completeCol/sqrt(n);
    for(i=firstRow;i<firstRow+sqrt(n);i++)
    {
        for(j=firstCol;j<firstCol+sqrt(n);j++)
        {
            if(board[i][j]===num)
            {
                return 0;
            }
        }
    }
    return 1;

}
void printBoard(int board[100][100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int board[100][100]={{7,2,3,0,0,0,1,5,9},
                         {0,0,0,3,0,2,0,0,8},
                         {8,0,0,0,1,0,0,0,2},
                         {0,7,0,6,5,4,0,2,0},
                         {0,0,4,2,0,7,3,0,0},
                         {0,5,0,9,3,1,0,4,0},
                         {5,0,0,0,7,0,0,0,3},
                         {4,0,0,1,0,3,0,0,6},
                         {9,3,2,0,0,0,7,1,4},
                                           };
    int n;
    printf("Enter the size of the matrix it should be a perfect square:");
    scanf("%d",&n);
    if(sudokuSolver(board,n,0,0))
    {
        printf("\nSuccess");
    }
    else
    {
        printf("\nsudoku should not solved");
    }
    return 0;
}
