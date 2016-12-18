/**
 *	DataSturctures
 *	hw3_2 Circular Queue
 *	Ch3 Stacks And Queues 
 *	p.114 Queue
 *
 *	first input 1 and 2 to select insert operation and delete operation respectively 
 *	input value other than 1 and 2 will print out "invalid input"
 *
 *	if input 1 (insert operation)
 *	next, input a character to insert into the queue
 *	print out the current queue data structures
 *
 *	input 2 to delete element from the front of the queue
 *	
 *	compile info : gcc hw3_1.c -o test -std=c99
 */

#include <stdio.h>
#define MAX_QUEUE_SIZE 4

#define CYAN  //"\x1b[36m" 
#define RESET //"\x1b[0m"

//circular queue
typedef struct{
		char data;
		} element;
element cirQueue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

void printq()
{
	printf(CYAN "Front=%d,Rear=%d\n" RESET, front, rear);	
	for(int i = 0; i < MAX_QUEUE_SIZE; ++i)
			printf(CYAN "[%c]" RESET, cirQueue[i].data);
	printf("\n");
}

void cirQueueFull()
{
	fprintf(stderr, "circular queue is full\n");
	printq();
}

element cirQueueEmpty()
{
	element error = {-1};
	fprintf(stderr, "circular queue is empty\n");
	printq();
	return error;
}

void addCirQ(element item)
{
	int temp = rear;
	rear = (rear+1) % MAX_QUEUE_SIZE;
	if( front == rear )
	{
		rear = temp;
		cirQueueFull();
		return;
	}
	cirQueue[rear] = item;
	printq();
}

element deleteCirQ()
{
	element item;
	if( front == rear )
		return cirQueueEmpty();
	front = (front+1) % MAX_QUEUE_SIZE;
	item = cirQueue[front];
	cirQueue[front].data = 0;
	printq();
	return item;
}

int main()
{
	int select; //select insert or delete
	
	while(1)
	{
		fflush(stdin);
		printf("insert(1)delete(2):");
		
		while( scanf("%d", &select) )
		{
			switch( select )
			{
				case 1 : {
							 element inputElement;
							 char input;
							 printf("insert:");
							 while(((input = getchar()) !='\n') && (input != EOF));
							 while(((input = getchar()) !='\n') && (input != EOF))
								  inputElement.data = input;
							 addCirQ(inputElement);
							 break;
						 }
				
				case 2 : {
							 element deleteElement = deleteCirQ();
							 if( deleteElement.data == -1 )
								 break;
							 else	
								printf(CYAN "delete:%c\n" RESET, deleteElement.data);
							 break; 
						 }

				default : fprintf(stderr, "invalid input\n");
			}
			
			break;
		}
	}
	return 0;
}
