
解法1：
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int snowBallSize = 0;
        
        for (int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                snowBallSize++;
            }
            else if (snowBallSize != 0) {
                nums[i-snowBallSize] = nums[i];
                nums[i] = 0;
            }
            
        }
    }
};


解法2：双指针一次遍历
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }
    }
};


解法3：双指针两次遍历-最易理解
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //初始化双指针
        //j指针用于找中间0
        int j = 0;
        for (int i=0;i<nums.size();i++) {
            /*如果两个指针指向元素均不为0，整体右移一位*/
            if (nums[j] != 0 && nums[i] != 0) {
                j++;
            }
            /*如果j指针找到了中间点0，i没有找到中间点0右侧非0元素*/
            else if (nums[j] == 0 && nums[i] == 0) {
                continue;
            }
            /*如果j指针找到了中间点0，i找到了中间点右侧非0元素*/
            else if (nums[j] == 0 && nums[i] != 0) {
               int tmp = nums[i];
               nums[i] = nums[j];
               nums[j] = tmp;
               j++;
            }
        }    
    }
};



