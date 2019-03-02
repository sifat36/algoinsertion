#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define S1 100000
#define S2 5
 void Merge(int *a, int low, int high, int mid)
{

	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}


	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}


	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}



	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}


void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;

		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}

int main()
{
	int n, i;
	FILE *f,*f1;
	int arr[S2],arr1[S1];
	clock_t start,end,start1,end1;
    int total;
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;

	for(i = 0; i < S2; i++)
	{
		printf("Enter element ",i+1,": ");
		scanf("%d",&arr[i]);
	}
	gettimeofday(&tv,&tz);
	MergeSort(arr, 0, S2);
	tm = localtime(&tv.tv_sec);
	printf("\nSorted Data");
	for (i = 0; i< S2; i++)
        {
             printf(" %d, ",arr[i]);
        }
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);
    printf("\nFor 1M:\n");
    f=fopen("in.txt","w");
    for(i = 0;i < S1 ;i++)
    {
        fprintf(f,"%d ",rand());
    }
    fflush(f);
    fclose(f);
    f1=fopen("in.txt","r");
    for(i = 0;i < S1 ;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    fclose(f1);
    start = clock();
    MergeSort(arr1, 0, S1);
    end = clock();
    f=fopen("out.txt","w");
    for(i = 0;i < S1;i++)
    {
        fprintf(f,"%d ",arr1[i]);
    }
    fclose(f);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\nExecution time for 1M(in millisec): %d millisec\n",total);
    printf("Time different: %d millisec\n",abs(total-tm->tm_sec));
	return 0;
}
