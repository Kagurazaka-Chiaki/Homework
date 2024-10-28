
#include <iostream>
#include <queue>
#include <vector>

int const INF = 1e9 + 7;

struct State {
    int x, y;
    int distance;
    int hlost;
};

int main() {
    int n, m;
    long long h;
    std::cin >> n >> m >> h;
    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    // Direction vectors for Up, Down, Left, Right
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    // Check if starting position is valid
    char start_cell = grid[0][0];
    int start_monster = 0;
    if (start_cell == '#') {
        std::cout << -1 << std::endl;
        return 0;
    } else if (start_cell >= '1' && start_cell <= '9') {
        start_monster = start_cell - '0';
        if (h - start_monster <= 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::vector<std::vector<int>> distance(n, std::vector<int>(m, -1));
    std::vector<std::vector<long long>> hlost(n, std::vector<long long>(m, INF));

    std::queue<State> q;
    q.push({0, 0, 0, start_monster});
    distance[0][0] = 0;
    hlost[0][0] = start_monster;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // Early exit if we have reached the target
        if (cur.x == n - 1 && cur.y == m - 1) {
            continue; // We need to continue to ensure we get the shortest path
        }

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            char cell = grid[nx][ny];

            if (cell == '#') continue;

            long long monster_value = 0;
            if (cell >= '1' && cell <= '9') {
                monster_value = cell - '0';
            }

            long long hlost_new = cur.hlost + monster_value;
            long long health_remaining = h - hlost_new;

            if (health_remaining <= 0) continue;

            int distance_new = cur.distance + 1;

            if (distance[nx][ny] == -1) {
                distance[nx][ny] = distance_new;
                hlost[nx][ny] = hlost_new;
                q.push({nx, ny, distance_new, (int) hlost_new});
            } else if (distance[nx][ny] == distance_new) {
                if (hlost_new < hlost[nx][ny]) {
                    hlost[nx][ny] = hlost_new;
                    q.push({nx, ny, distance_new, (int) hlost_new});
                }
            }
        }
    }

    if (distance[n - 1][m - 1] == -1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << distance[n - 1][m - 1] << std::endl;
    }

    return 0;
}
