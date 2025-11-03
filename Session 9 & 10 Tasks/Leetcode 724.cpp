class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            total = total + nums[i];
        }

        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int rightSum = total - leftSum - num;
            if(leftSum == rightSum) {
                return i;
            }
            leftSum = leftSum + num;
        }

        return -1;
    }
};
