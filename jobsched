#include<stdio.h>
#include<stdlib.h>
#define max 10

struct job
{
    int id,deadline,profit;
};

int compare(const void *a , const void *b)
{
    struct job *job1 = (struct job*)a;
    struct job *job2 = (struct job*)b;

    return job2->profit - job1->profit;
}

int main()
{
    struct job job[max];
    int n,i,j,maxD=0,totalp=0;
    int slot[max];
    printf("enter number of jobs: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter deadline and profit of job %d: ",i+1);
        job[i].id=i+1;
        scanf("%d %d",&job[i].deadline,&job[i].profit);
    }

    qsort(job,n,sizeof(struct job),compare);

    for(i=0;i<n;i++)
    {
        if(job[i].deadline>maxD)
            maxD=job[i].deadline;
    }

    for(i=0;i<maxD;i++)
        slot[i]=-1;

    for(i=0;i<n;i++)
    {
        for(j=job[i].deadline-1;j>=0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=job[i].id;
                totalp+=job[i].profit;
                break;
            }
        }
    }

    printf("\nScheduled jobs: ");
    for(i=0;i<maxD;i++)
    {
        if(slot[i]!=-1)
        printf("J5%d ",slot[i]);
    }

    printf("\nTotal cost: %d",totalp);


}
