#include<stdio.h>
#include<conio.h>

int queue1[100], queue2[100], queue3[100] ;
struct process {
		
		int processId ;
		int priority ;
		int arrivalTime ;
		int burstTime ;
} ;
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
	}
}

int main() {
	
	int n ;
	printf("How many process") ;
	scanf("%d",&n) ;
	struct process proc[n] ;
	createProcess(n, proc) ;
//	int i ;
//	for(i = 0; i<n;i++) {
//		
//		printf("%d %d %d %d\n",proc[i].processId,proc[i].arrivalTime,proc[i].burstTime,proc[i].priority) ;
//	}
}
