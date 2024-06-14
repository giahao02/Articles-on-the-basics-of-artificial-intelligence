// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum
// cost path for all the paths
void findMinRoute(vector<vector<int> > tsp)
{
	int sum = 0;
	int counter = 0;
	int j = 0, i = 0;
	int min = INT_MAX;
	map<int, int> visitedRouteList;

	// Starting from the 0th indexed
	// city i.e., the first city
	visitedRouteList[0] = 1;
	int route[tsp.size()];

	// Traverse the adjacency
	// matrix tsp[][]
	while (i < tsp.size() && j < tsp[i].size())
	{

		// Corner of the Matrix
		if (counter >= tsp[i].size() - 1)
		{
			break;
		}

		// If this path is unvisited then
		// and if the cost is less then
		// update the cost
		if (j != i && (visitedRouteList[j] == 0))
		{
			if (tsp[i][j] < min)
			{
				min = tsp[i][j];
				route[counter] = j + 1;
			}
		}
		j++;

		// Check all paths from the
		// ith indexed city
		if (j == tsp[i].size())
		{
			sum += min;
			min = INT_MAX;
			visitedRouteList[route[counter] - 1] = 1;
			j = 0;
			cout<<i;
			i = route[counter] - 1;
			counter++;
		}
	}

	// Update the ending city in array
	// from city which was last visited
	i = route[counter - 1] - 1;

	for (j = 0; j < tsp.size(); j++)
	{

		if ((i != j) && tsp[i][j] < min)
		{
			min = tsp[i][j];
			cout<<i;
			route[counter] = j + 1;
		}
	}
	sum += min;

	// Started from the node where
	// we finished as well.
	cout << ("Minimum Cost is : ");
	cout << (sum);
}

// Driver Code
int main()
{

	// Input Matrix
	vector<vector<int> > tsp = { { 0, 20, 42, 31, 6, 24 },
								{ 10, 0, 17, 6, 35, 18 },
								{ 25, 5, 0, 27, 14, 9 },
								{ 12, 9, 24, 0, 30, 12 },
								{ 14, 7, 21, 15, 0, 38},
								{ 40, 15, 16, 5, 20, 0}};

	// Function Call
	findMinRoute(tsp);
}

// This code is contributed by grand_master.

