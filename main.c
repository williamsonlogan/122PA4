#include "grocery.h"

int main(void) {
  // init queue(didn't see a need for a function)
  struct queue line1;
  line1.pHead = NULL;
  line1.pTail = NULL;

  struct queue line2;
  line2.pHead = NULL;
  line2.pTail = NULL;

  // vars
  bool exit = false;
  int secsPassed = 0;

  srand((unsigned int)(time NULL));

  int express = random_number(1, 5);
  int normal = random_number(3, 8);
  int nextExp = 0, nextNorm = 0, customers = 0, expWait = 0, normWait = 0;
  bool expInit = false, normInit = false;

  // sim loop
  while (!exit)
  {
	  system("cls");

	  printf("Seconds Passed: %d\n\n", secsPassed);

	  printf("Line 1 - Express\n");
	  printfQueue(line1.pHead);

	  printf("Line 2 - Normal\n");
	  printfQueue(line2.pHead);

	  printf("\nPress Esc. to Quit.\n");

	  //TODO: Queue management

	  if (line1.pHead != NULL)
	  {
		  if (line1.pHead->serviceTime == 0)
		  {
			  dequeue(&line1);
		  }
		  if (line1.pHead != NULL)
		  {
			  line1.pHead->serviceTime--;
		  }
	  }

	  if (line2.pHead != NULL)
	  {
		  if (line2.pHead->serviceTime == 0)
		  {
			  dequeue(&line2);
		  }
		  if (line2.pHead != NULL)
		  {
			  line2.pHead->serviceTime--;
		  }
	  }

	  if (!expInit)
	  {
		  if (secsPassed == express)
		  {
			  customers++;
			  int tempServ = random_number(1, 5);
			  enqueue(&line1, customers, tempServ, tempServ);
			  expWait += tempServ;
			  expInit = true;
			  nextExp = random_number(1, 5);
		  }
	  }
	  else
	  {
		  if (nextExp == 0)
		  {
			  customers++;
			  int tempServ = random_number(1, 5);
			  expWait += tempServ;
			  enqueue(&line1, customers, tempServ, expWait);
			  nextExp = random_number(1, 5);
		  }
	  }

	  if (!normInit)
	  {
		  if (secsPassed == normal)
		  {
			  customers++;
			  int tempServ = random_number(3, 8);
			  enqueue(&line2, customers, tempServ, tempServ);
			  normWait += tempServ;
			  normInit = true;
			  nextNorm = random_number(3, 8);
		  }
	  }
	  else
	  {
		  if (nextNorm == 0)
		  {
			  customers++;
			  int tempServ = random_number(3, 8);
			  normWait += tempServ;
			  enqueue(&line2, customers, tempServ, normWait);
			  nextExp = random_number(3, 8);
		  }
	  }

	  //End Sim if hit esc.
	  if (_kbhit())
	  {
		  char c = _getch();

		  if (c = 27)
			  return 0;
	  }

	  Sleep(1000); //Wait one second (windows.h)
	  if (nextExp != 0) {
		  nextExp--;
	  }

	  if (nextNorm != 0) {
		  nextNorm--;
	  }
	  secsPassed++;
  }
}
