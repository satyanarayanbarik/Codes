class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minn = prices[0];
        int n = prices.size();
        for(int i = 1; i<n; i++){
            if(prices[i]<minn) minn = prices[i];
            ans = max(ans, prices[i]-minn);
        }
        return ans;
    }
};
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
int init = [] {
	cin.tie(nullptr)->sync_with_stdio(false);
    freopen("user.out", "w", stdout);

    for (string s; getline(cin, s);) {
        int solution = 0, minPrice = INT_MAX;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            int price = s[_i++] & 15;
            while ((s[_i] & 15) < 10) price = price * 10 + (s[_i++] & 15);
            minPrice = min(minPrice, price);
            solution = max(solution, price - minPrice);
        }
    cout << solution << '\n';    }
    return 0;
}();