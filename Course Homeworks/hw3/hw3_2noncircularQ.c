/**
 *	DataSturctures
 *	hw3_2 noncircular Queue
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

#define CYAN //"\x1b[36m" 
#define RESET //"\x1b[0m"

//queue
typedef struct{
		char data;
		} element;
element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

void printq()
{
	printf(CYAN "Front=%d,Rear=%d\n" RESET, front, rear);	
	for(int i = 0; i < MAX_QUEUE_SIZE; ++i)
	{
		if( i > front && i <= rear )
			printf(CYAN "[%c]" RESET, queue[i].data);
		else
			printf(CYAN "[]" RESET);
	}
	printf("\n");
}

void queueFull()
{
	fprintf(stderr,CYAN "Queue is full\n" RESET);
	printq();
}

void queueEmpty()
{
	fprintf(stderr,CYAN "Queue is empty\n" RESET);
}

void addq(element item)
{
	if( rear == MAX_QUEUE_SIZE - 1 )
	{	
		queueFull();
		return;
	}
	queue[++rear] = item;
	printq();
}

element deleteq()
{
	if( front == rear )
	{	
		element error = {-1};
		queueEmpty();
		printq();
		return error;
	}
	++front;
	printq();
	return queue[front];
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
							 char input = '0';
							 element inputElement;
							 
							 printf("insert:");
							 while(((input = getchar()) !='\n') && (input != EOF));
							 while(((input = getchar()) !='\n') && (input != EOF))
								 inputElement.data = input;
//							 scanf(" %c", &input);
//							 inputElement.data = input;
							 addq(inputElement);
							 break;
						 }
				
				case 2 : {
							 element deleteqItem = deleteq();
							 if( deleteqItem.data == -1 )
								break;
							 else
								printf(CYAN "delete:%c\n" RESET, deleteqItem.data);
							 break;
						 }

				default : fprintf(stderr, "invalid input\n");
			}
			break;
		}
	}
	return 0;
}
