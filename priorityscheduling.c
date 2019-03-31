#include<stdio.h>

int main(void)
{
	int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,cycle=0,pri[10];
	int ct[10],cct[10],aat[10],temp,temp1,j,at[10],wt[10],tt[10],ta=0,sum=0;
	float wavg,tavg,tsum=0,wsum;

	printf("PRIORITY SCHEDULING ALGORITHM\n");
	printf("Number of processes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the cycle time of P%d: ", i+1);
		scanf("%d",&ct[i]);
		printf("\tEnter the arrival time of P%d: ", i+1);
		scanf("%d",&at[i]);
		printf("\tEnter the priority time of P%d: ", i+1);
		scanf("%d",&pri[i]);
	}

	for(i=0;i<n;i++)
	{
		cct[i]=ct[i];
		aat[i]=at[i];
	}

	printf("--------------------------------------------------");
	printf("\nProcess\t CPU cycle\tArrival time\tPriority " );
	for(i=0;i<n;i++)
	{
		printf("\n  P%d",p[i]);
		printf("\t     %d",ct[i]);
		printf("\t\t     %d",at[i]);
		printf("\t\t   %d",pri[i]);
	}

	for(j=0;j<n;j++)
	{
		cycle=cycle+ct[j];
   		min=ct[k];
		for(i=k;i<n;i++)//main logic
		{
			min=pri[k];
			if (cycle>=at[i])
			{
				if(pri[i]<min)
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
					temp=at[k];
					at[k]=at[i];
					at[i]=temp;
					temp1=ct[k];
					ct[k]=ct[i];
					ct[i]=temp1;
					temp=pri[k];
					pri[k]=pri[i];
					pri[i]=temp;
				}
			}
		}
		k++;
	}

	wt[0]=0;

	for(i=1;i<n;i++)
	{
		sum=sum+ct[i-1];
		wt[i]=sum-at[i];
	}

	for(i=0;i<n;i++)
	{
		wsum=wsum+wt[i];
	}

	wavg=wsum/n;

	for(i=0;i<n;i++)
	{
		ta=ta+ct[i];
		tt[i]=cct[i]+wt[i];
	}

	for(i=0;i<n;i++)
	{
		tsum=tsum+tt[i];
	}

	tavg=tsum/n;

	printf("\nProcess\tWaiting time\tTurnaround time");

	for(i=0;i<n;i++)
	{
		printf("\n  P%d",pri[i]);
		printf("\t     %d",wt[i]);
		printf("\t\t     %d",tt[i]);
	}

	printf("\nTOTAL WAITING TIME: %0.2f ms", wsum);
	printf("\nAVERAGE WAITING TIME: %0.2f ms", wavg);
	printf("\nTOTAL TURN AROUND TIME: %0.2f ms", tsum);
	printf("\nAVERAGE TURN AROUND TIME: %0.2f ms", tavg);

	getch();
	return 0;
}
