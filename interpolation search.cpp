#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
bool interpolation_search(int *arr,int s,int e,int key){
    if(s>e){
        return 0;
    }
    if(key<arr[s] or key>arr[e]){    //this is to handle mid<0 condition or mid>e cond
        return 0;
    }
    int mid=s+((double)(e-s)*(key-arr[s])/(arr[e]-arr[s]));
    // if(mid<0 or mid>e){
    //     return 0;
    // }
    if(key==arr[mid]){
        return 1;
    }
    else if(key>arr[mid]){
        return interpolation_search(arr,mid+1,e,key);
    }
    else{
        return interpolation_search(arr,s,mid-1,key);
    }

}
int main() 
{   
    c_p_c();
    int arr[]={1,2,6,4,8,9,10};
    sort(arr,arr+7);
    cout<<interpolation_search(arr,0,6,8);
    return 0; 
} 



