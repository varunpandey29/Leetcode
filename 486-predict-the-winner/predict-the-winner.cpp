class Solution {
public:
    int maxScore(vector<int>& nums, int i, int j, int chance){
        if(i>j)
            return 0;
        if(chance==0){
            return max(nums[i]+maxScore(nums, i+1, j, 1), nums[j]+maxScore(nums, i, j-1, 1));
        }
        else
            return min(maxScore(nums, i+1, j, 0), maxScore(nums,i, j-1, 0));
    }
    bool PredictTheWinner(vector<int>& nums) {
        long long two = 0;
        long long total = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            total = (long long) nums[i] + total; 
        }
        long long one = (long long) maxScore(nums, 0, n-1, 0);
        two = total-one;
        
        return(one>=two);
    }
};