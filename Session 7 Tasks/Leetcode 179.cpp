class Solution {
public:
    static bool compare(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int i = 0; i < nums.size(); i++)  arr.push_back(to_string(nums[i]));

        sort(arr.begin(), arr.end(), compare);
        
        if (arr[0] == "0") return "0";

        string result = "";
        for (int i = 0; i < arr.size(); i++) result = result + arr[i];

        return result;
    }
};
