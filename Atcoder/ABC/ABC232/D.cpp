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
vector<char>p;
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
void findmx(vector<vector<char>>&v, ll x, ll xlen, ll y, ll ylen, ll &mxval) {
	if (x == xlen || y == ylen) {
		return;
	}
	if (v[x][y] == '#') {
		mxval = max((ll)p.size(), mxval);
		return;
	}
	p.pb(v[x][y]);
	findmx(v, x + 1, xlen, y, ylen, mxval);
	findmx(v, x, xlen, y + 1, ylen, mxval);
	if (x == xlen - 1 && y == ylen - 1) {
		mxval = max((ll)p.size(), mxval);
	}
	p.pop_back();
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m; cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m, '\0'));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	ll mx = 0;
	findmx(v, 0, n, 0, m, mx);
	cout << mx << nline;
}