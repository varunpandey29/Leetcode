class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt;
        int sum = 0;
        for(int i =0; i<gain.size(); i++)
        {
            sum+=gain[i];
            if(sum>0){
                alt.push_back(sum);
            }
            else{
                alt.push_back(0);
            }
        }
        return *max_element(alt.begin(), alt.end());
    }
};