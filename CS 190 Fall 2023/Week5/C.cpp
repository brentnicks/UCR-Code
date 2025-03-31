#include <iostream>
#include <limits.h>

using namespace std;

int v, e;

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX;
    int minIndex;

    for (int i = 0; i < v; v++){
        if (sptSet[i] == false && dist[i] <= min){
            min = dist[i], minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[v][v], int src){
    int dist[v];
    bool sptSet[v];

    for (int i = 0; i < v; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < v - 1; count++){
        int u = minDistance(dist, sptSet, v);
        sptSet[u] = true;
        for (int i = 0; i < v; i++){
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i]){
                dist[i] = dist[u] + graph[u][i];
            }
        }
    } 
}

int main(){
    cin >> v >> e;
    int graph[v][v];
    int dist[v];

    dijkstra(graph, 0);

    for (int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;

    return 0;
}