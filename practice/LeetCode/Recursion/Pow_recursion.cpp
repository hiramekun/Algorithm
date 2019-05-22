class Solution {
	public:
		double rec(double x, long long int n) {
			if (n == 0) return 1;
			double ret = rec(x, n / 2);
			ret *= ret;
			if (n % 2 == 0) ret *= x;
			return ret;
		}
		double myPow(double x, long long int n) {
			if (n < 0) x = 1 / x, n = -n;
			return rec(x, n);
		}
};
