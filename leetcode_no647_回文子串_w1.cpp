/* ------------------------------------------------------------------|
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

输入的字符串长度不会超过 1000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	二维dp法
*
*	执行用时：32 ms, 在所有 C++ 提交中击败了23.41%的用户
*	内存消耗：7.5 MB, 在所有 C++ 提交中击败了41.34%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n, 1));
    int res = n;;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
            res += f[i][j];
        }
    }
    return res;
}