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
void solve() {
	ll color[3] = {};
	for (ll &i : color) {
		cin >> i;
	}
	sort(color, color + 3);
	ll pars = 0;
	while (true) {
		ll mN = min(color[1], color[0]);
		color[1] -= mN;
		color[0] -= mN;
		pars += mN;
		if (color[1] == 0 || color[0] == 0) {
			break;
		}
	}
	sort(color, color + 3);
	color[2] -= color[1];
	if (color[2] <= 2 * pars + 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--)
		solve();
	return 0;
}