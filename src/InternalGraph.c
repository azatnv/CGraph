#include "Graph.h"
Graph init(int size)
{
	Graph graph;
	graph.head = (Node**)malloc(size * sizeof(Node*));
	for (int i = 0; i < size; i++)
	{
		graph.head[i] = (Node*)malloc(sizeof(Node));
		graph.head[i]->elem[0] = -1;
		graph.head[i]->elem[1] = 0;
		graph.head[i]->next = NULL;
	}
	graph.size = size;
	return graph;
}




Graph addEdge(Graph g, int key1, int key2, int weight)
{
	Node* ptr1 = (Node*)malloc(sizeof(Node)); //создаваемый узел
	Node* ptr2 = (Node*)malloc(sizeof(Node)); //создаваемый узел
	Node* node;
	ptr1->elem[1] = ptr2->elem[1] = weight;
	ptr1->elem[0] = key2;
	ptr2->elem[0] = key1;
	ptr1->next = NULL;
	ptr2->next = NULL;
	if (key1 >= g.size || key2 >= g.size)
		g = RebuildEdge(g, key1, key2);
	g.head[key1]->elem[0] = key1;
	g.head[key2]->elem[0] = key2;
	node = g.head[key1];
	while (node->next != NULL)
		node = node->next;
	node->next = ptr1;
	node = g.head[key2];
	while (node->next != NULL)
		node = node->next;
	node->next = ptr2;
	return g;
}

Graph addNode(Graph g, int key) 
{
	if (key >= g.size)
		g = RebuildEdge(g, key, 0);
	g.head[key]->elem[0] = key;
	return g;
}

Graph RebuildEdge(Graph g, int key1, int key2)
{
	int max = key1;
	int prevSize = g.size;
	if (max < key2)
		max = key2;
	if (prevSize <= max)
	{
		g.head = (Node**)realloc(g.head, (max + 1) * sizeof(Node*));
		g.size = max + 1;
		for (int i = prevSize; i <= max; i++)
		{
			g.head[i] = (Node*)malloc(sizeof(Node));
			g.head[i]->next = NULL;
			g.head[i]->elem[1] = 0;
			g.head[i]->elem[0] = -1;
		}
	}
	return g;
}




void deleteEdge(Graph g, int key1, int key2)
{
	if (key1 >= g.size || key2 >= g.size || g.head[key1]->elem[0] != key1 || g.head[key2]->elem[0] != key2)
		return;
	Delete(g, key1, key2);
	Delete(g, key2, key1);
}

void deleteNode(Graph g, int key)
{
	if (key >= g.size || g.head[key]->elem[0] == -1)
		return;
	for (int i = 0; i < g.size; i++) 
		if (g.head[i]->elem[0] != -1)
		{
			Delete(g, key, i);
			if (i > key)
				Delete(g, i, key);
		}
	Node *current = g.head[key];
	current->elem[0] = -1;
	current->elem[1] = 0;
	current->next = NULL;
}

void Destruct(Graph g)
{
	for (int i = 0; i < g.size; i++)
	{
		deleteNode(g, i);
		free(g.head[i]);
	}
	free(g.head);
}

void Delete(Graph h, int key1, int key2)
{
	Node *current, *previous;
	previous = NULL;
	current = h.head[key1];
	if (current->elem[0] != key1 || h.head[key2]->elem[0] != key2)
		return;
	while (current)
	{
		if (current->elem[0] == key2 && h.head[key1] != current)
		{
			if (current->next != NULL)
			{
				previous->next = current->next;
				free(current);
				current = previous->next;
			}
			else
			{
				previous->next = NULL;
				free(current);
				return;
			}
		}
		else
		{
			previous = current;
			current = previous->next;
		}
	}
}





int searchNode(Graph g, int key) 
{
	if (key >= g.size || g.head[key]->elem[0] == -1)
		return 0;
	return 1;
}

int searchEdge(Graph g, int key1, int key2)
{
	if (searchNode(g, key1) == 0 || searchNode(g, key2) == 0)
		return -1;
	Node* current = g.head[key1];
	while (current)
	{
		if (current->elem[0] == key2)
			return current->elem[1];
		current = current->next;
	}
	return -1;
}

int searchEdgeWithWeight(Graph g, int key1, int key2, int weight) {
	if (searchNode(g, key1) == 0 || searchNode(g, key2) == 0)
		return 0;
	Node* current = g.head[key1];
	while (current)
	{
		if (current->elem[0] == key2 && current->elem[1] == weight)
			return 1;
		current = current->next;
	}
	return 0;
}

int equals(Graph g1, Graph g2)
{
	Node* ptr;
	if (size(g1) != size(g2))
		return 0;
	else
	{
		for (int i = 0; i < g1.size; i++)
		{
			if (g1.head[i]->elem[0] != g2.head[i]->elem[0])
				return 0;
			ptr = g1.head[i];
			ptr = ptr->next;		
			while (ptr)
			{
				int key = ptr->elem[0];
				int weight = ptr->elem[1];
				if (searchEdgeWithWeight(g2, g1.head[i]->elem[0], key, weight) == 0)
					return 0;
				ptr = ptr->next;
			}
		}
	}
	return 1;
}

int size(Graph g)
{
	int result = 0;
	for (int i = 0; i < g.size; i++)
		if (g.head[i]->elem[0] == i)
			result++;
	return result;
}

void GraphToString(Graph g, FILE* fileout)
{
	Node* ptr;
	fprintf(fileout, "Size of Graph: %d\n", size(g));
	for (int i = 0; i < g.size; i++)
	{
		if (g.head[i]->elem[0] != -1) {
			fprintf(fileout, "\nVertex %d connected with: ", i);
			ptr = g.head[i]->next;
			while (ptr)
			{
				fprintf(fileout, " %d(weight %d)", ptr->elem[0], ptr->elem[1]);
				ptr = ptr->next;
			}
		}
	}
}