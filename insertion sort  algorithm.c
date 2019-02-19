#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#define SIZE 100000
#define SIZE1 5
void insertionsort(int a[],int n)
{
    int i,j;
    int key;
    for (i=1;i<=n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    struct timeval tv,tv1;
    struct timezone tz,tz1;
    struct tm *tm;
    clock_t start,end;
    int i,n,a1[SIZE1],total;
    long int a[SIZE];
    FILE *fptr;
    //clock_t begin, end;
    //for 5 input
    printf("the input number are\n");
    for (i=0;i<SIZE1;i++)
    {
        scanf("%d",&a1[i]);
    }
    gettimeofday(&tv, &tz);
    insertionsort(a1,SIZE1);
    tm=localtime(&tv.tv_sec);
    printf("(5 input)The time took %d milisec to do the sorting \n",tm->tm_sec);
    //for 1M
    fptr = fopen("program1.txt","w");
    for (i=0;i<n;i++)
    {
      fprintf(fptr,"%d, ",rand()%1000);
    }
    fflush(fptr);
    fclose(fptr);
    fptr = fopen("program1.txt","r");
    start = clock();
    for(i=0;i<SIZE;i++)
    {
       fscanf(fptr,"%d",&a[i]);
    }
    fclose(fptr);
    insertionsort(a,SIZE);
    end = clock();
    fptr=fopen("out.text","w");
    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d, ",a[i]);
    }
    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("For 1M input\n(1M input)The time took %d millisec\n",total);
    printf("Time difference: %d millisec\n",total-tm->tm_sec);
    return 0;
}
