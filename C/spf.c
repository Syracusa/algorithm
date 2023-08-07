#include <stdio.h>
#include <string.h>

#define MAX_DIST 999

typedef struct Edge
{
    int src;
    int dest;
    int weight;
} Edge;

void bellmanford(int vertex_num, int start, Edge *edges, int edge_num)
{
    int dist[vertex_num];
    for (int i = 0; i < vertex_num; i++)
        dist[i] = MAX_DIST;
    dist[start] = 0;

    int prev[vertex_num];
    memset(prev, -1, sizeof(prev));

    for (int i = 0; i < vertex_num - 1; i++)
    {
        for (int j = 0; j < edge_num; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    printf("Vertex Distance from Source - Bellman-Ford\n");
    for (int i = 0; i < vertex_num; i++)
        printf("%d\t\t%d\tprev:%d\n", i, dist[i], prev[i]);
}

void dijkstra(int vertex_num, int start, Edge *edges, int edge_num)
{
    int dist[vertex_num];
    for (int i = 0; i < vertex_num; i++)
        dist[i] = MAX_DIST;
    dist[start] = 0;

    int visited[vertex_num];
    memset(visited, 0, sizeof(visited));

    int prev[vertex_num];
    memset(prev, -1, sizeof(prev));

    for (int i = 0; i < vertex_num - 1; i++)
    {
        int min_dist = MAX_DIST;
        int min_vertex;
        for (int j = 0; j < vertex_num; j++)
        {
            if (visited[j] == 0 && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_vertex = j;
            }
        }

        visited[min_vertex] = 1;

        for (int j = 0; j < edge_num; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (visited[v] == 0 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    printf("Vertex Distance from Source - Dijkstra\n");
    for (int i = 0; i < vertex_num; i++)
        printf("%d\t\t%d\tprev:%d\n", i, dist[i], prev[i]);
}

int main()
{
    int n = 5;
    int m = 6;

    Edge edges[m];
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 1;

    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 4;

    edges[2].src = 1;
    edges[2].dest = 2;
    edges[2].weight = 3;

    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 2;

    edges[4].src = 1;
    edges[4].dest = 4;
    edges[4].weight = 2;

    edges[5].src = 3;
    edges[5].dest = 2;
    edges[5].weight = 5;

    bellmanford(n, 0, edges, m);
    dijkstra(n, 0, edges, m);
    return 0;
}