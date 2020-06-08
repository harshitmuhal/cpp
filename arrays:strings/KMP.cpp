#include <iostream>
#define MAX_N 100005
int LPS[MAX_N];
using namespace std;

//in reset table for each index we store the length of longest suffix till now
//in pattern which is also present as a prefix in pattern

//if you see preprocessing code the LPS[i]= length-1 because it is actually
//the last index of prefix matched with the suffix

void KMPpreprocess(string pat) {
	int i = 0, j = 1;
    LPS[0] = -1;
	while(i < pat.size()) {
		// Check for resetting
		while(j >= 0 and pat[i]!=pat[j]) {
			j = LPS[j];
		}
		i++;
		j++;
		LPS[i] = j;
	}
}

void KMPsearch(string str, string pat) {
	KMPpreprocess(pat);
	int i = 0, j = 0;
	while(i < str.size()) {
		while(j >= 0 and str[i] != pat[j]) {
			j = LPS[j];
		}
		i++;
		j++;
		if(j == pat.size()) {
			cout<<"Pattern is found at"<<i-j<<endl;
			j = LPS[j];
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	for(int i = 0; i < MAX_N; i++) {
		LPS[i] = -1;
	}
	string str, pat;
	cin>>str>>pat;
	KMPsearch(str, pat);
	return 0;
}
