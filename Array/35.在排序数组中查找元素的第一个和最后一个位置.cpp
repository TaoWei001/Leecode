//1.该题还是一个二分查找法，只不过需要分别查找左右两个数据，在边界判断上需要想清楚

class Solution {
public:
    int FindFirstPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }

        if (nums[left] != target) {
            return -1;
        }else {
            return left;
        }
    
    }

int FindLastPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                left = mid;
            } else if (nums[mid] < target) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return {-1,-1};

        int first_position = FindFirstPosition(nums, target);
        if (first_position == -1) {
            return {-1, -1};
        }
        int right_position = FindLastPosition(nums, target);
        return {first_position, right_position};
    }
};


