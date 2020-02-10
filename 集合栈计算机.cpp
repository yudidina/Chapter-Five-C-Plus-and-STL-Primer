#include<set>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#define INS(x)	inserter(x, x.begin())
#define ALL(x)	x.begin(), x.end()
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;	//把集合映射成ID 
vector<Set> Setcache; //根据ID取集合

int ID(Set x){
	if(IDcache.count(x))
		return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size()-1;
} 

int main(void){
	int n;
	stack<int> s;
	cin >> n;
	for(int i=0; i<n; i++){
		string op;
		cin >> op;
		if(op[0] == 'P')	s.push(ID(Set()));
		else if(op[0] == 'D')	s.push(s.top());
		else{
			Set s1 = Setcache[s.top()]; s.pop();
			Set s2 = Setcache[s.top()]; s.pop();
			Set x;
			if(op[0] == 'U') set_union(ALL(s1), ALL(s2), INS(x));
			if(op[0] == 'I') set_intersection(ALL(s1), ALL(s2), INS(x));
			if(op[0] == 'A') { x = s2; x.insert(ID(s1)); }
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
}
