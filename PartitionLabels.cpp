// Link: https://leetcode.com/problems/partition-labels/description/
// Idea of the solution:
//    The main problem is to have the start and end of a letter to be in the same partition. The intermediate letters
//    are irrelevant and we can ignore them.
//    Then, the problem can be represented as a parentheses problem. The start of a letter is an opening parentheses,
//    and the end of a letter is a closing parentheses. The problem is how many valid parentheses partitions we can have.
//    For that, we can just keep a counter that increases when we see an opening parentheses and decreases when we see a closing one.
//    When the counter reaches zero, we have a valid partition.

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ans;
        int end[26], start[26];
        for (int i = 0; i < s.size(); ++i)
            end[s[i] - 'a'] = i;
        for (int i = s.size() - 1; i >= 0; --i)
            start[s[i] - 'a'] = i;

        int sum = 0, partitionStart = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (start[s[i] - 'a'] == i)
                sum += 1;
            if (end[s[i] - 'a'] == i)
                sum -= 1;
            if (sum == 0)
            {
                ans.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return ans;
    }
};