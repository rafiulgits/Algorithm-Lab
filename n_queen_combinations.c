#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define MAX 10

int board[MAX];
int total_solution = 0;

void n_queen(int row);
void show_solution();
bool is_safe(int row, int col);

int n;

int main()
{
    printf("N: "); scanf("%d",&n);
    n_queen(1);
    return 7;
}

void n_queen(int row)
{
    register int col;
    for(col=1; col<=n; col++)
    {
        if(is_safe(row, col))
        {
            board[row] = col;
            if(row == n)
                show_solution();
            else
                n_queen(row+1);
        }
    }
}
void show_solution()
{
    total_solution++;
    printf("Solution: %d\n", total_solution);
    register int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(board[i] == j)
                printf(" %c ",'Q');
            else
                printf(" %c ", '-');
        }
        puts("");
    }

    puts("\n\n");
}

bool is_safe(int row, int col)
{
    register int i;
    for(i=1; i<row; i++)
    {
        // diagonally check
        if(abs(board[i]-col) == abs(i-row))
            return false;
        if(board[i] == col)
            return false;

    }
    return true;
}
