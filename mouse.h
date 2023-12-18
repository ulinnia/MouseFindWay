#ifndef _MAGIC_
#define _MAGIC_

typedef struct Pocket pock_t;

#define FOURDIREC(i,j) (((i^j)==i || (i^j)==j)&&(!(i==0 && j==0)))

typedef struct axis{
	int x;
	int y;
} axis_t;

typedef struct Pocket{
	pock_t *next;
	axis_t coor;
} pock_t;

//#define EQU(p,q) (p.x==q.x && p.y==q.y)
static inline int EQU(axis_t a,axis_t b){
	return (a.x==b.x && a.y==b.y);
}

void Push(pock_t *headPtr, axis_t element);
axis_t GetTheTop(pock_t *headPtr);


#endif