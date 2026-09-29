class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        while(i<n-1 && nums[i+1]>=nums[i])i++;
        if(i==n-1)return 0;
        while(j>0 && nums[j-1]<=nums[j])j--;

        int minval = nums[i];
        int maxval = nums[i];

        for(int k=i;k<=j;k++){
            minval=min(minval,nums[k]);
            maxval=max(maxval,nums[k]);
        }
        while(i>0 && nums[i-1]>minval)i--;
        while(j<n-1 && nums[j+1]<maxval)j++;
        return j-i+1;
        
    }
};