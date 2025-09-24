class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            tickets[idx]--;
            time++;

            if (tickets[idx] > 0) {
                q.push(idx);
            } else if (idx == k) {
                return time;
            }
        }
        return time;
    }
};
