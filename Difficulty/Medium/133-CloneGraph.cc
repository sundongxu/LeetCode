/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// DFS
class Solution
{
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == nullptr)
            return nullptr;

        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copy;
        clone(node, copy);
        return copy[node];
    }

  private:
    // DFS
    static UndirectedGraphNode *clone(const UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> &copy)
    {
        // a copy already exists
        if (copy.find(node) != copy.end())
            return copy[node];

        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label); // 拷贝当前结点
        copy[node] = new_node;
        for (auto nbr : node->neighbors) // 拷贝当前结点的邻居关系，未拷贝邻居结点要先拷贝该邻居结点，才能拷贝邻居关系
            new_node->neighbors.push_back(clone(nbr, copy));

        return new_node;
    }
};

class Solution
{
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == nullptr)
            return nullptr;

        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copy;

        // 队列里面的每个结点都已经copy了自身（空间和关键字）， 但是其邻居数组还未拷贝
        queue<const UndirectedGraphNode *> q;
        copy[node] = new UndirectedGraphNode(node->label);
        q.push(node); // 把原始节点入队，用来找到各个邻居节点

        while (!q.empty())
        {
            const UndirectedGraphNode *cur = q.front();
            q.pop();
            for (auto nbr : cur->neighbors)
            {
                if (copy.find(nbr) != copy.end())              // cur的相邻结点已在之前就已经拷贝至map中
                    copy[cur]->neighbors.push_back(copy[nbr]); // 不用拷贝结点，只用拷贝邻居关系，cur的邻居是nbr，则copy[cur]的邻居为copy[nbr]
                else                                           // cur的相邻结点未在map中，不仅要拷贝邻居关系，还要先将该结点拷贝至copy中
                {
                    copy[nbr] = new UndirectedGraphNode(nbr->label);
                    copy[cur]->neighbors.push_back(copy[nbr]);
                    q.push(nbr);
                }
            }
        }

        return copy[node];
    }
};