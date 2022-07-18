/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;

void dfs(UndirectedGraphNode* node){
    ::map[node] = new UndirectedGraphNode(node->label);
    for(auto v: node->neighbors){
        if(::map.find(v) == ::map.end()){
            dfs(v);
        }
        ::map[node]->neighbors.push_back(::map[v]);
    }
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    ::map.clear();

    dfs(node);
    return ::map[node];
}