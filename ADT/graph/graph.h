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

/* ----- SELEKTOR ----- */
#define FirstG(G) (G).First
#define Id(Pn) (Pn)->id
#define Adj(Pn) (Pn)->Adj
#define Origin(Pn) (Pn)->origin
#define NextG(Pn) (Pn)->Next

/* ----- KONSTRUKTOR ----- */
void CreateGraph(int X, Graph* G); // membuat graph baru
/* ----- MANAJEMEN MEMORI ----- */
adrNode AlokNodeGraph(int X); // mengembalikan hasil alokasi simpul
void DeAlokNodeGraph(adrNode P); // mengembalikan simpul ke sistem
adrSuccNode AlokSuccNode(adrNode Pn); // mengembalikan hasil alokasi succ simpul
void DealokSuccNode(adrSuccNode P); // mengembalikan succ simpul ke sistem

/* ----- OPERASI GRAF ----- */
boolean isNodeEqual(adrNode P, int X); // mengembalikan apakah P memiliki Id X
adrNode SearchNode(Graph G, int X); // mencari X pada G, return nil jika tiada
adrSuccNode SearchEdge(Graph G, int prec, int succ); // mencari succ dari prec pada G, return nil jika tiada
void InsertNode(Graph* G, int X, adrNode* Pn); // memasang X ke akhir G
void InsertEdge(Graph* G, int prec, int succ); // memasang succ ke akhir prec
void PrintAdjList(Graph G);
#endif