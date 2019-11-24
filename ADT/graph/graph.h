#include "../boolean/boolean.h"

#ifndef GRAPH_H
#define GRAPH_H

#define NilGraph NULL

typedef struct tNodeGraph* adrNode;
typedef struct tSuccNode* adrSuccNode;
typedef struct tNodeGraph
{
    int id;
    adrSuccNode Adj;
    adrNode Next;
} NodeGraph;
typedef struct tSuccNode
{
    adrNode origin;
    adrSuccNode Next;
} SuccNode;

typedef struct
{
    adrNode First;
} Graph;

/* SELEKTOR */
#define FirstG(G) (G).First
#define Id(Pn) (Pn)->id
#define Adj(Pn) (Pn)->Adj
#define Origin(Pn) (Pn)->origin
#define NextG(Pn) (Pn)->Next

/* KONSTRUKTOR */
void CreateGraph(int X, Graph* G); 
/* ALOKASI DAN DEALOKASI */
adrNode AlokNodeGraph(int X); 
void DeAlokNodeGraph(adrNode P); 
adrSuccNode AlokSuccNode(adrNode Pn);
void DealokSuccNode(adrSuccNode P);

/* FUNGSI/OPERASI */
boolean isNodeEqual(adrNode P, int X); 
adrNode SearchNode(Graph G, int X); 
adrSuccNode SearchEdge(Graph G, int prec, int succ);
void InsertNode(Graph* G, int X, adrNode* Pn); 
void InsertEdge(Graph* G, int prec, int succ); 
void PrintAdjList(Graph G);
#endif