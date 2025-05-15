#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct State
{
    int bx, by, wx, wy, steps;
    State(int bx, int by, int wx, int wy, int steps) : bx(bx), by(by), wx(wx), wy(wy), steps(steps) {}
};

int n, m;
vector<vector<int>> matrix;
int target_x, target_y;
bool visited[7][7][7][7];                                  // œ‰◊”Œª÷√(bx,by)£¨∞·‘À
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

vector<pair<int, int>> getWorkerReachable(int bx, int by, int wx, int wy)
{
    vector<pair<int, int>> reachable;
    bool workerVisited[7][7] = {false};
    queue<pair<int, int>> q;
    q.push({wx, wy});
    workerVisited[wx][wy] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        reachable.push_back({x, y});
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !workerVisited[nx][ny] && matrix[nx][ny] != 1 && (nx != bx || ny != by))
            {
                workerVisited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return reachable;
}

int bfs()
{
    int box_x, box_y, worker_x, worker_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 2)
            {
                box_x = i;
                box_y = j;
            }
            else if (matrix[i][j] == 3)
            {
                target_x = i;
                target_y = j;
            }
            else if (matrix[i][j] == 4)
            {
                worker_x = i;
                worker_y = j;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    queue<State> q;
    q.push(State(box_x, box_y, worker_x, worker_y, 0));
    visited[box_x][box_y][worker_x][worker_y] = true;

    while (!q.empty())
    {
        State curr = q.front();
        q.pop();

        if (curr.bx == target_x && curr.by == target_y)
        {
            return curr.steps;
        }


        for (int i = 0; i < 4; i++)
        {
            int dx = dirs[i][0];
            int dy = dirs[i][1];

            if (curr.wx == curr.bx - dx && curr.wy == curr.by - dy)
            {
                int new_bx = curr.bx + dx;
                int new_by = curr.by + dy;

                if (new_bx >= 0 && new_bx < n && new_by >= 0 && new_by < m && matrix[new_bx][new_by] != 1)
                {
                    int new_wx = curr.bx;
                    int new_wy = curr.by;
                    if (!visited[new_bx][new_by][new_wx][new_wy])
                    {
                        visited[new_bx][new_by][new_wx][new_wy] = true;
                        q.push(State(new_bx, new_by, new_wx, new_wy, curr.steps + 1));
                    }
                }
            }
        }
        
        vector<pair<int, int>> reachable = getWorkerReachable(curr.bx, curr.by, curr.wx, curr.wy);
        for (auto pos : reachable)
        {
            int new_wx = pos.first;
            int new_wy = pos.second;
            if (!visited[curr.bx][curr.by][new_wx][new_wy])
            {
                visited[curr.bx][curr.by][new_wx][new_wy] = true;
                q.push(State(curr.bx, curr.by, new_wx, new_wy, curr.steps));
            }
        }
    }
    return -1;
}

int main()
{
    ifstream inputFile("in.txt");
    inputFile >> n >> m;
    matrix.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();
    int ans = bfs();
    cout << ans << endl;
    return 0;
}