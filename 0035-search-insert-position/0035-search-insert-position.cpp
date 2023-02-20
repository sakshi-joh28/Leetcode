class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        int mid;
        while(i<=j)
        {
           mid=i+(j-i)/2;
            if(nums[mid]==target)
            {
                return mid;
                break;
            }
            if(nums[mid]<target)
                i=mid+1;
            else
                j=mid-1;
        }
        if(nums[mid]>target)
            return mid;
        return mid+1;
    }
};