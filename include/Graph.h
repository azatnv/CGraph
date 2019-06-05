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
	unsigned int size;
}Graph;

Graph init(unsigned int size);
int equals(Graph g1, Graph g2);
int size(Graph g);

Graph addNode(Graph g, unsigned int key);
Graph addEdge(Graph g, unsigned int key1, unsigned int key2, unsigned int weight);
Graph RebuildEdge(Graph g, unsigned int key1, unsigned int key2);

int searchNode(Graph g, unsigned int key);
int searchEdge(Graph g, unsigned int key1, unsigned int key2);
int searchEdgeWithWeight(Graph g, unsigned int key1, unsigned int key2, unsigned int weight);

void deleteNode(Graph g, unsigned int key);
void deleteEdge(Graph h, unsigned int key1, unsigned int key2);
void Delete(Graph h, unsigned int key1, unsigned int key2);
void Destruct(Graph g);
void GraphToString(Graph g, FILE* fileout);