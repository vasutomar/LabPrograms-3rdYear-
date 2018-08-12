#include<bits/stdc++.h>
#define infinity INT_MAX

using namespace std;

//Function to initialize matrices
void init_mat(int mat[],int vis[],int cam[],int size) {
	for(int i=0;i<size;i++) {
		vis[i] = 0;
		mat[i] = infinity;
		cam[i] = -1;
	}
}

//Function to check if visited matrix is Empty
bool Filled(int mat[],int size) {
	for(int i=0;i<size;i++) {
		if(mat[i]==0)
			return false;
	}
	return true;
}

int main(void) {

	int vertices;
	int weight,from,to,edges;
	int i,j,mode;
	int source,immediate_next;

	cout<<"Enter the number of vertices in graph = ";
	cin>>vertices;
	cout<<"Enter edges in the graph = ";
	cin>>edges;

	int adjacency_matrix[vertices][vertices];
	int distance_matrix[vertices];
	int visited_matrix[vertices];
	int came_from[vertices];
	init_mat(distance_matrix,visited_matrix,came_from,vertices);

	//Initializing Adjacency matrix
	for(i=0;i<vertices;i++) {
		for(j=0;j<vertices;j++) {
			adjacency_matrix[i][j] = -1;
		}
	}

	cout<<"Enter if Directed(0) or undirected(1) = ";
	cin>>mode;
	mode = mode%2;

	//Building Adjacency matrix
	for(j=0;j<edges;j++) {
		cout<<"Enter nodes and edge weight : ";
		cin>>from;
		cin>>to;
		cin>>weight;
		adjacency_matrix[from-1][to-1] = weight;
		if(mode == 1)
			adjacency_matrix[to-1][from-1] = weight;
	}

	cout<<"Enter source = ";
	cin>>source;
	distance_matrix[source-1] = 0;
	visited_matrix[source-1] = 1;
	immediate_next = source-1;

	for(j=0;j<vertices;j++) {
		for(i=0;i<vertices;i++) {
			if(adjacency_matrix[immediate_next][i]!=-1) {
				if(adjacency_matrix[immediate_next][i]+distance_matrix[immediate_next]<distance_matrix[i]) {
					distance_matrix[i] = adjacency_matrix[immediate_next][i]+distance_matrix[immediate_next];
					came_from[i] = immediate_next;
				}
			}
		}
		int flag = 1;
		int min=0,pos=1;
		for(i=0;i<vertices;i++) {
			if(distance_matrix[i]<infinity && visited_matrix[i]!=1) {
				if(flag==1){
					min = distance_matrix[i];
					pos = i;
					flag = 0;
				}
				else {
					if(distance_matrix[i]<min) {
						min = distance_matrix[i];
						pos = i;
					}
				}
			}
		}
		visited_matrix[immediate_next] = 1;
		immediate_next = pos;
	}

	int dest;
	cout<<"Enter destination = ";
	cin>>dest;
	dest--;
	
	cout<<"Shortest Path = "<<distance_matrix[dest]<<endl;
	vector<int> a;
	i = came_from[dest];
	a.push_back(dest);
	while(i!=-1) {
		a.push_back(i);
		i = came_from[i];
	}

	cout<<"Path : ";
	for(i=a.size()-1;i>0;i--) 
		cout<<(char)(a[i]+65)<<"->";
	cout<<(char)(a[0]+65);
	cout<<endl;
	return 0;
}
