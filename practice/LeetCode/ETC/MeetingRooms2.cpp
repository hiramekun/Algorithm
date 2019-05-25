class Solution {
	public:
		int minMeetingRooms(vector<vector<int>>& intervals) {
			sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
			priority_queue<int, vector<int>, greater<>> que;
			int n = intervals.size();

			for (int i = 0; i < n; i++) {
				if (que.empty()) {
					que.push(intervals[i][1]);
				} else if (que.top() <= intervals[i][0]) {
					que.pop();
					que.push(intervals[i][1]);
				} else {
					que.push(intervals[i][1]);
				}
			}
			return que.size();
		}
};
