#include <iostream>
#include <vector>

struct Edge
{
	int src, dest;

};

class Graph
{
	public:
	/* a vector of vectors to represent an adjacency list */
	vector<vector<int>> adjList;

	/* Graph Constructor */
	Graph(vector<Edge> const &edges, int n)
	{
		/* Resize the vector to hold 'n' elements of type vector<int> */

		adjList.resize(n);

		/* add edges to the directed graph */
		for (auto &edge: edges)
		{
			/* insert at the end */
			adjList[edge.src].push_back(edge.dest);

			/*Uncomment the following code for undirected graph */
			//adjList[edge.dest].push_back(edge.src);
			
		}
	}
}





	// std::vector<std::vector<Edge> > graph;

	// int u;

	// for (int i = 0; i < graph[u].size(); ++i)
	// {
		

	// 	Edge edge = graph[u][i];

	// }

	// Edge newEdge;
	// newEdge.dest = 7;
	// ne=src,  8;
	// graph[3].push_back(newEdge);
