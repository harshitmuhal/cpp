#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a,string b){
string new1=a.append(b);
string new2=b.append(a);
    return new1>new2;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> v;
        while(n--){
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),compare);
        for(auto it:v){
            cout<<it;
        }
        cout<<endl;
    }
    
    return 0;
}

/*important sample test case

8
4
54 546 548 60
8
1 34 3 98 9 76 45 4
8
1430 344 4169 2627 2031 4234 3023 665
8
1044 2522 2612 4987 2813 1223 4853 15
8
3610 3627 749 3678 3952 2039 301 951
8
2492 119 3434 1111 2396 617 184 928
8
3449 4623 1043 2251 1143 4535 2860 3996
8
2393 2302 4477 1596 2976 1468 3569 3153

output-
6054854654
998764543431
665423441693443023262720311430
498748532813261225221512231044
95174939523678362736103012039
9286173434249223961841191111
46234535399634492860225111431043
44773569315329762393230215961468
*/