#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define S1 5
#define S2 100000
void swap(int a[],int i,int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int a[],int f,int l)
{
    int position=f,pivot=l,i;
    for(i=f;i<l;i++)
    {
        if(a[i]<=a[pivot])
        {
            swap(a,i,position);
            position++;
        }
    }
    swap(a,pivot,position);
    return position;

}
void QuickSort(int a[],int f,int l)
{
    int index;
    if(f<l)
    {
        index=partition(a,f,l);
        QuickSort(a,f,index-1);
        QuickSort(a,index+1,l);
    }
}

int main()
{
    int a1[S1],a2[S2],i,total;
    FILE *fp,*fp1;
    clock_t start,end;
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;
    printf("\n\"5 inputs:\"\n");
    printf("\nEnter the elements:\n");
    for(i=0;i<S1;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("\nBefore sorting:\n");
    for(i=0;i<S1;i++)
    {
        printf("%d ",a1[i]);
    }
    gettimeofday(&tv,&tz);
    QuickSort(a1,0,S1-1);
    tm = localtime(&tv.tv_sec);
    printf("\nAfter sorting:\n");
    for(i=0;i<S1;i++)
    {
        printf("%d ",a1[i]);
    }
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);
    printf("\n\"1M inputs:\"\n");
    fp=fopen("input.txt","w");
    for(i=0;i<S2;i++)
    {
        fprintf(fp,"%d ",rand());
    }
    fflush(fp);
    fclose(fp);
    fp1=fopen("input.txt","r");
    for(i=0;i<S2;i++)
    {
        fscanf(fp1,"%d",&a2[i]);
    }
    fclose(fp1);
    start = clock();
    QuickSort(a2,0,S2-1);
    end = clock();
    fp=fopen("output.txt","w");
    for(i=0;i<S2;i++)
    {
        fprintf(fp,"%d ",a2[i]);
    }
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\nExecution time for 1M(in millisec): %d millisec\n",total);
    printf("Time different: %d millisec\n",abs(total-tm->tm_sec));
    return 0;
}
