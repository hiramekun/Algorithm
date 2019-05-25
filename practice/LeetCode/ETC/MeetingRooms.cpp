class Solution {
	public:
		bool canAttendMeetings(vector<vector<int>>& intervals) {
			int n = intervals.size();
			sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];}); 

			for (int i = 0; i < n - 1; i++) {
				if (intervals[i][1] > intervals[i + 1][0]) return false;
			}
			return true;
		}
};
