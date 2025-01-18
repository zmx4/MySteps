#include <iostream>
using namespace std;

int main(){
		int t;cin>>t;
		while(t--){
			int n;cin>>n;
			int counter=0;
			while(n%3==0){
				if(n%6==0){
					n/=6;
					counter++;
				}
				else{
					n*=2;
					counter++;
				}
			}
			if(n==1){
				cout<<counter<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
	return 0;
}