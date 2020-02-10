#include<cstdio>
#include<map>
#include<queue>
using namespace std;

const int maxn = 100+10;

int main(void){
	int t;
	while(scanf("%d", &t)==1 && t){
		map<int,int> team;//key��ͬ��value������ͬ 
		for(int i=0; i<t; i++){
			int n, x;
			scanf("%d", &n);
			while(n--){
				scanf("%d", &x); team[x] = i;
			}
		}
		queue<int>q, q2[maxn]; //q���ŶӵĶ��У�����{3��, 2��, 1��}��q2���Ŷ��ڳ�Ա�Ķ��� 
		for(; ;){
			char cmd[10];
			scanf("%s", cmd);
			if(cmd[0] == 'S')	break;
			else if(cmd[0] == 'D'){
				int t = q.front();
				printf("%d\n", q2[t].front()); q2[t].pop();
				if(q2[t].empty()) q.pop();//����Ŷӳ�ԱΪ0���������Ŷ��˳�����q 
			}
			else if(cmd[0] == 'E'){
				int x;
				scanf("%d", &x);
				int t = team[x];
				if(q2[t].empty()) q.push(t);//�Ŷ�t�������
				q2[t].push(x);
			}
		}
		printf("\n");
	}
} 
/*
3
4
101 102 103 104
2
201 202
3
301 302 303
ENQUEUE
101
ENQUEUE
201
ENQUEUE
301
ENQUEUE
303
ENQUEUE
102
DEQUEUE
...
STOP
*/
