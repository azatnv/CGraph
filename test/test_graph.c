#include "Graph.h"
#include "test.h"

void test_graph() 
{
	Graph g = init(3);
	g = addEdge(g, 0, 1, 5);
	g = addEdge(g, 1, 2, 5);
	g = addEdge(g, 2, 0, 5);

	if (searchEdge(g, 0, 1) != 5 || searchEdge(g, 2, 1) != 5 || searchEdge(g, 2, 0) != 5 || searchEdge(g, 0, 3) != -1)
		printf("Error in the test: SearchEdge\n");
	else
		printf("Success: SearchEdge\n");
	if (searchEdgeWithWeight(g, 0, 1, 5) != 1 || searchEdgeWithWeight(g, 0, 1, 10) != 0)
		printf("Error in the test: SearchEdgeWhitWeight\n");
	else
		printf("Success: SearchEdgeWhitWeight\n");
	if (searchNode(g, 0) != 1 || searchNode(g, 3) != 0)
		printf("Error in the test: SearchNode\n");
	else
		printf("Success: SearchNode\n");

	if (searchEdgeWithWeight(g, 0, 1, 5) != 1 || searchEdgeWithWeight(g, 1, 2, 5) != 1 || searchEdgeWithWeight(g, 0, 2, 5) != 1)
		printf("Error in the test: AddEdge\n");
	else
		printf("Success: AddEdge\n");

	g = addNode(g, 3);
	if (searchNode(g, 3) != 1 || size(g) != 4)
		printf("Error in the test: AddNode\n");
	else
		printf("Success: AddNode\n");

	deleteEdge(g, 0, 1);
	deleteNode(g, 2);
	if (searchEdge(g, 0, 1) != -1)
		printf("Error in the test: DeleteEdge\n");
	else
		printf("Success: DeleteEdge\n");
	if (searchEdge(g, 0, 2) != -1 || searchNode(g, 2) == 1)
		printf("Error in the test: DeleteNode\n");
	else
		printf("Success: DeleteNode\n");
	Destruct(g);

	Graph g1 = init(3);
	Graph g2 = init(3);
	g1 = addEdge(g1, 0, 1, 7);
	g1 = addEdge(g1, 1, 2, 6);
	g1 = addNode(g1, 10);
	g2 = addEdge(g2, 0, 1, 7);
	g2 = addEdge(g2, 1, 2, 6);
	g2 = addNode(g2, 10);
	if (size(g1) != 4 && size(g2) != 4)
		printf("Error in the test: size\n");
	else 
		printf("Success: size\n");
	if (equals(g1, g2) != 1)
		printf("Error in the test: Equals\n");
	else 
		printf("Success: Equals\n");
	Destruct(g1);
	Destruct(g2);
}