#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

//ת�����ܲ����ҵ�һ����ӵ���S��·
//dp[i]����s��ǰi���ַ��ܲ������ֵ�����ĵ���ƴ�գ�����ܾ�true���������false,
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        for (int i = 1; i < s.size()+1; i++)
        {
            for (int j = 0; j < wordDict.size(); j++)
            {
                if (wordDict[j].size() <= i)
                {
                    auto iter = s.begin() + i - wordDict[j].size();
                    int bk = 0;
                    for (auto iter2=wordDict[j].begin();iter2!=wordDict[j].end();iter++,iter2++)
                    {
                        if (*iter!=*iter2)
                        {
                            bk = 1;
                            break;
                        }
                    }
                    if(bk==0)
                    dp[i] = dp[i] || dp[i-wordDict[j].size()];
                }
            }
        }
        return dp[s.size()];
        
    }
};

//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        unordered_set<string> wordSet(wordDict.begin(),
//            wordDict.end());
//        vector<bool> dp(s.size() + 1, false);
//        dp[0] = true;
//        for (int i = 1; i <= s.size(); i++) { // ��������
//            for (int j = 0; j < i; j++) { // ������Ʒ
//                string word = s.substr(j, i - j); //substr(��ʼλ�ã���ȡ�ĸ���)
//                if (wordSet.find(word) != wordSet.end() && dp[j]) {
//                    dp[i] = true;
//                }
//            }
//        }
//        return dp[s.size()];
//    }
//};

int main()
{
    string s="catsandog";
    vector<string> wordDict{ "cats","dog","sand","and","cat" };
    Solution so;
    cout << so.wordBreak(s, wordDict) << endl;
}
