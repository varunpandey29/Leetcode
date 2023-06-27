class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(int i = 0; i<operations.size(); i++)
        {
            if(operations[i]=="++X")
                ++ans;
            else if(operations[i]=="X++")
                ans++;
            else if(operations[i]=="X--")
                ans--;
            else if(operations[i]=="--X")
                --ans;

        }
        return ans;
    }
};