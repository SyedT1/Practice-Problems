#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cmath>
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
	ll len, y; cin >> len >> y;
	double sQ = sqrt(8 * y + 1);
	ll intQ = ll(sQ);
	bool state = sQ != ll(sQ);
	if (state) {
		if (intQ % 2 == 0) {
			intQ++;
		} else {
			intQ += 2;
		}
	}
	else {
		if (intQ % 2 == 0) {
			intQ++;
		}
	}
	ll lf = ((intQ + 1) / 2);
	string construct = string(len, 'a');
	ll yrd = (lf * (lf - 1)) / 2;
	construct[abs(len - lf)] = 'b';
	ll dif = abs(yrd - y);
	construct[abs(len - lf) + dif + 1] = 'b';
	cout << construct << nline;
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