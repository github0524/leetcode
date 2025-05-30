//·ÖÅä±ý¸É
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assign_cookies(vector<int> g, vector<int> s)
{
	int left = 0, right = 0, count = 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	for (int i = 0; i < g.size(); i++)
	{
		for (; right < s.size(); right++)
		{
			if (g[i]<=s[right])
			{
				count++;
				right++;
				break;
			}
		}
	}
	return count;

}

int main()
{
	vector<int> g = { 1,2 };
	vector<int> s = { 1,2,3 };
	cout << assign_cookies(g, s) << endl;

}