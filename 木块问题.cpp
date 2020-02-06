#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

const int maxn = 100;
int n;
vector<int> pile[maxn];

//�ҵ�ľ������ڶѺ������ڸ߶� 
void find_block(int a, int &p, int &height){
	for(p=0; p<n; p++){
		for(height=0; height<pile[p].size(); height++){
			if(a == pile[p][height])
				return;
		}
	}
}

//��aľ���Ϸ���ľ���λ
void clear_above(int p, int height){
	for(int i = height+1; i < pile[p].size(); i++){
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(height+1); //pileֻӦ�����±�Ϊ0~h��Ԫ�� 
} 

//��aľ�鼰���Ϸ���ľ�������ƶ���bľ�����ڶѵĶ���
//����p�Ѹ߶�Ϊh�����Ϸ���ľ��...... 
void pile_onto(int p, int h, int p2){
	for(int i = h; i<pile[i].size(); i++){
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
} 

//��ӡ����� 
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
	//����ֵ
	for(int i=0; i<n; i++)
		pile[i].push_back(i); 
	string s1, s2;
	int a, b;
	while(cin >> s1 >> a >> s2 >> b){
		int pile_a, pile_b, height_a, height_b;
		find_block(a, pile_a, height_a);
		find_block(b, pile_b, height_b);
		//��a, b��ͬһ�ѣ���Ϊ�Ƿ�ָ����Ӽ��� 
		if(pile_a == pile_b)	continue;
		if(s1 == "move")	clear_above(pile_a, height_a);
		if(s2 == "onto")	clear_above(pile_b, height_b);
		pile_onto(pile_a, height_a, pile_b);
	}
	print();//��ӡ���ս�� 
	
	return 0;
}
