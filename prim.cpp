#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<utility>

using namespace std;
const int MAX = 1e4+5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	int y;
	long long minCost = 0;
	PII p;
	Q.push(make_pair(0,x));
	while(!Q.empty())
	{	
		p = Q.top();
		Q.pop();
		x = p.second;
		if(marked[x]==true)
		{
			continue;
		}
		minCost += p.first;
		marked[x] = true;
		for(int i=0;i<adj[x].size();i++)
		{
			y = adj[x][i].second;
			if(marked[y]==false)
			{
				Q.push(adj[x][i]);
			}
		}
	}
	return minCost;
}

main()
{
	int nodes, edges, x, y;
	long long weight, minCost;
	cin>>nodes>>edges;
	for(int i=0;i<edges;++i)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	minCost = prim(1);
	cout<<"Minimum Cost: "<<minCost<<endl;
}	

