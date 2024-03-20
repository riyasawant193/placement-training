#include<stdio.h>
#include<math.h>
int board[20],count;
void queen(int row,int);
int main()
{
int n,i,j;
printf(" - N Queens Problem Using Backtracking -");
printf("\n\nEnter number of Queens:");
scanf("%d",&n);
queen(1,n);
return 0;
}
void print(int n)
{
int i,j;
printf("\n\nsolution %d:\n\n",++count);
for(i=1;i<=n;++i)
printf("\t%d",i);
for(i=1;i<=n;++i)
{
printf("\n\n%d",i);
for(j=1;j<=n;++j) //for nxn board
{
if(board[i]==j)
printf("\tQ"); //queen at i,j position
else
printf("\t-"); //empty slot
}
}
}
int place (int row, int column)
{
printf("r n с are %d%d\n" ,row, column);
int i;
for (i=1;i<=row-1;++i)
{
//checking column and digonal conflicts
if(board[i]==column){
printf("i m returning zero %d\n",i);
return 0;
}
else
if(abs(board[i]-column)==abs(i-row))
return 0;
}
printf("m rtrning 1 here fr %d \n",i);
return 1; //no conflicts
}
void queen (int row, int n)
{
int column;
for (column=1;column<=n;++column)
{
printf("column in queen is %d\n",column);
if(place(row, column))
{
printf("i m in if %d%d \n",row, column);
board[row]=column; //no conflicts so place queen
if(row==n) //dead end
print(n); //printing the board configuration
else //try queen with next position
queen(row+1,n);
}
}
printf("end of for wit %d\n",column);
}