#include <iostream>
using namespace std;
#include <bits/stdc++.h>


// Given number of vertices and its adjancy list, find the topological sort of the graph.
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
void BFS(vector<int> adj[], queue<int> q , vector<int> &degree, vector<int> &order){
    // vector<int> order;
    
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int a : adj[x]){
                degree[a]--;
                if(degree[a]==0){
                    q.push(a);
                    order.push_back(a);
                }
            }
        }
        // return order;
    }
    	
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> degree(V,0);
        // int j=0;
        vector<int> order;
        for(int j=0;j<V;j++){
            for(int i=0;i<adj[j].size();i++){
                degree[adj[j][i]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<degree.size();i++){
            if(degree[i]==0){
                q.push(i);
                order.push_back(i);
                
            }
        }
        
        BFS(adj,q,degree, order);
    
        return order;
    }
}; 

int main(){

}