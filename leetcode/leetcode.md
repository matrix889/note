[TOC]

###字符串

#### Reverse Words in a String

1. 题目大意:
&emsp;&emsp;给出一个字符串,取出其中单词间多余的空格,并且将该字符串中的单词倒序输出.

2. 思路:
&emsp;&emsp;首先去除多余的空格,考虑将每个单词尽量向前移动.用一个变量lastSpace标记上一段空格的起始位置,用wordStart标记下当前单词的起始位置,找到单词的末尾之后,将单词前移即可.找到该单词之后,顺便将这个单词做翻转.扫描一遍单词之后,将整个单词做翻转,即可完成要求.

3. Code:
```cpp
class Solution {
public:
    void reverseWords(string &s) {
        int lastSpace = 0, wordStart = 0, pos = 0;

        while (pos < s.length()){
            if (s[pos] == ' '){
                while (s[pos] == ' ' && pos < s.length()) ++pos;
            }

            if (pos < s.length() && s[pos] != ' '){
                wordStart = pos;
                while (s[pos] != ' ' && pos < s.length()) ++pos;
                reverseWord(wordStart, pos, s);

                if (lastSpace != 0) ++lastSpace;
                removeSpace(lastSpace, wordStart, pos, s);
            }

        }
        s.erase(lastSpace, s.length() - lastSpace);

        reverseWord(0, s.length(), s);
    }

    void reverseWord(const int &wordStart, const int &wordEnd, string &s){
        for (int i = wordStart; i < (wordStart + wordEnd) / 2; ++i)
            swap(s[i], s[wordEnd - (i - wordStart) - 1]);
    }
    void removeSpace(int &lastSpace, const int &wordStart, const int &i, string &s){
        for (int k = wordStart; k < i; ++k){
            swap(s[lastSpace], s[k]);
            ++lastSpace;
        }
    }
};
```

4. Link:
[Reverse Word](https://leetcode.com/problems/reverse-words-in-a-string/)

### 动态规划

#### Pascal Triangle

1. 题目大意:
&emsp;&emsp;返回一个大小为n行的杨辉三角.

2. 思路:
&emsp;&emsp;有一个小小的优化,就是只需要用一个vector<int> q保存前一行的数据,然后从后向前更新,q[j] += q[j-1], q.push_back(1),然后将q加入到结果集中即可.

3. 代码:

```cpp
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows <= 0) return vector<vector<int> >();

        vector<int> level;
        vector<vector<int> > ret;
        for (int i = 1; i <= numRows; ++i){
            int sz = (int)level.size();

            for (int j = sz - 1; j >= 1; --j)
                level[j] += level[j-1];
            level.push_back(1);
            ret.push_back(level);
        }
        return ret;
    }
};
```

4. Link:
[pascal_triangle](https://leetcode.com/problems/pascals-triangle/)

#### Pascal Triangle2

1. 题目大意:
&emsp;&emsp;输出杨辉三角的第k行.

2. 思路:
&emsp;&emsp;思路同上一题.

3. 代码:
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> q;
        q.push_back(1);
        for (int i = 1; i <= rowIndex; ++i){
            size_t sz = q.size();

            for (size_t j = sz - 1; j; --j)
                q[j] += q[j-1];
            q.push_back(1);
        }
        return q;
    }
};
```

4. Link:
[pascal_triangle2](http://leetcode.com/problems/pascals-triangle-ii/)

### 二叉树

#### Binary Tree Zigzag Level Order Traversal

1. 题目大意:

&emsp;&emsp;输入一个二叉树,返回它的Z字形层次遍历.

2. 思路:

&emsp;&emsp;直接BFS破之,可以用两个队列,一个队列保存上一层的节点,另一个队列保存当前层的节点.将上一层的节点全部拓展出来之后,将第二个队列的全部值赋值给第一个队列即可.

3. 代码:
```cpp
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int> >();
        vector<int> level;
        vector<vector<int> > ret;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        bool flag = false;

        while (!q1.empty()){
            while (!q1.empty()){
                TreeNode * u = q1.front();
                q1.pop();
                level.push_back(u->val);

                if (u->left != NULL)
                    q2.push(u->left);
                if (u->right != NULL)
                    q2.push(u->right);
            }

            q1 = q2;
            while (!q2.empty()) q2.pop();

            if (flag){
                size_t sz = level.size();
                for (size_t i = 0; i < sz/2; ++i)
                    swap(level[i], level[sz - 1 - i]);
            }
            flag = !flag;
            ret.push_back(level);
            level.clear();
        }
        return ret;
    }
};
```

4. Link:
[Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
