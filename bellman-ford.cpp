/*
PROGRAM FOR BELLMAN-FORD-ALGORITHMS
@author MOHIT GUPTA
Date:-24th september 2019
*/

#include<iostream>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 
//FUNCTION TO ADD AN EDGE TO GRAPH
void addedge(vector<pair<int,int>> adj[],int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
}
//FUNCTION FOR RELAXATION OF AN EDGE
void relax(int d[],int u,int v,int w){
    if(d[v] > d[u]+w){
        d[v] = d[u]+w;
    }
}
int main(){
    int n,i,j,u,v,w,choice;
    //TAKING INPUT FOR NUMBER OF VERTICES n=number of vertices
    cout<<"Please Enter the no. of vertices"<<endl;
    cin >> n;
   
    int d[n];
    vector<pair<int,int>> adj[n];
    while(1){
        cout <<"please enter the edges with weights"<<endl;
        cin >>u>>v>>w;
        addedge(adj,u,v,w);
        cout<<"Do you want to add more edges press 0"<<endl;
        cin>>choice;
        if(choice ==1)
            break;
    }
    d[0]=0;
    for(i=1;i<n;i++){
        d[i]=INT_MAX;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            for(auto itr=adj[j].begin();itr!=adj[j].end();itr++){
                relax(d,j,itr->first,itr->second);
            }
        }
    }
	for(i=0;i<n;i++){
		cout<<d[i]<<endl;
	}
}
