#include<bits/stdc++.h>
using namespace std;
struct Node {
     Node*links[26];
     int prefix_count=0;
     bool flag=false;

     bool containskey(char ch) {
          return links[ch-'a']!=NULL;
     }

     Node*get(char ch) {
           return links[ch-'a'];
     } 
  
     void put (char ch,Node*node) {
            links[ch-'a']=node;
     }

     void isSetEnd() {
          flag=true;
     }

     bool isEnd() {
          return flag;
     }
}; 
class Trie {
     public:
     Node*root;
     Trie() {
         root=new Node();
         root->prefix_count=0;
     }
     void insert(string&word) {
         Node*node=root;
         for(int i=0;i<word.size();i++) {
               if(!node->containskey(word[i])) {
                    node->put(word[i],new Node());
                    node->prefix_count++;
               }
               node=node->get(word[i]);
         }
         node->isSetEnd();
     }
     void len(string&word,string&ans) {
           Node*node=root;
           for(int i=0;i<word.size();i++) {
                if(node->prefix_count==1) {
                     ans.push_back(word[i]);
                     node=node->get(word[i]);
                }
                else break;

                if(node->isEnd()) break;
           }
     }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         Trie trie;
         for(auto it:strs) {
              if(it=="") return "";
              trie.insert(it);
         }
         string s=strs[0];
         string ans="";
         trie.len(s,ans);
         return ans;

    }
};

// TC->O(N*M)
// SC->O(N*M)











