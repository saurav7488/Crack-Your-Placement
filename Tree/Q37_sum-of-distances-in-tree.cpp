class Solution {
public:
    vector<int> countnode,ans;
    vector<vector<int>> g;
    void dfs1(int s,int p){
        for(auto &i: g[s]){
            if(i==p)continue;
            dfs1(i,s);
            countnode[s] += countnode[i];
            ans[s] += ans[i]+countnode[i];
        }
        countnode[s]++;
    }
    void dfs2(int s,int p){
        for(auto &i: g[s]){
            if(i==p)continue;
            ans[i] = ans[s]-countnode[i]+ans.size()-countnode[i];
            dfs2(i,s);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans.resize(n,0);
        countnode.resize(n,0);
        g.resize(n);
        for(auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }
};