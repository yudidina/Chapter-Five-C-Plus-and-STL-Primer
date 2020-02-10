#include<cstdio>
#include<map>
#include<queue>
using namespace std;

const int maxn = 100+10;

int main(void){
	int t;
	while(scanf("%d", &t)==1 && t){
		map<int,int> team;//key不同，value可以相同 
		for(int i=0; i<t; i++){
			int n, x;
			scanf("%d", &n);
			while(n--){
				scanf("%d", &x); team[x] = i;
			}
		}
		queue<int>q, q2[maxn]; //q是团队的队列，比如{3队, 2队, 1队}，q2是团队内成员的队列 
		for(; ;){
			char cmd[10];
			scanf("%s", cmd);
			if(cmd[0] == 'S')	break;
			else if(cmd[0] == 'D'){
				int t = q.front();
				printf("%d\n", q2[t].front()); q2[t].pop();
				if(q2[t].empty()) q.pop();//如果团队成员为0，则整个团队退出队列q 
			}
			else if(cmd[0] == 'E'){
				int x;
				scanf("%d", &x);
				int t = team[x];
				if(q2[t].empty()) q.push(t);//团队t进入队列
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
