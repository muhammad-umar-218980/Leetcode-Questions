
/**
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in non-decreasing order,
 * find the starting and ending position of a given target value.
 *
 * If target is not found in the array,
 * return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = startingPosition(nums, target);
        int last = endingPosition(nums, target);
        return {first, last};
    }

    int startingPosition(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int first = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                first = mid;
                end = mid - 1;
            }
        }
        return first;
    }
    
    int endingPosition(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int last = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                last = mid;
                start = mid + 1;
            }
        }
        return last;
    }
};