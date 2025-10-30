// Link: https://leetcode.com/problems/jump-game-ii/
// Idea of the solution:
//.   The naive solution is to just iterate through the positions at reach,
//.   but we'd like to have an O(n) solution and that give's an O(n^2). How can we just iterate through those
//.   that we really need? OR how to not iterate through any and just "know"? Or how to just iterate once through the loop.
//.   The main idea is that if the minimum jumps from some index x is less than the minimum jumps from a later
//.   index y, then no other index will ever want to check the index y's solution, since x's solution is better and closer.
//.   That gives the idea of a monotonic stack. We can keep a stack of decreasing answers, and for a given index,
//.   eliminate the top solution as long as we can reach the next index, which would make my answer better and closer for
//.   next indexes. This has a classic runtime of O(N) and at most O(N) in space as well.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        stack<pii> ans;
        ans.push(pii(nums.size() - 1, 0));

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            // initialize answer with the previous one
            // while stack is at least size 2, and I can get to the previous
            // delete the top and update my answer
            int current_ans = 1 + ans.top().second;
            bool stop = false;
            while (ans.size() >= 2 && !stop)
            {
                pii tmp = ans.top();
                ans.pop();
                if (i + nums[i] >= ans.top().first)
                {
                    current_ans = 1 + ans.top().second;
                }
                else
                {
                    stop = true;
                    ans.push(tmp);
                }
            }
            ans.push(pii(i, current_ans));
        }
        return ans.top().second;
    }
};