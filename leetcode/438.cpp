#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

//�ҵ��ַ�����������ĸ��λ��

//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        unordered_multiset<char> hash;
//        unordered_multiset<char> hash2;
//        
//        for (auto c : p)
//        {
//            hash.insert(c);
//        }
//        vector<char> win;
//
//        
//        vector<int> ret;
//        int pass = 1;
//        int size = p.size();
//        for (int i = 0; i < s.length();i++ )
//        {
//            pass = 1;
//            win.push_back(s[i]);
//            if (win.size()== size)
//            {
//                hash2 = hash;
//                for (int j = 0; j < size; j++)
//                {
//                    unordered_multiset<char>::iterator it;
//                    if ( (it = hash2.find(win[j]))==hash2.end())
//                    {
//                        pass = 0;
//                        break;
//                    }
//                    
//                    hash2.erase(it);
//                }
//                if (pass == 1)
//                {
//                    //ȫͨ
//                    ret.push_back(i - size+1);
//                }
//                win.erase(win.begin());
//            }
//        }
//        return ret;
//    }
//};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);
        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;
        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }
        //���Ծ�����ɾ��һ��Ԫ�أ�������һ��Ԫ�ص��������ڣ�������ô��ȫ���Ĳ�ͬ����һ��int��ʾ�ж��ٸ����ڲ���
        for (int i = 0; i < sLen - pLen; ++i) {
            if (count[s[i] - 'a'] == 1) {  // ��������ĸ s[i] ���������ַ��� p �е������Ӳ�ͬ�����ͬ
                --differ;
            }
            else if (count[s[i] - 'a'] == 0) {  // ��������ĸ s[i] ���������ַ��� p �е���������ͬ��ò�ͬ
                ++differ;
            }
            --count[s[i] - 'a'];

            if (count[s[i + pLen] - 'a'] == -1) {  // ��������ĸ s[i+pLen] ���������ַ��� p �е������Ӳ�ͬ�����ͬ
                --differ;
            }
            else if (count[s[i + pLen] - 'a'] == 0) {  // ��������ĸ s[i+pLen] ���������ַ��� p �е���������ͬ��ò�ͬ
                ++differ;
            }
            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

int main()
{
    Solution so;
    auto ret = so.findAnagrams("baa", "aa");
    for (auto i : ret)
    {
        cout << i << endl;
    }
    return 0;
}