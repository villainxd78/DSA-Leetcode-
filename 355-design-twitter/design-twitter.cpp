class Twitter {
public:
   unordered_map<int,deque<pair<int,int>>>mp;
   unordered_map<int,unordered_set<int>>fmp;
   int t ;
    Twitter() {
        t=0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({t++,tweetId});
        if(mp[userId].size()>10){
            mp[userId].pop_front();
        }
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it:mp[userId]){
            pq.push(it);
        }
        for(auto it : fmp[userId]){
            for(auto num : mp[it]){
                pq.push(num);
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        fmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fmp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */