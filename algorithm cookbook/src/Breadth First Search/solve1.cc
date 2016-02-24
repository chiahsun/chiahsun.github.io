#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

const int M = 50;
char nodes[M][30];

int pos_node = 0;
std::vector<int> adjacent_nodes[M];

void init() {
    pos_node = 0;
    for (int i = 0; i < M; ++i) adjacent_nodes[i].clear();
}

int get_node() {
    char name[30];
    scanf("%s", name);
    for (int i = 0; i < pos_node; ++i)
        if (!strcmp(name, nodes[i]))
            return i;
    strcpy(nodes[pos_node++], name);
    return pos_node-1;
}

bool bfs(int source, int sink, std::vector<int> & path) {
    int enqueued[M], prev[M], distance[M];
    memset(enqueued, false, sizeof(enqueued));
    memset(distance, 0, sizeof(distance));

    std::queue<int> queue;
    queue.push(source); enqueued[source] = true; prev[source] = source; distance[source] = 0;
    while (not queue.empty()) {
        int cur = queue.front(); queue.pop();
        if (cur == sink) break;
        for (auto next : adjacent_nodes[cur]) {
            if (not enqueued[next]) {
                queue.push(next); enqueued[next] = true; prev[next] = cur; distance[next] = distance[cur]+1; 
            }     
        }
    }

    path.clear();
    if (not enqueued[sink]) return 0;

    int now = sink;
    while (prev[now] != now) {
        path.push_back(now);
        now = prev[now];
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    return true;
}

void print_path(const std::vector<int> & path) {
    for (int i = 0; i < path.size(); ++i) {
        printf("%s%s", i != 0 ? " -> " : "", nodes[path[i]]);
    }
    printf("\n");
}

int main() {
    init();

    int n_node;
    scanf("%d", &n_node);

    for (int i = 0; i < n_node; ++i) {
        int from = get_node();
        int n_next;
        scanf("%d", &n_next);
        while (n_next--) {
            int to = get_node();
            adjacent_nodes[from].push_back(to);
        }
    }
    int n_query;
    scanf("%d", &n_query);
    while (n_query--) {
        std::vector<int> path;
        int from = get_node(), to = get_node();
        if (bfs(from, to, path)) 
            print_path(path);
        else
            printf("There is no path from %s -> %s\n", nodes[from], nodes[to]);
    }
    
    return 0;
}
