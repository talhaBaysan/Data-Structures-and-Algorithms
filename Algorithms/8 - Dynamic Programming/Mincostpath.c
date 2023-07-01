#include<stdio.h>
#include<limits.h>

int min(int A, int B){
	if(A>B)	
		return B;
	return A;
}

int main(){
  	int N = 4,M = 4;
   //Given Cost matrix
   int cost[4][4] = {{1,7,9,2},
                     {8,6,3,2},
                     {1,6,7,8},
                     {2,9,8,2}};
 
   //Declare the auxiliary minCost matrix
   int minCost[N][M];
   int i, j;
   //Initialize it with 0
   for(i=0;i<N;i++)
     for(j=0;j<M;j++)
       minCost[i][j]=0;
 
   minCost[0][0]=cost[0][0];
   for(i=1;i<N;i++){
   	minCost[i][0] = minCost[i-1][0] + cost[i][0];
   	minCost[0][i] = minCost[0][i-1] + cost[0][i];
   }
   for(i=0;i<N;i++){
   	for(j=0;j<M;j++){
   		 printf("%4d ", minCost[i][j]);
	   }
      printf("\n");
   }
   printf("\n\n");
   for(i=1;i<N;i++){
      for(j=1;j<M;j++){
         //Extend the current cell to make a mincost path till (i,j) 
         minCost[i][j] = min(minCost[i-1][j], minCost[i][j-1]) + cost[i][j];
         printf("%4d ", minCost[i][j]);
      }
      printf("\n");
   }
    printf("\n\n");
   for(i=0;i<N;i++){
   	for(j=0;j<M;j++){
   		 printf("%4d ", minCost[i][j]);
	   }
      printf("\n");
   }
   printf("Cost of minimum cost path from (0,0) to ((%d,%d) is: %d",N-1, M-1, minCost[N-1][M-1]);
   
   return 0;
}
