#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX_VERTRICES  8



typedef struct linkedlist *listpointer;
typedef struct linkedlist 
{
 short int vertex; //vertex number
 listpointer link;
}ptr;



void dfs(int ,listpointer * , int * ,int *);


int main(void)
{
   
   int v,z,x;
   int *y;
   int visited[MAX_VERTRICES];
   listpointer a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t;
   a=(listpointer)malloc(sizeof(*a));
   b=(listpointer)malloc(sizeof(*b));
   c=(listpointer)malloc(sizeof(*c));
   d=(listpointer)malloc(sizeof(*d));
   e=(listpointer)malloc(sizeof(*e));
   f=(listpointer)malloc(sizeof(*f));
   g=(listpointer)malloc(sizeof(*g));
   h=(listpointer)malloc(sizeof(*h));
   i=(listpointer)malloc(sizeof(*i));
   j=(listpointer)malloc(sizeof(*j));
   k=(listpointer)malloc(sizeof(*k));
   l=(listpointer)malloc(sizeof(*l));
   m=(listpointer)malloc(sizeof(*m));
   n=(listpointer)malloc(sizeof(*n));
   o=(listpointer)malloc(sizeof(*o));
   p=(listpointer)malloc(sizeof(*p));
   q=(listpointer) malloc(sizeof(*q));
   r=(listpointer) malloc(sizeof(*r));
   s=(listpointer)malloc(sizeof(*s));
   t=(listpointer) malloc(sizeof(*t));
   
   
   
   
   listpointer graph[8];
   graph[0]=a;
   a -> link=b;
   a->vertex=1;
   b->link=NULL;
   b->vertex=2;
    
    
   graph[1]=c;
   c->link=d;
   c->vertex=0;
   d->link=e;
   d->vertex=3;
   e->link=NULL;
   e->vertex=4;

   
   graph[2]=f;
   f->link=g;
   f->vertex=0;
   g->link=h;
   g->vertex=5;
   h->link=NULL;
   h->vertex=6;
   
   graph[3]=i;
   i->link=j;
   i->vertex=1;
   j->link=NULL;
   j->vertex=7;
   
   graph[4]=k;
   k->link=l;
   k->vertex=1;
   l->link=NULL;
   l->vertex=7;
   
   graph[5]=m;
   m->link=n;
   m->vertex=2;
   n->link=NULL;
   n->vertex=7;
   
   graph[6]=o;
   o->link=p;
   o->vertex=2;
   p->link=NULL;
   p->vertex=7;
   
   graph[7]=q;
   q->link=r;
   q->vertex=3;
   r->link=t;
   r->vertex=4;
   t->link=s;
   t->vertex=5;
   s->link=NULL;
   s->vertex=6;
  
  x=0;
  y=&x;
  printf("please input the startpoint of vertex:\n");
  scanf("%d",&v); 
  printf("\n");
  
  for(z=0;z<MAX_VERTRICES;z++)
  {
  	visited[z]=0;
  }
  
  dfs(v,graph,visited,y);
}





void dfs(int v ,listpointer * graph , int * visited , int *y)
{
  listpointer w;
  visited[v]=TRUE;
  printf("%5d",v);
  (*y)++;
  if((*y)<MAX_VERTRICES)
  {
  	printf("->");
  }
  
  
  
  for(w=graph[v];  w  ;w=w->link)
   {       
        if(!visited[w->vertex])
		{
        dfs(w->vertex,graph,visited,y);
	    }
   }
    
}





