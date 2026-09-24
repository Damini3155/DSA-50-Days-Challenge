class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int l=0;
        int r=n-1;
        int i=n-1;

        while(l<=r){
            int a = nums[l]*nums[l];
            int b = nums[r]*nums[r];

            if(a>b){
                result[i]=a;
                l++;
            }else{
                result[i]=b;
                r--;
            }
            i--;
        }
        return result;
    }
};