class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            double distance = sqrt(x * x + y * y);

            pq.push({distance, i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (pq.size() > 0) {
            int idx = pq.top().second;
            pq.pop();
            result.push_back(points[idx]);
        }

        return result;
    }
};
