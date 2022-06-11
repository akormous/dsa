#include<bits/stdc++.h>
using namespace std;

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
#define SIZE 2
struct Node {
    Node* children[SIZE];
    bool isEOW;
    Node() {
        for(int i = 0; i < SIZE; i++)   children[i] = nullptr;
        isEOW = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int row[], int n) {
        Node* crawler = root;
        for(int i = 0; i < n; i++) {
            if(crawler->children[ row[i] ] == nullptr)
                crawler->children[ row[i] ] = new Node();
            crawler = crawler->children[ row[i] ];
        }
        crawler->isEOW = true;
    }
    
    bool search(int row[], int n) {
        Node* crawler = root;
        for(int i = 0; i < n; i++) {
            if(crawler->children[ row[i] ] == nullptr)
                return false;
            crawler = crawler->children[ row[i] ];
        }
        return crawler->isEOW ? true : false;
    }
};
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    // create a trie from the given rows,
    // before inserting a row, check if it already exists,
    // if it doesn't then insert it in trie and result vector
    // so in this way result will contain only unique rows
    Trie* t = new Trie();
    vector<vector<int>> result;
    for(int i = 0; i < row; i++) {
        if(!t->search(M[i], col)) {
            t->insert(M[i], col);
            vector<int> temp(M[i], M[i] + col);
            result.push_back(temp);
        }
    }
    return result;
}