class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
		int n = num1.size();
		int m = num2.size();

		if (m < n) return findMedianSortedArrays(num2, num1);

		int s = -1, e = n + 1;
		while (e - s > 1) {
			int sep1 = (s + e) / 2; 
			int sep2 = (n + m + 1) / 2 - sep1;
			int left_sep1 = (sep1 == 0 ? INT_MIN : num1[sep1 - 1]);
			int left_sep2 = (sep2 == 0 ? INT_MIN : num2[sep2 - 1]); 
			int right_sep1 = (sep1 == n ? INT_MAX : num1[sep1]);
			int right_sep2 = (sep2 == m ? INT_MAX : num2[sep2]);

			if (left_sep1 <= right_sep2  && left_sep2 <= right_sep1) {
				if ((n + m) % 2 == 0) {
					return (max<double>(left_sep1, left_sep2) + min<double>(right_sep1, right_sep2)) / 2;
				} else {
					return max<double>(left_sep1, left_sep2);
				}
			}
			if (left_sep1 > right_sep2) {
				e = sep1;
			} else {
				s = sep1;
			}
		}
		throw "Illeagal argumants";
    }
};
