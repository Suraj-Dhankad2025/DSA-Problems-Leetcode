class Twitter {
    int time;
    unordered_map<int, set<int>>following;
    unordered_map<int, vector<pair<int, int>>>tweets;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>news;
        priority_queue<pair<int, int>>pq;
        for(auto i:tweets[userId]){
            pq.push(i);
        }
        for(int follower:following[userId]){
            for(auto i:tweets[follower]){
                pq.push(i);
            }
        }
        while(!pq.empty() && news.size()<10){
            news.push_back(pq.top().second);
            pq.pop();
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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