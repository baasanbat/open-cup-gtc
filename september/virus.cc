#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

char board[51][51];
int virus[51][51];
int human[51][51];
int coord[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<pair<int, int>> q;
int main() {
    memset(virus, -1, sizeof virus);
    memset(human, -1, sizeof human);
    int r, c; scanf("%d%d", &r, &c);
    pair<int, int> d, s;

    for (int i = 0; i < r; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'S')
                s = make_pair(i, j),
                human[i][j] = 0;
            if (board[i][j] == 'D')
                d = make_pair(i, j);
            if (board[i][j] == '*')
                q.push(make_pair(i, j)),
                virus[i][j] = 0;
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (size_t i = 0; i < 4; i++) {
            int dx = x+coord[i][0];
            int dy = y+coord[i][1];
            if (dx<0 || dx>=r) continue;
            if (dy<0 || dy>=c) continue;
            if (virus[dx][dy] == -1 && board[dx][dy] != 'X' && board[dx][dy] != 'D') {
                q.push(make_pair(dx, dy));
                virus[dx][dy] = virus[x][y] + 1;
            }
        }
    }

    q.push(s);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (size_t i = 0; i < 4; i++) {
            int dx = x+coord[i][0];
            int dy = y+coord[i][1];
            if (dx<0 || dx>=r) continue;
            if (dy<0 || dy>=c) continue;
            if (human[dx][dy] == -1 && board[dx][dy] != 'X') {
                if (human[x][y]+1 < virus[dx][dy] || virus[dx][dy] == -1) {
                    human[dx][dy] = human[x][y]+1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }

    if (human[d.first][d.second] == -1)
        printf("bolomjgui\n");
    else
        printf("%d\n", human[d.first][d.second]);

return 0;
}