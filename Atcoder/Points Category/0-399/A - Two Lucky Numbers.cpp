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
#define UPL 1e18
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
	ll a, b ; cin >> a >> b;
	if (a * 2 == b) {
		cout << a << nline;
		return;
	}
	a *= 10;
	while (a < UPL) {
		bool found = false;
		for (ll i = 0; i < 10; i++) {
			string l = to_string(l);
			//push_front and increment
			while (stoll(l) < UPL) {
				for (ll j = 0; j < 9; j++) {
					string t = l;
				}
				l = '1' + l;
			}
			a++;
		}
		a *= 10;
		//push_back and increment
	}
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}