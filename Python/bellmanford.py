# https://github.com/TheAlgorithms/Python/blob/master/graphs/bellman_ford.py

def bellmanford(
        graph: list[dict[str, int]],
        vertex_count: int, 
        edge_count: int,
        src: int) -> list[float]:
    distance = [float("inf")]  * vertex_count
    distance[src] = 0.0

    for _ in range(vertex_count - 1):
        for j in range(edge_count):
            u, v, w = (graph[j][k] for k in ["src", "dst", "weight"])

            if distance[u] != float("inf") and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w
    return distance

graph = list()
graph.append({"src": 0, "dst": 1, "weight": 1})
graph.append({"src": 0, "dst": 2, "weight": 4})
graph.append({"src": 1, "dst": 2, "weight": 3})
graph.append({"src": 1, "dst": 3, "weight": 2})
graph.append({"src": 1, "dst": 4, "weight": 2})
graph.append({"src": 3, "dst": 2, "weight": 5})

print(bellmanford(graph, 5, 6, 0))
