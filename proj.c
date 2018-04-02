#include<stdio.h>
#include<conio.h>

struct process {
		int processId ;
		int priority ;
		int arrivalTime ;
		int burstTime ;
		int responseTime ;
};

struct process queue1[100], queue2[100], queue3[100] ;

int rear1 = -1 ;
int front1 = -1 ;
int rear2 = -1 ;
int front2 = -1 ;
int rear3 = -1 ;
int front3 = -1 ;


void queue1Push(struct process proc) {
	if(front1 == -1) {
		front1 = 0 ;
	}
	rear1 = rear1 + 1 ;
	queue1[rear1] = proc ;
}


void queue1Pop() {
	front1 = front1 + 1 ;
}


struct process queue1Front() {
	return queue1[front1] ;
}


void queue2Push(struct process proc) {
	if(front2 == -1) {
		front2 = 0 ;
	}
	rear2 = rear2 + 1 ;
	queue2[rear2] = proc ;
}


void queue2Pop() {
	front2 = front2 + 1 ;
}


struct process queue2Front() {
	return queue2[front2] ;
}


void queue3Push(struct process proc) {
	if(front3 == -1) {
		front3 = 0 ;
	}
	rear3 = rear3 + 1 ;
	queue3[rear3] = proc ;
}


void queue3Pop() {
	front3 = front3 + 1 ;
}


struct process queue3Front() {
	return queue3[front3] ;
}


void createProcess(int n, struct process proc[]) {	
	int i ;
	for(i=0; i<n; i++) {
		printf("Enter Process Id") ;
		scanf("%d",&proc[i].processId) ;
		printf("Enter Process Arrival Time") ;
		scanf("%d",&proc[i].arrivalTime) ;
		printf("Enter Process Burst Time") ;
		scanf("%d",&proc[i].burstTime) ;
		printf("Enter Processes Priority") ;
		scanf("%d",&proc[i].priority) ;
		proc[i].responseTime = proc[i].burstTime ;
	}
}


void assignProcessInQueue(int n, struct process proc[]) {
	int i ;
	for(i=0; i<n; i++) {
		if((proc[i].priority)>=0 && (proc[i].priority)<100) {
			queue1Push(proc[i]) ;
		} else if ((proc[i].priority)>=100 && (proc[i].priority)<200) {
			queue2Push(proc[i]) ;
		} else if ((proc[i].priority)>=200 && (proc[i].priority)<300) {
			queue3Push(proc[i]) ;
		} 
	}	
}


void printQueueFront() {
	printf("%d\n",queue1Front().processId) ;
	printf("%d\n",queue2Front().processId) ;
	printf("%d\n",queue3Front().processId) ;
}


void roundRobin(int n, struct process proc[]) {
	int i,j,time,remain=n,flag=0,timeQuantum = 4,waitTime=0,turnAroundTime=0 ;
	
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
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
			printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-(proc[i].arrivalTime),time-((proc[i].arrivalTime)-(proc[i].burstTime))); 
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
	printf("\nAverage Waiting Time= %f\n",waitTime*1.0/n); 
	printf("Avg Turnaround Time = %f",turnAroundTime*1.0/n); 
}

int main() {
	int n ;
	printf("How many process") ;
	scanf("%d",&n) ;
	struct process proc[n] ;
	createProcess(n, proc) ;
	assignProcessInQueue(n, proc) ;
	printQueueFront() ;
	roundRobin(n, proc) ;
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
