class Solution {
public:
    double myPow(double x, long long int n) {
		if (n < 0) x = 1 / x, n = -n;

		double pow2 = x;
		long long int time = 1;
		while (time < n) pow2 *= pow2, time *= 2;

		for (long long int  i = 1; i <= time - (long long int) n; i++) {
			pow2 /= x;
		}

		return pow2;
    }
};
