#include "../graph/graph.c"

int main(){
    Graph G;
    CreateGraph(1, &G);
    InsertEdge(&G, 1, 7);
    InsertEdge(&G, 1, 3);
    InsertEdge(&G, 3, 1);
    InsertEdge(&G, 2, 3);
    InsertEdge(&G, 4, 2);
    PrintAdjList(G);
    return 0;
}