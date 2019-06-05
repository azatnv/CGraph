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
			int key1;
			int key2;
			int weight;
			while (fscanf(filein, "%i%i%i", &key1, &key2, &weight) != EOF) {
				g = addEdge(g, key1, key2, weight);
			}
			GraphToString(g, fileout);
			Destruct(g);
		}
	}
	return 0;
}