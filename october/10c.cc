#include <iostream>
#include <stack>
#include <utility>
using namespace std;

stack< pair<int, int> > line;

int main() {
	int n; cin >> n;
	long long ret = 0LL;
	for (int i = 0; i < n; i++) {
		int h; cin >> h;
		pair<int, int> tmp = make_pair(h, 1);
		while (1) {
			if (line.empty() || line.top().first > h) break;
			ret += 1ll*(line.top().second);
			if (line.top().first == h) tmp.second += line.top().second;
			line.pop();
		}
		ret += 1ll*(!line.empty());
		line.push(tmp);
	}
	cout << ret << endl;
	return 0;
}