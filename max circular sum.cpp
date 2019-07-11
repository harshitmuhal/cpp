#include<iostream>
using namespace std;
int kadane(int a[], int n){  
int max = 0, cmax = 0;  
int i;  
for (i=0;i<n;i++)  
{  
	cmax=cmax+a[i];  
	if (cmax<0)  
		cmax=0;  
	if (max<cmax)  
		max=cmax;  
}  
return max;  
}  
 
int maxCircularSum(int a[], int n)  
{  
    int max_kadane = kadane(a, n);  
    int sum = 0; 
    for(int i = 0; i < n; i++)  
    {  sum += a[i];   
       a[i] = -a[i];  
    }  
    sum+=kadane(a, n);  
    return max(sum,max_kadane);  
}  
   

int main() {

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<maxCircularSum(arr,n)<<endl;
	}
	return 0;
}