
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[5];
bool visited[5];

// DFS
void DFS(int node)
{
    cout << node << " ";
    visited[node] = true;

    for (int i : graph[node])
    {
        if (!visited[i])
            DFS(i);
    }
}

// BFS
void BFS(int start)
{
    bool visit[5] = {false};
    queue<int> q;

    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i : graph[node])
        {
            if (!visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    // Connections between buildings
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {1, 2};

    cout << "DFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    return 0;
}
