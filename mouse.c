#include<assert.h>
#include "mouse.h"
#include <stdio.h>
#include<stdlib.h>

char maze[10][10] ={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
char mark[10][10] = {0};

axis_t FindGetPlace(pock_t *head, axis_t current){
    for(char dx=-1; dx<2; dx++){
        for(char dy=-1; dy<2; dy++){
            if(FOURDIREC(dx,dy)){
                axis_t space;
                space.x = current.x+dx;
                space.y = current.y+dy;
                if(maze[space.x][space.y] == 0 &&
                   mark[space.x][space.y] != '*'){
                    mark[space.x][space.y] = '*';
                    Push(head, space);
                   }
            }
        }
    }
    return GetTheTop(head);
}

int main(){
    pock_t *head = (pock_t *)malloc(sizeof(pock_t));
    assert(head);
    head->next = NULL;
    axis_t current;
    axis_t entry = {1, 0};
    axis_t out = {6, 9};
    axis_t noExit = {-1, -1};
    
    current = entry;
    mark[current.x][current.y] = '*';

    while(!EQU(current,out)){
        current = FindGetPlace(head, current);
        if(EQU(current, noExit)){
            printf("NO EXIT!!!\n");
            break;
        }
        printf("move to (%d, %d)\n", current.x, current.y);
    }
    free(head);
    return 0;
}