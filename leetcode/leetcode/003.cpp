#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1) {
			return s.length();
		}
		int i, j;
		i = 0; j = i;
		string maxSubStr = "";
		int maxLen = 0;
		map<string, int> tmpMap;
		tmpMap.clear();
		while ((string::size_type)j < s.length()) {
			string curChar = s.substr(j, 1);
			if (tmpMap.end() == tmpMap.find(curChar)) {
				tmpMap[curChar] = j;
			}
			else if (tmpMap[curChar] >= i) {
				if ((j - i) >= maxLen) {
					maxSubStr = s.substr(i, j - i);
					maxLen = j - i;
				}

				i = tmpMap[curChar] + 1;
				tmpMap[curChar] = j;
			}
			else {
				tmpMap[curChar] = j;
			}
			j++;
		}
		if ((j - i) >= maxLen) {
			maxSubStr = s.substr(i, j - i);
			maxLen = j - i;
		}
		return maxLen;
	}
};

//int main()
//{
//	string testStr = "abcabcbb";
//	Solution sln;
//	//cout << sln.lengthOfLongestSubstring("abcabcbb") << endl;
//	cout << sln.lengthOfLongestSubstring("qwnfenpglqdq") << endl;
//	cout << sln.lengthOfLongestSubstring(testStr) << endl;
//	return 0;
//}

