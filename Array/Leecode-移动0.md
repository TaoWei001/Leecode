# Leecode-移动0

主推两种解法：

## 1.双指针-两次遍历

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++:
            }
        }
        
        for(int i=j;i<nums.size();i++) {
            nums[i] = 0;
        }
    }
};
```

## 2.双指针-一次遍历

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++:
            }
        }
    }
};
```

## 3.滚雪球解法

```c++
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
```

