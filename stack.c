/*=============计算机科学引论==========
关于链栈的基本操作
*/
#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	int data;
	struct node* link;
}stack_node;

typedef struct {
	int count;
	stack_node* top;
}stack;

/*===================push=====================
  Insert node into linked list stack

  */

  bool push(stack* pStack,int dataIn){
  	stack_node* pNew;
  	pNew = (stack_node*) malloc(sizeof(stack_node));
  	bool success;

  	if(! pNew){
 		success = false;
  	}
  	else{
  	pNew->link = pStack->top;
    pNew->data =dataIn;

  	pStack->top =pNew;
  	pStack->count++;
	success =true;	
	}

	return success;



  }
/*=============pop===============
 pop node from linked list stack
 
 */

  bool pop(stack* pStack,int * dataOut){

  	stack_node* pDlt;//被删除节点
  	bool success;

  	if(! (pStack->top) ){
  		success = false;

  	}

  	else{
		pDlt = pStack->top;
		*dataOut =pDlt->data;
	   	pStack->top = pStack->top->link;
		pStack->count --;
  		free(pDlt);
		success =true;
  	}

  	return success;

}
/*===========insertData============

  
*/
  void insertData(stack* pStack){

	  int numIn;
	  bool success;

	  printf("Creating numbers: ");
	  for(int nodeCount = 0;nodeCount<10;nodeCount++){
			numIn = rand()% 999;
			printf("%4d",numIn);
			success =push(pStack,numIn);

			if(!success){
				printf("Error 101: Out of memory\n");
				exit(101);
			}

	  }

	  printf("\n");
	  return;

  }

  void print(stack* pStack){

	  int printData;

	  printf("Stack contained: ");

	  while (pop(pStack,&printData))
	  {
		  printf("%4d",printData);
	  }
		return ;
  }


  int main(){
	  stack* pStack;

	  printf("Beginning simple stack program\n");

	  pStack =(stack*) malloc(sizeof(stack));

	  if(!pStack){
		  printf("Error allocating stack");
		  exit(100);
	  }

	  pStack->top = NULL;
	  pStack->count =0;
	  insertData(pStack);
	  print(pStack);

	  printf("\nEnd simple stack program\n");

	  return 0;

  }