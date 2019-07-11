
//better approach-----O(NKlog(K))
#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class mypair{
public:
    int data;
    int array_idx;  //to store data of array with its index
    int next_element;  //index of next element for which we have to check in array with index array_idx

    mypair(){

    }

    bool operator()(mypair a,mypair b){
        return a.data>b.data;
    }
};

int main(){
    int k,n;
    cin>>k>>n;
    int arr[k][n];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    priority_queue<mypair,vector<mypair>,mypair> h;
    int output[k*n];

    for(int i=0;i<k;i++){
        mypair p;
        p.data=arr[i][0];
        p.array_idx=i;
        p.next_element=1;
        h.push(p);
    }
    for(int cnt=0;cnt<n*k;cnt++){
        mypair p=h.top();
        output[cnt]=p.data;
        h.pop();
        if(p.next_element<n){
            p.data=arr[p.array_idx][p.next_element];
            p.next_element++;
            h.push(p);
        }
        else{
            p.data=INT_MAX;
            h.push(p);
        }
    }

    for(int i=0;i<n*k;i++){
        cout<<output[i]<<" ";
    }

    return 0;
}




//naive approach
//(NKlog(NK))

#include<iostream>
#include<queue>
using namespace std;

int main() {
	long int k,n;
	cin>>k>>n;
	long int d;
	priority_queue<int,vector<int>,greater<int>> h;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>d;
			h.push(d);
		}
	}

	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}	
	return 0;
}

