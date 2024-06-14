#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int x = 10;
const int colors[x] = { 0,1,2,3,4,5,6,7,8,9 };
int counter = 0;
bool problem = false;

/*  
	 B      G---------J
	/ \      \        |
       /   \      \       |
      /     \      \      |
     A------C-------E-----K
     \     /       /      |
      \   /       /       |
       \ /       /        |
        D-------F---------L

*/

bool graf[x][x] = {
	0,1,1,1,0,0,0,0,0,0,
	1,0,1,0,0,0,0,0,0,0,
	1,1,0,1,1,0,0,0,0,0,
	1,0,1,0,0,1,0,0,0,0,
	0,0,1,0,0,1,1,0,1,0,
	0,0,0,1,1,0,0,0,1,1,
	0,0,0,0,1,0,0,1,0,0,
	0,0,0,0,0,0,1,0,1,0,
	0,0,0,0,1,0,0,1,0,1,
	0,0,0,0,0,1,0,0,1,0
};

char vertex_names[x] = {'A','B','C','D','E','F','G','J','K','L'};
int rate_list[x]; 

struct Graf {
	char vertex_id[x];
	int vertex_rates[x];
	bool adj[x][x];
	int colors[x];
	bool colored[x];
};

void ToMau(Graf g) {
	counter++;
	int biggest=0;
	int temp_rate = 0;
	if (counter == 1)
		for (int i = 0; i < x; i++)
			for (int j = 0; j < x; j++)
				if (g.adj[i][j])
					rate_list[i]++;

	for (int w = 0; w < x; w++)
		if (!g.colored[w]) {
			g.vertex_rates[w] = rate_list[w];
			if (temp_rate < g.vertex_rates[w]) {
				temp_rate = g.vertex_rates[w];
				biggest = w;
			}
		}

	g.colors[biggest] = colors[counter];
	cout << g.vertex_id[biggest] <<":color "<< g.colors[biggest]<<endl;

	for (int e=0;e < x;e++)
		if (!g.adj[biggest][e] && biggest!=e && !g.colored[e]) {
			for (int t = 0; t < x;t++) {

				if(g.adj[e][t] &&g.colors[t]==g.colors[biggest]) problem = true;

					if (t == x - 1 && !problem) {
						g.colors[e] = colors[counter];
						cout << g.vertex_id[e] <<":color "<< g.colors[e] << endl;
						g.colored[e] = true;
						problem = false;
					}
					else if (t == x - 1) problem = false;
			}
		}

		g.colored[biggest] = true;

	if (all_of(begin(g.colored), end(g.colored), [](bool i) { return i; })) {
		cout << "Graph full colored" << endl;
		system("pause");
		exit(EXIT_SUCCESS);

	}

	else ToMau(g);

}

int main()
{
	Graf graf1;
	
	for (int y = 0; y < x; y++) {
		graf1.colors[y] = 99;
		graf1.colored[y] = false;
	}

	memcpy(&graf1.adj, &graf, sizeof(graf1.adj));
	memcpy(&graf1.vertex_id, &vertex_names, sizeof(graf1.vertex_id));

	ToMau(graf1);

	return 0;
}
