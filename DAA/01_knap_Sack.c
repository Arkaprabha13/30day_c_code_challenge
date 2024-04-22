#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int max(int a,int b)
{
  return a>b?a:b;
}



int kanpsack_01(int capacity,int weight[],int profit[],int n)
{
  int dp[n+1][capacity+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=capacity;j++)
    {
      if(i==0||j==0)
      {
        dp[i][j]=0;
      }
      else if(weight[i-1]>j)
      {
        dp[i][j]=dp[i-1][j];
      }
      else
      {
        dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
      }
    }
  }
  for(int i=0;i<=n;i++){
    for(int c=0;c<capacity;c++)
    {
      printf("%d  ",dp[i][c]);
    }
    printf("\n");
  }
  return dp[n][capacity];
}





int main()
{
  
  
  
int val[] = { 10, 40, 30, 50 }; 
int wt[] = { 5, 4, 6, 3 }; 
int W = 10; 
int n = 4;
int ans=kanpsack_01(W, wt, val, n);
printf("Ans is ->%d ",ans);
  return 0;
}
