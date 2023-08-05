#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Tc->(n^2)
// sc->(n^2)
 void buildSnakesLadderMap(vector<vector<int>>& board, unordered_map<int,int>& mp, int n) {
        int count = 1;
        bool flag = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(flag) {
                for(int j = 0; j < n; j++) {
                    if(board[i][j] != -1) mp[count] = board[i][j];
                    count++;
                }
            }
            else {
                for(int j = n - 1; j >= 0; j--) {
                    if(board[i][j] != -1) mp[count] = board[i][j];
                    count++;
                }
            }
            flag = !flag;
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
         int n = board.size();
        int maxVal = n * n;
        int step = 0;
        queue<int> q;
        unordered_map<int,int> mp;
        vector<int> vis(maxVal + 1, false);
        q.push(1);
        vis[1] = true;

        buildSnakesLadderMap(board, mp, n);

        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int num=q.front();
                q.pop();
                if(num==maxVal) return step;
                for(int k=1;k<=6;k++) {
                    int next=num+k;
                    if(next>maxVal) continue;
                    if(mp[next]) next=mp[next];
                    if(!vis[next])  {
                         vis[next]=true;
                         q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};