#include "Graph.h"

int main(int argc, char* argv[])
{
	if (argc > 3)
	{
		printf("error: many arguments\n");
		return 101;
	}
	if (argc == 3)
	{
		FILE *filein;
		FILE *fileout;
		filein = freopen(argv[1], "r", stdin);
		fileout = fopen(argv[2], "w");
		if (filein == NULL)
		{
			printf("ERROR: file is empty\n");
			return 911;
		}
		else
		{
			Graph g = init(2);
			unsigned int key1;
			unsigned int key2;
			unsigned int weight;
			while (fscanf(filein, "%u%u%u", &key1, &key2, &weight) != EOF) {
				g = addEdge(g, key1, key2, weight);
			}
			GraphToString(g, fileout);
			Destruct(g);
		}
	}
	return 0;
}