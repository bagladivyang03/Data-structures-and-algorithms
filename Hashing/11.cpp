// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int res = 0, temp = 1, cnt = 1;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                // cout<<nums[i]<<endl;
               while(s.find(nums[i]+temp)!=s.end()){
                   // cout<<nums[i]<<endl;
                   cnt += 1;
                   temp += 1;
               }
                res = max(res,cnt);
                temp = 1, cnt = 1;
                
            }
        }
        return res;
    }
};