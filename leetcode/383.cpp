#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for (auto c : magazine)
        {
            hash[c]++;
        }
        for (auto c : ransomNote)
        {
            if (hash[c]<1)
                return false;
            hash[c]--;
        }
        return true;
    }
};

int main()
{
    Solution so;
    so.canConstruct("aa", "ab");
    return 0;
}