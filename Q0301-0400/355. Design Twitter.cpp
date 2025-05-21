class Twitter {
public:
  int time;
  map<int, set<int>> follower;
  map<int, set<pair<int, int>>> tweets;
  Twitter() { time = 0; }

  void postTweet(int userId, int tweetId) {
    time++;
    tweets[userId].insert({time, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    set<pair<int, int>> s;
    for (int f : follower[userId]) {
      for (auto t : tweets[f]) {
        s.insert(t);
      }
    }
    for (auto t : tweets[userId]) {
      s.insert(t);
    }
    vector<int> ans;
    for (auto i = s.rbegin(); i != s.rend(); i++) {
      ans.push_back(i->second);
      if (ans.size() == 10)
        break;
    }
    return ans;
  }

  void follow(int followerId, int followeeId) {
    follower[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    follower[followerId].erase(followeeId);
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