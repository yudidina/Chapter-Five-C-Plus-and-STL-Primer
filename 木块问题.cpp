#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

const int maxn = 100;
int n;
vector<int> pile[maxn];

//找到木块的所在堆和其所在高度 
void find_block(int a, int &p, int &height){
	for(p=0; p<n; p++){
		for(height=0; height<pile[p].size(); height++){
			if(a == pile[p][height])
				return;
		}
	}
}

//将a木块上方的木块归位
void clear_above(int p, int height){
	for(int i = height+1; i < pile[p].size(); i++){
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(height+1); //pile只应保留下标为0~h的元素 
} 

//将a木块及其上方的木块整体移动到b木块所在堆的顶部
//即第p堆高度为h及其上方的木块...... 
void pile_onto(int p, int h, int p2){
	for(int i = h; i<pile[i].size(); i++){
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
} 

//打印最后结果 
void print(){
	for(int i=0; i<n; i++){
		printf("%d:", i);
		for(int j=0; j<pile[i].size(); j++){
			printf(" %d", pile[i][j]);
		}
		putchar('\n');
	}
}

int main(void){
	cin >> n;
	//赋初值
	for(int i=0; i<n; i++)
		pile[i].push_back(i); 
	string s1, s2;
	int a, b;
	while(cin >> s1 >> a >> s2 >> b){
		int pile_a, pile_b, height_a, height_b;
		find_block(a, pile_a, height_a);
		find_block(b, pile_b, height_b);
		//若a, b在同一堆，则为非法指令，无视即可 
		if(pile_a == pile_b)	continue;
		if(s1 == "move")	clear_above(pile_a, height_a);
		if(s2 == "onto")	clear_above(pile_b, height_b);
		pile_onto(pile_a, height_a, pile_b);
	}
	print();//打印最终结果 
	
	return 0;
}
