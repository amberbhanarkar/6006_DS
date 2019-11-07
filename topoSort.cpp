#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topoSortUtil(int v, bool visited[], stack<int> &Stack);
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void topoSort();
};

Graph::Graph(int v)
{
	this->V=v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topoSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			topoSortUtil(*i,visited,Stack);
		}
	}
	Stack.push(v);
}

void Graph::topoSort()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			topoSortUtil(i,visited,Stack);
		}
	}
	while(Stack.empty()==false)
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	cout<<"Topo sort is ";
	g.topoSort();
}
