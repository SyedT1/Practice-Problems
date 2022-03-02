#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define loop(x, n) for(int x = 0; x < n; ++ x)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;

template <typename T>
ostream &operator<<(ostream &out, pair<T, T>p) {
	out << p.first << ' ' << p.second;
	return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
	for (T i : v)
	{
		out << i << ' ';
	}
	return out;
}
istream &operator>>(istream &in, vector<ll> &v)
{
	for (ll &i : v)
	{
		cin >> i;
	}
	return in;
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void findif(ll sum, ll p, ll q, ll l, ll r, ll burles, bool &condition) {
	if (p == l + 1 || q == r + 1) {
		return;
	}
	findif(sum + q, p + 1, q, l, r, burles, condition);
	findif(sum + p, p, q + 1, l, r, burles, condition);
}
void solve() {
	ll l, r, p; cin >> l >> r >> p;
	bool found = false;
	ll i, j, sum = 0;
	i = j = 1;
	findif(sum, i, j, l, r, p, found);
	cout << vector<string> {"NO", "YES"} [found] << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}