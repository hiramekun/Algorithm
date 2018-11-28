#include <unistd.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
vector<vector<vector<int> > > past_states;
vector<int> costs, gs;
int state_current[2][3];
int state_correct[2][3] = {{1, 2, 3},
                           {4, 5, -1}};

void print_state() {
    for (auto &i : state_current) {
        for (int j : i) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_correct() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state_current[i][j] != state_correct[i][j]) return false;
        }
    }
    return true;
}

bool searched() {
    for (auto &state : past_states) {
        for (int j = 0; j < 2; ++j) {
            bool is_break = false;
            for (int k = 0; k < 3; ++k) {
                if (state[j][k] != state_current[j][k]) {
                    is_break = true;
                    break;
                }
            }
            if (is_break) break;
            if (j == 1) return true;
        }
    }
    return false;
}


int calc_h_hat() {
    int sum = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state_current[i][j] != state_correct[i][j]) sum++;
        }
    }
    return sum;
}

struct state_info {
    vector<vector<int> > state;
    int cost;
};

vector<state_info> all_state_info;


void add_state(int cost) {
    vector<vector<int>> state;
    state.resize(2, vector<int>(3));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            state[i][j] = state_current[i][j];
        }
    }
    state_info info;
    info.state = state;
    info.cost = cost;
    all_state_info.emplace_back(info);
}


int get_past_state() {
    for (int i = 0; i < all_state_info.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            bool b = false;
            for (int k = 0; k < 3; ++k) {
                if (all_state_info[i].state[j][k] != state_current[j][k]) {
                    b = true;
                    break;
                }
            }
            if (b) break;
            if (j == 1) return i;
        }
    }
    return -1;
}

void update_state(int idx, int cost) {
    vector<vector<int>> state;
    state.resize(2, vector<int>(3));
    for (int i1 = 0; i1 < 2; ++i1) {
        for (int j = 0; j < 3; ++j) {
            state[i1][j] = state_current[i1][j];
        }
    }
    state_info info;
    info.state = state;
    info.cost = cost;
    all_state_info[idx] = info;
}


void move(int ix, int iy) {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int status_code = get_past_state();
    int cost_gs = gs[gs.size() - 1] + 1;
    gs.emplace_back(cost_gs);

    for (int i = 0; i < 4; i++) {
        int nx = ix + dx[i], ny = iy + dy[i];
        if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
            int cur_num = state_current[nx][ny];
            state_current[ix][iy] = cur_num;
            state_current[nx][ny] = -1;
            int cost = cost_gs + calc_h_hat();
            if (status_code == -1) {
                printf("new cost: %d\n", cost);
                add_state(cost);
                break;
            } else {
                state_info past_state = all_state_info[status_code];
                if (past_state.cost > cost) {
                    update_state(status_code, cost);
                    printf("update cost: %d\n", cost);
                    break;
                } else {
                    state_current[nx][ny] = cur_num;
                    state_current[ix][iy] = -1;
                }
            }
        }
    }
}


int main() {
    for (auto &i : state_current) for (int &j : i) cin >> j;
    gs.emplace_back(0);
    costs.emplace_back(calc_h_hat());

    while (!is_correct()) {
        for (int i = 0; i < 2; ++i) {
            bool b = false;
            for (int j = 0; j < 3; ++j) {
                if (state_current[i][j] == -1) {
                    move(i, j);
                    print_state();
                    sleep(1);
                    if (is_correct()) return 0;
                    b = true;
                    break;
                }
            }
            if (b) break;
        }
    }
    return 0;
}

