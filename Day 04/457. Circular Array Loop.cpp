class Solution {
public:

    int getNext(vector<int>& nums, int i) {
        int n = nums.size();

        int next = (i + nums[i]) % n;

        if(next < 0)
            next += n;

        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int slow = i;
            int fast = i;

            while(true) {

                int nextslow = getNext(nums, slow);

                int nextfast1 = getNext(nums, fast);
                int nextfast2 = getNext(nums, nextfast1);

                if((nums[slow] > 0) != (nums[nextslow] > 0) ||
                   (nums[fast] > 0) != (nums[nextfast1] > 0))
                    break;

                if(slow == nextslow || nextfast1 == nextfast2)
                    break;

                slow = nextslow;
                fast = nextfast2;

                if(slow == fast)
                    return true;
            }
        }

        return false;
    }
};