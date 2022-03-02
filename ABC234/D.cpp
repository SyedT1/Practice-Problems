    #include <iostream>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    int main()
    {
    	//freopen("input.txt", "r", stdin);
    	//freopen("op.txt", "w", stdout);
    	ordered_set o_set;
    	int n, k; cin >> n >> k;
    	for (int i = 0; i < n; i++) {
    		int input; cin >> input;
    		o_set.insert(input);
    		if (i + 1 >= k) {
    			cout << *(o_set.find_by_order(i + 1 - k)) << endl;
    		}
    	}
    	return 0;
    }
