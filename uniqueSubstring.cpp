#include <bits/stdc++.h>

using namespace std;

int decimal(string str){ 
    long long sum=0, i=str.size()-1, j=0;
    while(i>=0){
        sum+=((str[i]-'0')*(pow(2, j))%1000000007)%1000000007;
        j++;
        i--;
    }
    return sum%1000000007;
}
int main() {
	//code
	int t, k;
	cin>>t;
	while(t--){
	    map<string, int>m;
	    string str, sol="";
	    cin>>str>>k;
	    int len = str.size(), j=0, sum=0;
	    if(len/k==0) return -1;
	    else{
	        for(int i=0; i<len/k; i++){
	            for(; j<k*(i+1); j++){
	                sol+=str[j];
	            }
	            m[sol]=1;
	            sol="";
	        }
	    }
	    for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++){
	        sum+=decimal(it->first);
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}
