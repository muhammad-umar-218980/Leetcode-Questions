class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> freq;
        for(int x : nums) 
            freq[x] += 1;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        for(auto &p : freq) {
            minHeap.push({p.second, p.first}); 
            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};