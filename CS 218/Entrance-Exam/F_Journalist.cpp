#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int venueCount;
    cin >> venueCount;

    vector<int> venues(venueCount);

    for (int i = 0; i < venueCount; i++) {
        int venue;
        cin >> venue;
        venues[i] = venue;
    }

    int t;
    cin >> t;

    vector<vector<pair<int,int>>> adjList(n); // (distance, index)

    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adjList[u].push_back({l,v});
        adjList[v].push_back({l,u});
    }

    int largestDist = 0;

    for (int i = 0; i < venueCount; i++) {
        vector<int> distList(n, INT_MAX);
        int start = venues[i];
        distList[start] = 0;

        vector<bool> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            for (auto& neighbor : adjList[node]) {
                auto [neighborDist, neighborNode] = neighbor;
                if (dist + neighborDist < distList[neighborNode]) {
                    distList[neighborNode] = dist + neighborDist;
                    pq.push({distList[neighborNode], neighborNode});
                }
            }
        }

        for (int j = 0; j < venueCount; j++) {
            largestDist = max(largestDist, distList[venues[j]]);
        }
    }

    cout << fixed << setprecision(3) << largestDist / (t * 60.0) << endl;

    return 0;
}