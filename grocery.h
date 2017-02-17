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

int isEmpty (Queue q);
void printQueue(Queue q);
bool makeNode();
