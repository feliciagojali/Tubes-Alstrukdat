#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

/* ----- KONSTRUKTOR ----- */
void CreateGraph(int X, Graph* G)
{
    FirstG(*G) = NilGraph;
    adrNode dummy;
    InsertNode(G, X, &dummy);
}

/* ----- MANAJEMEN MEMORI ----- */
adrNode AlokNodeGraph(int X)
{
    adrNode P = (adrNode) malloc (sizeof(NodeGraph));
    if (P != NilGraph) {
        Id(P) = X;
        Adj(P) = NilGraph;
        NextG(P) = NilGraph;
 }
    return P;
}

void DeAlokNodeGraph(adrNode P)
{
    free(P);
}

adrSuccNode AlokSuccNode(adrNode Pn)
{
    adrSuccNode P = (adrSuccNode) malloc (sizeof(SuccNode));
    if (P != NilGraph) {
        Origin(P) = Pn;
        NextG(P) = NilGraph;
    }
 return P;
}

void DealokSuccNode(adrSuccNode P)
{
    free(P);
}

boolean isNodeEqual(adrNode P, int X){
 return (Id(P)==X);
}

/* ----- OPERASI GRAF ----- */
adrNode SearchNode(Graph G, int X)
{
    adrNode P = FirstG(G);
    while(P != NilGraph){
  if (isNodeEqual(P, X))
   return P;
  else
   P = NextG(P);
 }
    return P;
}

adrSuccNode SearchEdge(Graph G, int prec, int succ)
{
    adrNode Pn = SearchNode(G, prec);
 if (Pn == NilGraph)
  return NilGraph;
 adrSuccNode P = Adj(Pn);
    while(P != NilGraph){
  if (isNodeEqual(Origin(P), succ))
   return P;
  else
   P = NextG(P);
 }
 return P;
}

void InsertNode(Graph* G, int X, adrNode* Pn)
{
    *Pn = AlokNodeGraph(X);
 adrNode P = FirstG(*G);
 if (P == NilGraph)
  FirstG(*G) = *Pn;
 else {
  while (NextG(P) != NilGraph)
   P = NextG(P);
  NextG(P) = *Pn;
 }
}

void InsertEdge(Graph* G, int prec, int succ)
{
    if (SearchEdge(*G, prec, succ) == NilGraph){
  adrNode Pn = SearchNode(*G, prec);
  if (Pn == NilGraph)
   InsertNode(G, prec, &Pn);
  adrNode Ps = SearchNode(*G, succ);
  if (Ps == NilGraph)
   InsertNode(G, succ, &Ps);
  
  adrSuccNode P = Adj(Pn);
  if (P == NilGraph)
   Adj(Pn) = AlokSuccNode(Ps);
  else {
   while (NextG(P) != NilGraph)
    P = NextG(P);
   NextG(P) = AlokSuccNode(Ps);
  }
 }
 
}

void PrintAdjList(Graph G)
{
 if(FirstG(G) == NilGraph){
  printf("empty");
 } else {
  adrNode t = FirstG(G);
  while(t != NilGraph){
   printf("%d : ", Id(t));
   adrSuccNode Ad = Adj(t);
   while(Ad != NilGraph){
    printf("%d ", Id(Origin(Ad)));
    Ad = NextG(Ad);
   }
   printf("\n");
   t = NextG(t);
  }
 }
}