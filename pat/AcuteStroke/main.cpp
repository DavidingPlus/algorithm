#include <iostream>
#include <queue>
using namespace std;

const int MAX_M = 1286;
const int MAX_N = 128;
const int MAX_L = 60;

struct point {
    int x, y, z;
};

int brain[MAX_L][MAX_M][MAX_N];
bool visited[MAX_L][MAX_M][MAX_N];

int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};

int m, n, l, t;

bool isValid(int x, int y, int z) {
    return x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < l;
}

int bfs(int z, int x, int y) {
    queue<point> q;
    q.push({x, y, z});
    visited[z][x][y] = true;
    int volume = 0;
    while (!q.empty()) {
        point p = q.front();
        q.pop();
        volume++;
        for (int i = 0; i < 6; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];
            if (isValid(nx, ny, nz) && !visited[nz][nx][ny] && brain[nz][nx][ny] == 1) {
                visited[nz][nx][ny] = true;
                q.push({nx, ny, nz});
            }
        }
    }
    return volume;
}

int main() {
    cin >> m >> n >> l >> t;
    for (int z = 0; z < l; z++) {
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                cin >> brain[z][x][y];
                visited[z][x][y] = false;
            }
        }
    }
    int totalVolume = 0;
    for (int z = 0; z < l; z++) {
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (!visited[z][x][y] && brain[z][x][y] == 1) {
                    int volume = bfs(z, x, y);
                    if (volume >= t) {
                        totalVolume += volume;
                    }
                }
            }
        }
    }
    cout << totalVolume << endl;
}