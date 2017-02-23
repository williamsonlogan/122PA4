#include "grocery.h"

int isEmpty(Queue q) { return (q.pHead == NULL); }

void printfQueue(QueueNode *pHead) {
  if (pHead != NULL) // Recursive step
  {
    printf(“Customer %d - Time to service:%d | Total time:%d\n”, (pHead)->customerNumber;
    // Get to the next item
    pHead = (pHead)->pNext;
    printQueueRecursive(pHead);
  } else // Base case
  {
    printf(“NULL\n”);
  }
}
