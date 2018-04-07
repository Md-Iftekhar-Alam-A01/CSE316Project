void roundRobin(int n, struct process proc[]) {
	int i,j,time,remain=n,flag=0,timeQuantum = 4,waitTime=0,turnAroundTime=0 ;
	
	printf("\n\nProcess\t\tWaiting Time    Turnaround Time\n\n"); 
  	for(time=0,i=0;remain!=0;) {  	 
	    if((proc[i].responseTime<=timeQuantum) && (proc[i].responseTime)>0) { 
			time+=(proc[i].responseTime); 
	      	(proc[i].responseTime)=0; 
	      	flag=1; 
	    } else if((proc[i].responseTime)>0) { 
			(proc[i].responseTime)-=timeQuantum; 
			time+=timeQuantum; 
	    } if((proc[i].responseTime)==0 && flag==1) { 
		    remain--; 
			printf("Process[%d]\t\t%d\t\t%d\n",proc[i].processId,time-((proc[i].arrivalTime)-(proc[i].burstTime)),time-(proc[i].arrivalTime)); 
		    waitTime+=time-(proc[i].arrivalTime)-(proc[i].burstTime); 
			turnAroundTime+=time-(proc[i].arrivalTime); 
		    flag=0; 
	    } if(i==n-1) 
	    	i=0; 
	    else if((proc[i+1].arrivalTime)<=time) 
	    	i++; 
	    else 
	    	i=0; 
	} 
	//printf("\nAverage Waiting Time= %f\n",waitTime*1.0/n); 
	//printf("Avg Turnaround Time = %f",turnAroundTime*1.0/n); 
}


void fcfs(int n, struct process proc[]) {
		float waiting_time[30], turnaround_time[30];
        float average_waiting_time = 0.0, average_turnaround_time = 0.0;
        int count, j, total_process=n;
        waiting_time[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                waiting_time[count] = 0;
                for(j = 0; j < count; j++)
                {
                        waiting_time[count] = waiting_time[count] + proc[j].burstTime ;
                }
        }
        printf("\nProcess\t\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                turnaround_time[count] = proc[count].burstTime + waiting_time[count];
                average_waiting_time = average_waiting_time + waiting_time[count];
                average_turnaround_time = average_turnaround_time + turnaround_time[count];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f", proc[count].processId, waiting_time[count], turnaround_time[count]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time / count;
        average_turnaround_time = average_turnaround_time / count;
//        printf("\nAverage Waiting Time = %f", average_waiting_time);
//        printf("\nAverage Turnaround Time = %f", average_turnaround_time);
//        printf("\n");
        
}


void queueScheduling1() {
	roundRobin(rear1+1, queue1) ;
}
void queueScheduling3() {
	fcfs(rear3+1, queue3) ;
}


int main() {
	int n ;
	printf("How many process - ") ;
	scanf("%d",&n) ;
	struct process proc[n] ;
	createProcess(n, proc) ;
	assignProcessInQueue(n, proc) ;
	printQueueFront() ;
	queueScheduling1() ;
	queueScheduling3() ;
//	int i ;
//	for(i = 0; i<n;i++) {
//		
//		printf("%d %d %d %d\n",proc[i].processId,proc[i].arrivalTime,proc[i].burstTime,proc[i].priority) ;
//	}
}




// main_scheduling() {
//    RoundRobin - 10sec
//          q1 / q2 / q3
// }

// queue1() - round robin 4 secs
// queue2() - priority scheduling
// queue3() - FCFS
