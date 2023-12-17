#ifndef _MAGIC_
#define _MAGIC_

#define EQU(p,q) (p.x==q.x && p.y==q.y)

typedef struct axis{
	int x;
	int y;
} axis_t;

typedef struct Pocket{
	pock_t *next;
	axis_t coor;
} pock_t;

void Push(pock_t *headPtr, axis_t element);
axis_t GetTheTop(pock_t *headPtr);


#endif