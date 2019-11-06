#include<iostream>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int v);
		void addEdge(int v, int w);
		void BFS(int v);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	list<int> queue;
	queue.push_back(v);
	list<int>::iterator i;
	while(!queue.empty())
	{
		v = queue.front();
		cout<<v<<" ";
		queue.pop_front();
		for(i=adj[v].begin();i!=adj[v].end();++i)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
}

main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	cout<<"Following is BFS of the graph: ";
	g.BFS(2);
}	

