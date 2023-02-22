class Solution {
public:
    bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>freq;
        for(int i=0;i<nums.size();i++)
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]++;
        else
          mp[nums[i]]++;
        vector<pair<int,int>>ans;
        for(auto it:mp)
            ans.push_back({it.second,it.first});
        
        cout<<"the size is"<<ans.size();
          sort(ans.begin(), ans.end());
        reverse(ans.begin(),ans.end());
        
        int i=0;
      while(i<k)
      {
         freq.push_back(ans[i].second);
          i++;
      }
        return freq;
    }
};