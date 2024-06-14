#include<bits/stdc++.h>
using namespace std;

//7 11
//0 1
//0 3
//1 2
//1 3
//1 5
//1 6
//2 3
//2 4
//2 5
//3 4
//4 6

int n, m;
vector<int> a[100];
bool visited[100];

void inp(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout<<u<<" ";
	//Danh dau u da duoc tham
	visited[u]=true;
	for(int v : a[u]){
		//Neu dinh v chua duoc tham
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	inp();
	dfs(1);
	return 0;
}
