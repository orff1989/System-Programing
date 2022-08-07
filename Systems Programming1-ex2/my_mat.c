#include <stdio.h>
#include "my_mat.h"

int mat[10][10];
int ans[10][10];
int matChanged=0;
int ansChanged=0;
int inf = 999999;

void printMat(){
 for (int k = 0; k < 10; k++)
    {
        for (int r = 0; r < 10; r++)
        {
         printf("%d ",mat[k][r]);  
        }
        printf("\n");
    }
    printf("\n");
}

void printAns(){
 for (int k = 0; k < 10; k++)
    {
        for (int r = 0; r < 10; r++)
        {
         printf("%d ",ans[k][r]);  
        }
        printf("\n");
    }
    printf("\n");
}

void function1(){
    int num;
     for (int i = 0; i < 10; i++)
       {
           for (int j = 0; j < 10; j++)
           {
               scanf("%i",&num);
               mat[i][j]=num; 
           }
        }
        matChanged++;
}

void buildAns(){
   for (int k = 0; k < 10; k++)
    {
        for (int r = 0; r < 10; r++)
        {
            if (mat[k][r]==0 && r!=k)
            {
               ans[k][r]=inf;
            }
            else{
                ans[k][r]=mat[k][r];  
            }
        } 
}
}

void fixAns(){
    for (int h = 0; h < 10; h++)
    {
        for (int v = 0; v < 10; v++)
    {
        if (ans[h][v]==inf) ans[h][v]=0;
    }
    }    
}

void FWalgorithm(){
    if (matChanged>ansChanged){
    buildAns();
    
    for (int a = 0; a < 10; a++)
    {
      for (int b = 0; b < 10; b++)
      {
          for (int c = 0; c < 10; c++)
          {
              if(ans[b][a]+ans[a][c]< ans[b][c])
              ans[b][c]=ans[b][a]+ans[a][c];
          }
      }
    }
    ansChanged++;
    fixAns();
}
}

void function2(){
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);

    FWalgorithm();

    if (ans[i][j]==0) printf("False");
    else printf("True");

    printf("\n");
}

void function3(){
    int i;
    int j;
    scanf("%d",&i);
    scanf("%d",&j);

    FWalgorithm();
    
    if (ans[i][j]==0) printf("-1");
    else printf("%d",ans[i][j]);

    printf("\n");
}
