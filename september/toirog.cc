#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int r; scanf("%d", &r);
    printf("%.6f\n%.6f\n", r * r * 4 * atan(1), 2.0 * r * r);

return 0;
}