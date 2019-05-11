class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> queue;
    int k = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int e: nums) {
            if (queue.size() < k) queue.push(e);
            else {
                if (queue.top() < e) queue.pop(), queue.push(e);
            }
        }
    }
    
    int add(int val) {
        if (queue.size() < k) {
            queue.push(val);
            return queue.top();
        }
        else if (val <= queue.top()) return queue.top();
        else {
            queue.pop(), queue.push(val);
            return queue.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
