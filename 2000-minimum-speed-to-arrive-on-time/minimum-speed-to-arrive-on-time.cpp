class Solution {
public:
    bool check(vector<int>& dist, double hour, int speed){
        int n = dist.size();
        double time = 0;
        for(int i = 0; i<n-1; i++)
        {
            time += ceil((double) dist[i]/speed);
        }
        time += (double) dist[n-1]/speed;
        
        if(time<=hour)
            return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int ans = -1;

        while(low<=high){
        int mid = low+(high-low)/2;
        if(check(dist, hour, mid))
            {
                high = mid-1;
                ans = mid;
            }
        else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};