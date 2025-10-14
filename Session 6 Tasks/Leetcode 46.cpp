class Solution {
public:
    void helperFunc(vector<int>& nums, int idx , vector<vector<int>> &ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i = idx ; i <n;i++){
            swap(nums[i],nums[idx]);
            helperFunc(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        helperFunc(nums, 0 , answer);
        return answer;
    }
};