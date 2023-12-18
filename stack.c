#include <stdio.h>
#include<stdlib.h>
#include "mouse.h"

int isEmpty(pock_t *headPtr){
    if (headPtr->next==NULL)return 1;
    return 0;
}

void Push(pock_t *headPtr, axis_t element){
    pock_t *NewPtr = (pock_t *) malloc(sizeof(pock_t));
    NewPtr->coor = element;
    NewPtr->next = headPtr->next;
    headPtr->next = NewPtr;
}

axis_t GetTheTop(pock_t *headPtr){
    pock_t *current = headPtr->next;
    axis_t temp = {-1, -1}; 
    if(isEmpty(headPtr)) return temp;
    headPtr->next = current->next;
    temp = current->coor;
    free(current);
    return temp;
}