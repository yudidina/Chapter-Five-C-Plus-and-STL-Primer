#include<iostream>
#include<vector>
#include<queue> 
#include<set>
using namespace std;

typedef long long LL;
const int coeff[3] = {2,3,5};
/*
第一个参数为数据类型，第二个参数为保存数据的容器（默认为vector<int>），
第三个参数为元素比较函数（默认为less）
*/ 
int main(void){
	priority_queue<LL, vector<LL>, greater<LL> > pg;
	//greater<LL>表示数小的优先级高，最小的在队顶 
	set<LL> s; 
	pg.push(1);
	s.insert(1);
	//从1开始计算 
	for(int i=1; ;i++){
		//x为队列顶部元素 
		LL x = pg.top();
		pg.pop(); 
		if(i == 1500){
			cout << "The 1500'th ugly number is " << x << "." << endl;
			break;
		}
		
		for(int j=0; j<3; j++){
			LL t = x * coeff[j];
			if(!s.count(t)){
				s.insert(t);
				pg.push(t);
			}
		}
	}
	return 0;
}



