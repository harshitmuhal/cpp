#include<iostream>
using namespace std;
void matmul(int n,int a[100][100],int ans[100][100]){
    int temp[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
            for(int k=0;k<n;k++){
                temp[i][j]+=ans[i][k]*a[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=temp[i][j];
        }
    }
}
void matrix_exponentiation(int n,int a[100][100],int x){
    int ans[100][100];
    for(int i=0;i<n;i++){          //initialising ans matrix with identity matrix because in firts step
        for(int j=0;j<n;j++){      //ans * a should be a ..compare it with code for a^x when a, x are int
            if(i==j)
                ans[i][j]=1;
            else
                ans[i][j]=0;
        }
    }
    while(x>0){
        if(x&1){
            matmul(n,a,ans);
        }
        matmul(n,a,a);
        x=x>>1;
    }
    cout<<"final matrix is\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;                 //dimensions of the matrix
    cin>>n;
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int x;                 // power on matrix ie A^x
    cin>>x;
    matrix_exponentiation(n,a,x);
    return 0;
}
