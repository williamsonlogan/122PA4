#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct queueNode
{
     int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
     int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
     int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

     struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
     QueueNode *pHead;
     QueueNode *pTail;
} Queue;

//Function prototypes

int isEmpty (Queue q);                                            //check if queue is empty
void printQueue(Queue q);                                         //print contents of a queue
QueueNode * makeNode(int custNum, int servTime, int totalTime);   //creates a new queuenode
void enqueue(struct queue *line, struct queueNode new_node);      //adds to back of queue
void dequeue(struct queue *line);                                 //takes from front of queue
