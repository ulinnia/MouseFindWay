#include "mouse.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    pock_t *head = (pock_t *) malloc(sizeof(pock_t));
    head->next = NULL;
    axis_t a = GetTheTop(head);
    printf("(%d,%d)\n",a.x,a.y);
    axis_t b = {1,2};
    Push(head,b);
    axis_t c = {1,3};
    Push(head,c);
    a = GetTheTop(head);
    printf("(%d,%d)\n",a.x,a.y);
    a = GetTheTop(head);
    printf("(%d,%d)\n",a.x,a.y);
    free(head);
    return 0;
}