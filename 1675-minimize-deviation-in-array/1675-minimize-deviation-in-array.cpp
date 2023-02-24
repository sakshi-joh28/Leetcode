class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini=INT_MAX,diff=INT_MAX;
        int temp_max;
        priority_queue<int>pq;
        for(auto i:nums)
        {
            if(i%2!=0)
                i=i*2;
            mini=min(mini,i);
            pq.push(i);
        }
        while(pq.top()%2==0)
        {
             temp_max=pq.top();
            pq.pop();
            diff=min(diff,temp_max-mini);
            pq.push(temp_max/2);
            mini=min(mini,temp_max/2);
        }
        return min(diff,pq.top()-mini);
        
    }
};