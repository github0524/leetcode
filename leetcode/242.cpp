#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        unordered_map<char, int> hash1;
        for (auto c : s)
        {
            if (hash.count(c)) hash[c]++;
            else {
                hash.insert(pair<char, int>(c, 1));
            }
        }
        for (auto c : t)
        {
            if (hash1.count(c)) hash1[c]++;
            else {
                hash1.insert(pair<char, int>(c, 1));
            }
        }
        if (hash.size() != hash1.size()) return false;
        for (auto c : s)
        {
            if (hash[c] != hash1[c]) return false;
        }
        return true;
    }
};

int main()
{
    Solution so;
    string s("anagram"), t("nagaram");
    cout << so.isAnagram(s, t) << endl;
}