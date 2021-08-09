#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int size1 = 10;
constexpr int size2 = 8;

bool visited_rec[size1];

int graph[size1][size1] = {
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
};

int graph2[size2][size2] = {
    {0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 1, 0}
};

void dfs(int vertex)
{
    bool visited[size1];
    std::stack<int> neighbors;

    for(int i = 0; i < size1; ++i)
    {
        visited[i] = false;
    }

    neighbors.push(vertex);
    visited[vertex] = true;

    while(!neighbors.empty())
    {
        int vertex = neighbors.top();
        neighbors.pop();
        std::cout << vertex + 1 << ' ';
        for(int i = 0; i < size1; ++i)
        {
            if(graph[vertex][i] != 0 && !visited[i])
            {
                neighbors.push(i);
                visited[i] = true;
            }
        }
    }
    std::cout << std::endl;
}

void dfs_count(int vertex)
{
    bool visited[size2];
    std::pair<int, int> visited_vertecies_count[size2];
    std::stack<int> neighbors;

    for(int i = 0; i < size2; ++i)
    {
        visited[i] = false;
        visited_vertecies_count[i].first = i + 1;
        visited_vertecies_count[i].second = 0;
    }

    neighbors.push(vertex);
    visited[vertex] = true;

    while(!neighbors.empty())
    {
        int vertex = neighbors.top();
        neighbors.pop();
        for(int i = 0; i < size2; ++i)
        {
            if(graph2[vertex][i] != 0)
            {
                visited_vertecies_count[i].second++;
                if(!visited[i])
                {
                    neighbors.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    std::cout << "Vertecies visits count: ";
    for(const auto& p : visited_vertecies_count)
    {
        std::cout << "(" << p.second << "->" << p.first  << ") ";
    }
    std::cout << std::endl;
}

void bfs_count(int vertex)
{
    bool visited[size2];
    std::pair<int, int> visited_vertecies_count[size2];
    std::queue<int> neighbors;

    for(int i = 0; i < size2; ++i)
    {
        visited[i] = false;
        visited_vertecies_count[i].first = i + 1;
        visited_vertecies_count[i].second = 0;
    }

    neighbors.push(vertex);
    visited[vertex] = true;

    while(!neighbors.empty())
    {
        int vertex = neighbors.front();
        neighbors.pop();
        for(int i = 0; i < size2; ++i)
        {
            if(graph2[vertex][i] != 0)
            {
                visited_vertecies_count[i].second++;
                if(!visited[i])
                {
                    neighbors.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    std::cout << "Vertecies visits count: ";
    for(const auto& p : visited_vertecies_count)
    {
        std::cout << "(" << p.second << "->" << p.first  << ") ";
    }
    std::cout << std::endl;
}

void recursive_graph_traversal(int vertex, int& count)
{
    visited_rec[vertex] = true;
    count++;
    std::cout << vertex + 1 << ' ';
    for(int i = 0; i < size1; ++i)
    {
        if(graph[vertex][i] != 0 && !visited_rec[i])
        {
            recursive_graph_traversal(i, count);
        }
    }
}

void bfs(int vertex)
{
    bool visited[size2];
    std::pair<int, int> visited_vertecies_count[size2];
    std::queue<int> neighbors;

    for(int i = 0; i < size2; ++i)
    {
        visited[i] = false;
        visited_vertecies_count[i].first = i + 1;
        visited_vertecies_count[i].second = 0;
    }

    neighbors.push(vertex);
    visited[vertex] = true;

    while(!neighbors.empty())
    {
        int vertex = neighbors.front();
        neighbors.pop();
        std::cout << vertex + 1 << ' ';
        for(int i = 0; i < size2; ++i)
        {
            if(graph2[vertex][i] != 0)
            {
                visited_vertecies_count[i].second++;
                if(!visited[i])
                {
                    neighbors.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    std::cout << std::endl;
    std::sort(std::begin(visited_vertecies_count), std::end(visited_vertecies_count), [](const auto& p1, const auto p2) { return p1.second > p2.second; });

    std::cout << "Vertecies visits count: ";
    for(const auto& p : visited_vertecies_count)
    {
        std::cout << "(" << p.second << "->" << p.first  << ") ";
    }
    std::cout << std::endl;
}

int main()
{
    // ====== TASK #1 ======
    int vertex;
    std::cout << "Input start node (1-10): ";
    std::cin >> vertex;

    std::cout << "Graph traversal: ";
    dfs(vertex - 1);

    // ====== TASK #2 ======
    int vertex2;
    std::cout << "Input start node (1-8): ";
    std::cin >> vertex2;
    dfs_count(vertex2 - 1);
    bfs_count(vertex2 - 1);

    // ====== TASK #3 ======
    int vertex3;
    std::cout << "Input start node (1-10): ";
    std::cin >> vertex3;

    std::cout << "Graph traversal: ";
    int count = -1;
    recursive_graph_traversal(vertex3 - 1, count);
    std::cout << "\nAdjacent vertices count: " << count << std::endl;

    // ====== TASK #4 ======
    int vertex4;
    std::cout << "Input start node (1-8): ";
    std::cin >> vertex4;

    std::cout << "Graph traversal: ";
    bfs(vertex4 - 1);


    return 0;
}

