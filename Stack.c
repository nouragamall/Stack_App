#include "Stack.h"

void Stack_Init(stack_t *stack){
stack->LastIndex=0;
}
void Stack_Push(stack_t *stack,STACK_DATA_TYPE Data){
stack->StackArr[stack->LastIndex]=Data;
stack->LastIndex++;

}
void Stack_Pop(stack_t *stack){
stack->LastIndex--;
}
void Stack_Top(stack_t *stack , STACK_DATA_TYPE *Data){
*Data= stack->StackArr[(stack->LastIndex)-1];
}
void Stack_GetSize(stack_t *stack , STACK_TYPE *size){
  *size=stack->LastIndex;
}
void stack_traverse(stack_t *stack,void (*ptr_func)(STACK_TYPE* x)){
	STACK_TYPE i=0;
  for(i=0;i<(stack->LastIndex);i++){
    (*ptr_func)(&stack->StackArr[i]);
  }
}
STACK_TYPE IsEmpty(stack_t *stack)
{
	STACK_TYPE Empty=1;
	STACK_TYPE notEmpty=0;
	if(stack->LastIndex == 0)
		return Empty;
	else
		return notEmpty;
}
