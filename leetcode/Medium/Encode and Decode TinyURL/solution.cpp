class Solution {
public:

  unordered_map<int,string> mp;
  int key = 0;
    
  string encode(string longUrl) {
    mp[key++] = longUrl;
    return to_string(key-1);
  }

  string decode(string shortUrl) {
    return mp[stoi(shortUrl)];
  }
};
