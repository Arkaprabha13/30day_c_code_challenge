#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int find_lcs(char *s1,char*s2,int m,int n,char *lcs)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(s1[m-1]==s2[n-1])
    {
        if(lcs!=NULL)
        {
            lcs[find_lcs(s1,s2,m-1,n-1,lcs)]=s1[m-1];
        }
        return 1+find_lcs(s1,s2,m-1,n-1,lcs);
    }
    else
    {
        return max(find_lcs(s1,s2,m,n-1,lcs),find_lcs(s1,s2,m-1,n,lcs));
    }
}


void find_lcs2(char*s1,char*s2,int m,int n)
{
    int lcs[m+1][n+1];
    int i,j;
    
    
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                lcs[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    int lcs_length=lcs[m][n];
    char lcs_string[lcs_length+1];
    lcs_string[lcs_length]='\0';
    i=m;
    j=n;
    while(i>=0 && j>=0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs_string[lcs_length-1]=s1[i-1];
            i--;j--;lcs_length--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    // Printing the LCS length and LCS sequence
    printf("Length of LCS: %d\n", lcs[m][n]);
    printf("LCS: %s\n", lcs_string);
}

int main()
{
    char s1[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char s2[] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int m = sizeof(s1) / sizeof(s1[0]);
    int n = sizeof(s2) / sizeof(s2[0]);

    char lcs[max(m, n)];
    int lcs_length = find_lcs(s1, s2, m, n, lcs);
    
    printf("Length of LCS: %d\n", lcs_length);
    printf("LCS: ");
    for (int i = 0; i < lcs_length; i++)
        printf("%c", lcs[i]);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    find_lcs2(s1,s2,m,n);
    
    return 0;
}
