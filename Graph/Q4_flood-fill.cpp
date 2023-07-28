#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color,int c) {
       if(i<0 or j<0 or i>=image.size() or j>=image[0].size() or image[i][j]!=c) return;
       image[i][j]=color;
       dfs(image,i-1,j,color,c);
       dfs(image,i+1,j,color,c);
       dfs(image,i,j+1,color,c);
       dfs(image,i,j-1,color,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int c=image[sr][sc];
          if(c!=color)
          dfs(image,sr,sc,color,c);
          return image;
    }
};