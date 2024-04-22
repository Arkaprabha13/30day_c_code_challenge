#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
void swap(int *a,int*b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

int partition(int *a,int l,int h,int *comparisions)
{
  int i=l-1;
  // int j=high;
  int pivot=a[h];
  
  for(int j=l;j<=h-1;j++)
  {
    (*comparisions)++;
    if(a[j]<pivot)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[h]);
  return i+1;
}

int randomised(int *a,int low,int high,int *comparisions)
{
  srand(time(NULL));
  int random=low+rand()%(high-low);
  swap(&a[random],&a[high]);
  return partition(a,low,high,comparisions);
}

void quicksort(int *a,int low,int high,int *comparisions)
{
  if(low<high)
  {
    int pivot=randomised(a,low,high,comparisions);
    quicksort(a,low,pivot-1,comparisions);
    quicksort(a,pivot+1,high,comparisions);
    
  }
}


int main()
{
      int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
  double total_time=0;
  
  clock_t start=clock();
    // Regular Quick Sort
    int comparisonsRegular = 0;
    quicksort(arr, 0, n - 1, &comparisonsRegular);
    clock_t end=clock();
    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;
        total_time += runtime;
        
        
      printf("The time req -> %f\n",total_time);
    printf("Sorted array using Quick Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Number of comparisons: %d\n", comparisonsRegular);

  
  return 0;
}
