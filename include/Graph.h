#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

typedef struct Node {
	int elem[2];
	Node* next;
}Node;

typedef struct Graph {
	Node** head;
	int size;
}Graph;

Graph init(int size);
int equals(Graph g1, Graph g2);
int size(Graph g);

Graph addNode(Graph g, int key);
Graph addEdge(Graph g, int key1, int key2, int weight);
Graph RebuildEdge(Graph g, int key1, int key2);

int searchNode(Graph g, int key);
int searchEdge(Graph g, int key1, int key2);
int searchEdgeWithWeight(Graph g, int key1, int key2, int weight);

void deleteNode(Graph g, int key);
void deleteEdge(Graph h, int key1, int key2);
void Delete(Graph h, int key1, int key2);
void Destruct(Graph g);
void GraphToString(Graph g, FILE* fileout);