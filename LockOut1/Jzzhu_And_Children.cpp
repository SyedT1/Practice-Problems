#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#include<unordered_map>
#define nline '\n'
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;
void fop_cl() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll n, k; cin >> n >> k;
	vector<ll>v(n), mark(101, 0);
	for (ll &i : v)
		cin >> i;
	queue<pair<ll, ll>>serve;
	for (ll i = 0; i < n; i++) {
		serve.push({v[i], i + 1});
	}
	while (serve.size() > 1) {
		if (serve.front().first - k > 0) {
			serve.push({serve.front().first - k, serve.front().second});
		}
		serve.pop();
	}
	cout << serve.front().second << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}