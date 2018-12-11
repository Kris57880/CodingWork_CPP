// MatchingProblem.cpp : Defines the entry point for the console application.
//Author Hiko
//Gale-Shapley Algorithm(n^2 )
/*-----------------------------------------------------------------
	intialize each person to be free
	While(some man m is free and hasn't propose to every woman)do
		w=heightst ranked woman in m's list to whom m hasn't yet prposed;
		if(w is free)
			(m,w)become engaged;
		else if(w prefers mto her fiance m')
			(m,w)become engaged;
			m' become free;
	return the set S of engaged pairs
-------------------------------------------------------------------*/
//https://zerojudge.tw/ShowProblem?problemid=c484
#include <iostream>
#include <vector>
using namespace std;
void input(vector<vector<int> >&vec);
void output();
int main()
{
	//配置
	vector<vector<int> > p_M;//preferance of Man
	vector<vector<int> > p_W;//preferance of Woman
	vector<int> r_M;//Result of Man
	vector<int> r_W;//Result of Woman 
	int i,j,k,l;
	//初始化 
	p_M.resize(5);
	p_W.resize(5);
	for(i=0;i!=5;i++){
		p_M[i].resize(5);
		p_W[i].resize(5);
	}
	r_M.resize(5,-1);
	r_W.resize(5,-1);
	//輸入
	input(p_M);
	input(p_W);
	//配對
	int man_index,woman_index,man1_index;
	for(i=0;i!=5;i++){
		man_index=i;
		for(j=0;j!=5;j++){
			woman_index=p_M[man_index][j];
			if(r_W[woman_index]==-1){ //match success
				r_W[woman_index]=man_index;
				r_M[man_index]=woman_index;
				} 
			else 
				man1_index=r_W[woman_index];
				for(k=0;k!=5;k++){
					if(p_W[woman_index][k]==man1_index)	break;//can't match
					else {									//match success
						r_W[woman_index]=man_index;
						r_M[man_index]=woman_index;
						r_M[man1_index]=-1;//kick!
					}
				}
		}
	}
	 return 0;
}
void input(vector<vector<int> >&vec){
	for(int i=0;i!=5;i++){
		for(int j=0;j!=5;j++)
			cin>>vec[i][j];
	}
}
void output();
