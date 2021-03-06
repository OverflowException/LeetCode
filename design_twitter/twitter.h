#include <iterator>
#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct Tweet
{

}
    
struct User
{
  int user_id;
  list<int> tweet_list;
  list<int> follow;
  User(int id) : user_id(id){}
};

class Twitter
{
 private:
  vector<User*> _users;
  void constructNewUser(int id);
  
 public:
  /**Initialize your data structure here. */
  Twitter();    
  /**Compose a new tweet.*/
  void postTweet(int userId, int tweetId);
    
  /**Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId);
  /**Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId);
  /**Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId);

  void listAllTwitter(int userId);
  void listAllFollow(int userId);
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
