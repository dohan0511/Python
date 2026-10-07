#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n;
int x[1000];
char dir[1000];

int offset = 0;
deque<char> cur_colors; // 'B', 'W'

void color(int pos, char dir) {
    int offpos = pos + offset;

    if (offpos < 0) {
        cur_colors.push_front(' ');
        offset++;
        offpos = 0;
    }
    else if (offpos >= cur_colors.size()) {
        cur_colors.push_back(' ');
    }
    
    if (dir == 'L') {
        cur_colors[offpos] = 'W';
    }
    else if (dir == 'R') {
        cur_colors[offpos] = 'B';
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Please write your code here.

    int cur_pos = 0;
    for (int i = 0; i < n; i++) {
        color(cur_pos, dir[i]);
        for (int j = 1; j < x[i]; j++) {
            if (dir[i] == 'L') cur_pos--;
            else if (dir[i] == 'R') cur_pos++;

            color(cur_pos, dir[i]);
        }
    }

    cout << count(cur_colors.begin(), cur_colors.end(), 'W') << ' ';
    cout << count(cur_colors.begin(), cur_colors.end(), 'B');
    return 0;
}