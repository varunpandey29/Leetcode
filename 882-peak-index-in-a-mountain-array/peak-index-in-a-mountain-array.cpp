class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i;
        for(i = 0; i<arr.size(); i++)
        {
            if(arr[i]>arr[i+1])
                break;
        }  
        return i; 
    }
};