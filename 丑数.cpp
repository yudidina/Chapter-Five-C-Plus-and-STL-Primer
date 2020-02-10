#include<iostream>
#include<vector>
#include<queue> 
#include<set>
using namespace std;

typedef long long LL;
const int coeff[3] = {2,3,5};
/*
��һ������Ϊ�������ͣ��ڶ�������Ϊ�������ݵ�������Ĭ��Ϊvector<int>����
����������ΪԪ�رȽϺ�����Ĭ��Ϊless��
*/ 
int main(void){
	priority_queue<LL, vector<LL>, greater<LL> > pg;
	//greater<LL>��ʾ��С�����ȼ��ߣ���С���ڶӶ� 
	set<LL> s; 
	pg.push(1);
	s.insert(1);
	//��1��ʼ���� 
	for(int i=1; ;i++){
		//xΪ���ж���Ԫ�� 
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



