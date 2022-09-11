#include <iostream>
using namespace std;
bool mods[42];
int main() {
    for (int i = 0; i < 10; i++) {
        int k; cin >> k;
        mods[k%42] = 1;
    }

    int ret = 0;
    for (size_t i = 0; i < 42; i++)
        ret += mods[i];
    cout << ret << endl;
return 0;}