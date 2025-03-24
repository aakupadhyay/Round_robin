#include<stdio.h> 
 
//DISPLAYING THE GANTT CHART
void Gantt_chart(int n,int pname[], int Wt[], int Bu[])
{
    int i;
    printf("\n\nGANTT CHART");
    printf("\n--------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
        printf("|\tP%d\t",pname[i]);
    printf("|\t");
    printf("\n--------------------------------------------------------------------\n");
    //printf("\n");
    for(i=0;i<n;i++)
        printf("%d\t\t",Wt[i]);
    printf("%d",Wt[n-1]+Bu[n-1]);
    printf("\n--------------------------------------------------------------------\n");
    printf("\n");
 }

int main() 
{ 
	int i, limit, total = 0, x, counter = 0, time_quantum, y=0, p[10], t, t1=0, pos,Wt[10]; 
  	int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
	float average_wait_time, average_turnaround_time;
  	printf("\nEnter Total Number of Processes:\t"); 
  	scanf("%d", &limit); 
  	x = limit; 
  	for(i = 0; i < limit; i++) 
  	{
		printf("\nEnter Details of Process[%d]\n", i + 1);
    		printf("Arrival Time:\t");
    		scanf("%d", &arrival_time[i]);
		printf("Burst Time:\t");
    		scanf("%d", &burst_time[i]); 
                 //y = y + burst_time[i];
                  p[i]=i+1; //contains process number
  	} 
      
     	printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
  	for(total = 0, i = 0; x != 0;) 
  	{   
	  //sorting burst time in ascending order using selection sort
	       for(int k = i; k < limit; k++)
		{
			pos=k;
			for(int j=k+1; j < limit; j++)
			{
			    if(burst_time[j]<burst_time[pos])
				pos=j;
			}
		 
			t=burst_time[k];
			burst_time[k]=burst_time[pos];
			burst_time[pos]=t;
		 
			t1=p[k];
			p[k]=p[pos];
			p[pos]=t1;
		} 

		for(int k = i; k < limit; k++)
		{  temp[k] = burst_time[k];
		    y = y + burst_time[k];
		 }

//Dynamic Time Quantum is the average of burst time of all arrived process                
                time_quantum = y/limit;
	  	printf("\nTime Quantum:%d\t\n", time_quantum); 

    		if(temp[i] <= time_quantum && temp[i] > 0) 
    		{ 
      			total = total + temp[i]; 
      			temp[i] = 0; 
      			counter = 1; 
    		} 
    		else if(temp[i] > 0) 
    		{ 
      			temp[i] = temp[i] - time_quantum; 
      			total = total + time_quantum; 
    		} 
    		if(temp[i] == 0 && counter == 1) 
    		{ 
      			x--; 
 			printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", p[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
      			wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                        Wt[i]=wait_time;
      			turnaround_time = turnaround_time + total - arrival_time[i]; 
      			counter = 0; 
    		} 
    		if(i == limit - 1) 
      		{
			i = 0; 
		}
    		else if(arrival_time[i + 1] <= total) 
      		{
			i++;
		}
    		else 
      		{
			i = 0;
		}
	} 
	average_wait_time = wait_time * 1.0 / limit;
	average_turnaround_time = turnaround_time * 1.0 / limit;
  	printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
  	printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
        Gantt_chart(limit, p, Wt, burst_time);
  	return 0; 
}
