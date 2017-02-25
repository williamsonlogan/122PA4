#include "grocery.h"

int isEmpty(Queue q) { return (q.pHead == NULL); }

void printfQueue(QueueNode *pHead) {
  if (pHead != NULL) // Recursive step
  {
    printf("Customer %d - Time to service: %d - Total time: %d\n", (pHead)->customerNumber, (pHead)->serviceTime, (pHead)->totalTime);
    // Get to the next item
	if ((pHead)->pNext != NULL) {
		pHead = (pHead)->pNext;
		printfQueue(pHead);
	}
  } else // Base case
  {
    printf("This line is empty.\n");
  }
}

QueueNode * makeNode(int custNum, int servTime, int totalTime)
{
  QueueNode *pMem = NULL;

  pMem = (QueueNode *)malloc(sizeof(QueueNode));

  if (pMem != NULL){
    pMem->customerNumber = custNum;
    pMem->serviceTime = servTime;
    pMem->totalTime = totalTime;
    pMem->pNext = NULL;
  }

  return pMem;
}

void enqueue(struct queue *line, int custNum, int servTime, int totalTime)
{
  struct queueNode *pMem = NULL;

  pMem = makeNode(custNum, servTime, totalTime);

  if (pMem != NULL)
  {
    if(isEmpty(*line))
    {
      line->pHead=pMem;
    }
    else
    {
      line->pTail->pNext = pMem;
    }
	line->pTail = pMem;
  }
}

void dequeue(struct queue *line)
{
	QueueNode *pFront = NULL;
	QueueNode *retNode = NULL;

	if (!isEmpty(*line))
	{
		pFront = line->pHead;
		retNode = line->pHead;
		line->pHead = line->pHead->pNext;
		if (line->pHead == NULL)
		{
			line->pTail = NULL;
		}
		free(pFront);
	}
}

int random_number(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;
	if (min_num<max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1; // this is done to include max_num in output.
	}
	else {
		low_num = max_num + 1;// this is done to include max_num in output.
		hi_num = min_num;
	}
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
} //Taken and edited from http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c