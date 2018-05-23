// 判断有向图是否有环
// 依赖关系，用拓扑排序
// class Solution
// {
//   public:
//     bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
//     {
//         if (prerequisites.empty())
//             return true;

//         unordered_map<int, int> m;
//         stack<int> s;
//         vector<int> cmp;
//         int curr = 0, found = 0;

//         for (auto i : prerequisites)
//         {
//             m[i.first] = 0;
//             m[i.second] = 0;
//         }

//         s.push(prerequisites[0].first);
//         m[prerequisites[0].first] = 1;

//         while (!m.empty())
//         {
//             if (!s.empty())
//             {
//                 curr = s.top();
//                 cmp.push_back(curr);
//                 found = 0;
//                 for (auto i : prerequisites)
//                 {
//                     // i是某条边，从i.first指向i.second
//                     auto fnd = m.find(i.second); // 迭代器，若无则指向m.end()
//                     if (curr == i.first && fnd != m.end())
//                     {
//                         if (fnd->second > 0)
//                             return false;
//                         s.push(i.second);
//                         found = 1;
//                         m[i.second]++;
//                         break;
//                     }
//                 }
//                 if (!found)
//                 {
//                     m.erase(curr);
//                     s.pop();
//                 }
//             }
//             else
//                 s.push(m.begin()->first);
//         }

//         return true;
//     }
// };

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <utility>

using namespace std;
// 新学的拓扑排序
class Solution
{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        if (prerequisites.empty())
            return true;

        stack<int> s;                        // 用于存储入度为0的顶点
        vector<int> inDegree(numCourses, 0); // 用于存储各点的入度
        unordered_set<int> visited;          // 用于存储之前已访问过的结点

        // 统计各个顶点的入度
        countInDegree(inDegree, prerequisites);

        // 建立入度为0的栈
        push(s, inDegree, visited);

        while (!s.empty())
        {
            int cur = s.top();
            cout << "当前输出顶点" << cur << endl;
            s.pop();
            visited.insert(cur); // 设置该点已访问
            // 删除顶点cur发出的所有边
            bool alreadyDel = delEdgeSourcedBy(cur, prerequisites, inDegree);
            // 将此时入度为0的顶点再次入栈，但之前入栈过的不再入栈
            if (alreadyDel)
                push(s, inDegree, visited);
        }

        cout << "loop ending..." << endl;
        if (visited.size() < numCourses)
            return false;

        return true;
    }

    // 计算各个顶点的入度
    void countInDegree(vector<int> &inDegree, vector<pair<int, int>> &edges)
    {
        for (auto edge : edges)
            // edge.first是边的终点，edge.second是边的起点
            inDegree[edge.first]++; // 只统计入度，那只对于边的终点而言
    }

    void push(stack<int> &s, vector<int> &inDegree, unordered_set<int> &visited)
    {
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0 && visited.find(i) == visited.end()) // 入度为0，且之前未访问过
                s.push(i);
    }

    bool delEdgeSourcedBy(int src, vector<pair<int, int>> &edges, vector<int> &inDegree)
    {
        bool flag = false;
        vector<pair<int, int>> copy;

        for (int i = 0; i < edges.size(); i++)
        {
            // 删除所有以顶点src为起点的边
            // src应该为edge.second;
            cout << "当前边为" << edges[i].second << "->" << edges[i].first << endl;
            if (edges[i].second == src)
            {
                inDegree[edges[i].first]--; // 边的终点的入度减1
                flag = true;
            }
            else
                copy.push_back(edges[i]);
        }
        edges = copy;
        return flag;
    }
};

int main()
{
    // int numCourses = 2;
    // vector<pair<int, int>> prerequisites;
    // prerequisites.push_back(make_pair(1, 0));

    // int numCourses = 3;
    // vector<pair<int, int>> prerequisites;
    // prerequisites.push_back(make_pair(1, 0));
    // prerequisites.push_back(make_pair(2, 0));

    int numCourses = 2;
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(0, 1));

    Solution s;
    if (s.canFinish(numCourses, prerequisites))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}