#include <stdio.h>

#define WIDTH      10
#define HEIGHT     10

int board[HEIGHT][WIDTH];

int Cycles = 100;

static void start_board(void)
{
    int cols, rows;
    
    for (rows = 0; rows < HEIGHT; rows++)
    {   
        for (cols = 0; cols < WIDTH; cols++)
        {    
            board[cols][rows] = 0;
            
            board[(HEIGHT / 2)][(WIDTH / 2)] = 1;
            board[((HEIGHT / 2) - 1)][((WIDTH / 2) + 1)] = 1;
            board[((HEIGHT / 2) - 1)][((WIDTH / 2) - 1)] = 1;
            board[((HEIGHT / 2) - 2)][((WIDTH / 2) + 1)] = 1;
            board[((HEIGHT / 2) - 2)][((WIDTH / 2) + 2)] = 1;
            board[((HEIGHT / 2) - 3)][((WIDTH / 2) + 1)] = 1;
            board[((HEIGHT / 2) - 3)][((WIDTH / 2) - 1)] = 1;
            board[((HEIGHT / 2) - 3)][((WIDTH / 2) - 2)] = 1;
        }
    }
}

static int xlim(int col, int prev_col)
{
    col += prev_col;
    
    while (col < 0)
    {
        col += WIDTH;
    }
    
    while (col >= WIDTH)
    {
        col -= WIDTH;
    }
    
    return col;
}

static int ylim(int row, int prev_row)
{
    row += prev_row;
    
    while (row < 0)
    {
        row += HEIGHT;
    }
    
    while (row >= HEIGHT)
    {
        row -= HEIGHT;
    }
    
    return row;
}

static int addingtoCount(int rows, int cols)
{
    int diff_y, diff_x, count;
    
    count = 0;
    
    for (diff_y = -1; diff_y <= 1; diff_y++)
    {
        for (diff_x = -1; diff_x <= 1; diff_x++) 
        {
            if (diff_y || diff_x)
            {
                if (board[ylim(rows, diff_y)][xlim(cols, diff_x)])
                {
                    count++;
                }
            }
        }
    }
    
    
    return count;
}

static void table_GofL(void) 
{
    int cols, rows;
    
    for (rows = 0; rows < HEIGHT; rows++)
    {   
        for (cols = 0; cols < WIDTH; cols++)
        {   
            printf("%c", board[rows][cols] ? '*' : '.');
        }
        
        printf("\n");
    }
    
    printf("\n\r");
}

static void evolve_GofL(void)
{
    int cols, rows, add, newboard[HEIGHT][WIDTH];
    
    for (rows = 0; rows < HEIGHT; rows++)
    {   
        for (cols = 0; cols < WIDTH; cols++)
        { 
            add = addingtoCount(rows, cols);
            
            if (add == 2)
            {
                newboard[rows][cols] = board[rows][cols];
            }
            
            if (add == 3)
            {
                newboard[rows][cols] = 1;
            }
            
            if (add < 2)
            {
                newboard[rows][cols] = 0;
            }
            
            if (add > 3)
            {
                newboard[rows][cols] = 0;
            }
        }
    }
    
    for (rows = 0; rows < HEIGHT; rows++)
    {   
        for (cols = 0; cols < WIDTH; cols++)
        { 
            board[rows][cols] = newboard[rows][cols];
        }
    }
}

int main_GofL(void)
{
    start_board();
    
    for (int i = 0; i < Cycles; i++)
    {
        table_GofL();
        evolve_GofL();
    }
    
    return 0;
}


