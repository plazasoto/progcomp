#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<string,string> > users;
	pair<string,string> temp;
	for(int i=0; i<n; ++i){
		getline(cin, temp.first, '@');
		size_t p = temp.first.find_first_of('+');
		if(p!=temp.first.npos)
			temp.first.resize(p);
		p = temp.first.find_first_of('.');
		while(p!=temp.first.npos){
			temp.first.erase(p,1);
			p = temp.first.find_first_of('.');
		}
		getline(cin, temp.second);
		users.push_back(temp);
	}

	vector<pair<string,string> >::iterator s1=users.begin(), s2;
	while(s1!=users.end()){
		s2=s1;
		++s2;
		while(s2!=users.end()){
			if(*s1==*s2)
				users.erase(s2);
			else
				++s2;
		}
		++s1;
	}

	printf("%lu\n", users.size());
	return 0;
}
