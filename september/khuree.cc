#include <string>
#include <iostream>
using namespace std;

int abs(int x) { return x<=0?-x:x;}

char ret[5][62];

void frame(char alphabet, int c, char frame_char) {
    ret[2][c] = alphabet;
    for (int i = -2; i <= 2; i++)
        for (int j = -2; j <= 2; j++)
            if (abs(i) + abs(j) == 2)
                ret[i+2][c+j] = frame_char;
}

int main() {
    string s; cin >> s;
    for (int i = 0; i < 5; i++) {
        for (size_t j = 0; j <= 4*s.length(); j++) {
            ret[i][j] = '.';
        }
    }

    for (size_t i = 0; i < s.length(); i++) frame(s[i], 4*i+2, '#');
    for (size_t i = 2; i < s.length(); i += 3) frame(s[i], 4*i+2, '*');

    for (int i = 0; i < 5; i++)
        cout << ret[i] << endl;
return 0;
}