#include "stdio.h"  
#include "stdlib.h"  
void dfs(int a[9][9], int row, int col){  
 int count = 0, d[9] = { 0 },i,j,k; //d为记录每一个可填入数的一维数组  
 //搜索结束，行列均累加至9  
 if (row == 9 && col == 9){  
  for (i = 0; i < 9; i++){  
   for (j = 0; j < 9; j++){  
    printf("%d", a[i][j]);  
   }  
   printf("\n");  
  }  
  return;  
 }  
 //开始回溯，即此格为零需要填入数字a[row][col] == 0，可是经过行、列、块检测无可填入的数count == 0  
 if (a[row][col] == 0){  
  for ( k = 0; k < 9; k++){      //行检验  
   if (a[row][k] != 0){  
    d[a[row][k] - 1] = 1;  
   }  //列检验  
   if (a[k][col] != 0){  
    d[a[k][col] - 1] = 1;  
   }  
  }  
//块检验
int m,n;
  for ( m = (int)(row / 3) * 3; m < (int)(row / 3) * 3 + 3; m++){  
   for ( n = (int)(col / 3) * 3; n < (int)(col / 3) * 3 + 3; n++){  
    if (a[m][n] != 0)  
     d[a[m][n] - 1] = 1;  
   }  
  }  
  for (k = 0; k < 9; k++){  
   if (d[k] == 0) count++;  
  }  
  if (count == 0)  
   return;  
//正常情况下，填入d中记录可填入的数，再进行对行列数进入到下一个的操作，如若下一个满足回溯条件跳回原来的，则之前改变的还原  
  else{  
   for ( k = 0; k < 9; k++){  
    if (d[k] == 0){  
//填入d中记录可填入的数  
     a[row][col] = k + 1;  
     d[k] = 1;  
//再进行对行列数进入到下一个的操作  
     if (col == 8 && row == 8){  
      col = col + 1;  
      row = row + 1;  
     }  
     else if (col == 8 && row < 8){  
      col = 0;  
      row += 1;  
     }  
     else if(col < 8 && row <= 8){  
      col += 1;  
     }  
     dfs(a, row, col); //进入下一格  
//如若下一个满足回溯条件跳回原来的，则之前改变的还原  
     if (col == 0){  
      col = 8;  
      row -= 1;  
     }  
     else{  
      col--;  
     }  
     a[row][col] = 0;  
     d[k] = 0;  
    }  
   }  
  }  
 }  
//若一格中已经提供了数，即a[row][col] ！= 0，则进行行列数的操作后，直接进入下一格  
 else{  
  if (col == 8 && row == 8){  
   col = col + 1;  
   row = row + 1;  
  }  
  else if (col == 8 && row < 8){  
   col = 0;  
   row += 1;  
  }  
  else if (col < 8 && row <= 8){  
   col += 1;  
  }  
  dfs(a, row, col); //进入下一格  
 }  
}  
int main()  
{  
 char temp[10];  
 int a[9][9] = { 0 }, d[9] = { 0 }, row = 0, col = 0; 
 int i,j; 
   //输入格式控制  
 for (i = 0; i<9; i++)   
 {  
  gets(temp);  
  for (j = 0; j<9; j++)  
  {  
   a[i][j] = (int)(temp[j] - '0');  
  }  
 }  
printf("\n");   
 dfs(a, row, col);  
 return 0;  
}  
