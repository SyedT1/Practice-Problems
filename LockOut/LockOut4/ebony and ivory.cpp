#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define FOR(i, n) for (i = 0; i < n; i++)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;
ll init = 0;
ostream &operator<<(ostream &out, vector<ll> v)
{
	for (ll i : v)
	{
		out << i << ' ';
	}
	return out;
}
istream &operator>>(istream &in, vector<ll> &v)
{
	ll l = len(v);
	FOR(init, l)
	{
		cin >> v[init];
	}
	return in;
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll a, b, c; cin >> a >> b >> c;
	for (int i = 0; i <= c; i++) {
		for (int j = 0; j <= c; j++) {
			if (a * i + b * j == c) {
				cout << "Yes" << nline;
				return;
			}
		}
	}
	cout << "No" << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}