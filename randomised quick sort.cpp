#include<iostream>
#include<ctime>

using namespace std;
void shuffle(int arr[],int s,int e){
    
    //srand() is the random seed generator
    
    srand(time(NULL));
    
    //rand() function produces a random no between 0 and MAX_RANGE(read documentation)
    //rand()%x produces a random no between 0 and x-1(inclusive)
    
    for(int i=e;i>=s;i--){
        int random_index =rand()%(i+1);
        swap(arr[i],arr[random_index]);
    }
    
}
void quicksort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }

    //recursive case
    int i=s-1;
    int pivot=arr[e];
    for(int j=s;j<e;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    quicksort(arr,s,i);
    quicksort(arr,i+2,e);
}

int main() {

    int n;
    cin>>n;
    int arr[20];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shuffle(arr,0,n-1);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
