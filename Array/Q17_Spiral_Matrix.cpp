#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>spiral;
        int row=matrix.size();
        int col=matrix[0].size();
        int k=1;
        bool ok=true;
        int i=0,j=0;
        while(k<=(row*col)) {
            if(ok) {
                while(j<col and matrix[i][j]!=-101) {
                    spiral.push_back(matrix[i][j]);
                    matrix[i][j]=-101;
                    j++,k++;
                }
                i++,j--;
                while(i<row and matrix[i][j]!=-101) {
                     spiral.push_back(matrix[i][j]);
                     matrix[i][j]=-101;
                     i++,k++;
                }
                i--,j--;
                ok=!ok;
            }
            else{
                while(j>=0 and matrix[i][j]!=-101) {
                    spiral.push_back(matrix[i][j]);
                    matrix[i][j]=-101;
                    j--,k++;
                }
                j++,i--;
                while(i>=0 and matrix[i][j]!=-101) { 
                   spiral.push_back(matrix[i][j]);
                   matrix[i][j]=-101;
                   i--,k++;
                }
                i++,j++;
                ok=!ok;
            }
        }
        return spiral;
    }
};