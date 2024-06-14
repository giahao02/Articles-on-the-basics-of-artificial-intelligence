// C++ program to implement Best First Search using priority
// queue
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
 
vector<vector<pi> > graph;
 
// Function for adding edges to graph
void addedge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}
 
// Function For Implementing Best First Search
// Gives output path having lowest cost
void best_first_search(int source, int target, int n)
{
    vector<bool> Close(n, false);
    // MIN HEAP priority queue
    priority_queue<pi, vector<pi>, greater<pi> > Open;
    // sorting in pq gets done by first value of pair
    Open.push(make_pair(0, source));
    int s = source;
    Close[s] = true;
    while (!Open.empty()) {
        int x = Open.top().second;
        // Displaying the path having lowest cost
        cout << x << " ";
        Open.pop();
        if (x == target)
            break;
 
        for (int i = 0; i < graph[x].size(); i++) {
            if (!Close[graph[x][i].second]) {
                Close[graph[x][i].second] = true;
                Open.push(make_pair(graph[x][i].first,graph[x][i].second));
            }
        }
    }
}
 
// Driver code to test above methods
int main()
{
    // No. of Nodes
    int v = 10;
    graph.resize(v);
 
    // The nodes shown in above example(by alphabets) are
    // implemented using integers addedge(x,y,cost);
    addedge(0, 1, 20);
    addedge(0, 2, 35);
    addedge(0, 3, 30);
    addedge(1, 4, 40);
    addedge(1, 5, 45);
    addedge(2, 5, 15);
    addedge(2, 6, 10);
    addedge(4, 7, 30);
    addedge(4, 8, 25);
    addedge(5, 9, 10);
    addedge(6, 9, 20);
 
    int source = 0;
    int target = 9;
 
    // Function call
    best_first_search(source, target, v);
 
    return 0;
}
