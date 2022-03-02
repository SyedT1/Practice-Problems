#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<list>
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
	ll n; cin >> n;
	vector<ll>a, b;
	unordered_map<ll, ll>MP;
	ll k = 0;
	for (ll i = 0; i < n; i++) {
		ll y; cin >> y;
		if (!y)
			continue;
		MP[y] = k++;
		a.push_back(y);
	}
	for (ll i = 0; i < n; i++) {
		ll y; cin >> y;

		if (!y)
			continue;
		b.push_back(y);
	}
	n--;
	ll common = 0;
	for (ll i = 0; i < n; i++) {
		if (a[(i + MP[b[0]]) % n] == b[i]) {
			common++;
		}
	}
	cout << (common == n ? "YES" : "NO") << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}