#include <bits/stdc++.h>
using namespace std;

char mino[3][4][4][4];

bool ok(char grid[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(grid[i][j] == '.') return false;
        }
    }
    return true;
}

bool search(char grid[4][4], int k) {
    if(k == 3) return ok(grid);

    for(int r = 0; r < 4; r++) {
        for(int dx = -3; dx <= 3; dx++) {
            for(int dy = -3; dy <= 3; dy++) {

                bool valid = true;

                // 配置可能か確認
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        if(mino[k][r][i][j] == '.') continue;

                        int x = i + dx;
                        int y = j + dy;

                        if(x < 0 || x >= 4 || y < 0 || y >= 4) {
                            valid = false;
                            continue;
                        }

                        if(grid[x][y] == '#') {
                            valid = false;
                        }
                    }
                }

                if(!valid) continue;

                // 配置
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        if(mino[k][r][i][j] == '#') {
                            int x = i + dx;
                            int y = j + dy;
                            grid[x][y] = '#';
                        }
                    }
                }

                if(search(grid, k + 1)) return true;

                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        if(mino[k][r][i][j] == '#') {
                            int x = i + dx;
                            int y = j + dy;
                            grid[x][y] = '.';
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int k = 0; k < 3; k++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> mino[k][0][i][j];
            }
        }
    }

    for(int k = 0; k < 3; k++) {
        for(int r = 0; r < 3; r++) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    mino[k][r+1][j][3-i] = mino[k][r][i][j];
                }
            }
        }
    }

    char emp[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            emp[i][j] = '.';
        }
    }

    cout << (search(emp, 0) ? "Yes" : "No") << '\n';
}