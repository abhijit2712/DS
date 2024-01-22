#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> parent,rank,size;
    
    //constructor of class
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    //find parent method -> this method uses the 
    //backtraking approach

    int findUPar(int node){
        //if got the ultimate parent node
        //then and only then return 
        if(node == parent[node]) return node;


        //if dont get any node got ultimate 
        //parent then find parent node
        //until don't find the ultimate parent node
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        //u and v are two node to attach each other
        

        //find the ultimate parent for both the node which you want to connect
        int up_of_u = findUPar(u);
        int up_of_v = findUPar(v);


        //if both have same parent then no need to connect them again
        if(up_of_u == up_of_v) return;


        //if rank of u is less then assing parent of v to u
        if(rank[up_of_u] < rank[up_of_v]){
            parent[up_of_u] = up_of_v;
        }
        else if(rank[up_of_v] <= rank[up_of_v]){
            //if if rank of v is less then assing parent of u to v
            parent[up_of_v] = up_of_u; 
        }else{
            parent[up_of_v] = up_of_u;
			rank[up_of_u]++;
        }
    }

    void unionBySize(int u,int v){
         //u and v are two node to attach each other
        

        //find the ultimate parent for both the node which you want to connect
        int up_of_u = findUPar(u);
        int up_of_v = findUPar(v);

        //if same 
        if(up_of_u == up_of_v) return;

        if(size[up_of_u] < size[up_of_v]){
            parent[up_of_u] = up_of_v;
            size[up_of_v] += size[up_of_u];
        }
        else{
            parent[up_of_v] = up_of_u;
            size[up_of_u] += size[up_of_v];
        }
        
    }
};

int main(){
    DisjointSet ds(100);

	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);

	if(ds.findUPar(3) == ds.findUPar(7)){
		cout << "same\n" << endl;
	}
	else{
		cout << "Not same" << endl;
	}

	ds.unionBySize(3,7);

	if(ds.findUPar(3) == ds.findUPar(7)){
		cout << "same\n" << endl;
	}
	else{
		cout << "Not same" << endl;
	}

	   for(int i=0;i<7;i++){  
		cout << ds.size[ds.findUPar(i)] << "\t" << i  <<"\t" << endl;
    }


		// string s;
		// cin >> s;
		// cout << s << endl;
		// int n;
		// cin >> n;
		// cout << n <<endl; 

 return 0;
}
