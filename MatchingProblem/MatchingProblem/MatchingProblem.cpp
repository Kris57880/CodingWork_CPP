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
#include "stdafx.h"
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
	//初始化 
	p_M.resize(10);
	p_W.resize(10);
	for(int i=0;i!=10;i++){
		p_M[i].resize(10);
		p_W[i].resize(10);
	}
	r_M.resize(10,-1);
	r_W.resize(10,-1);
	//輸入
	input(p_M);
	input(p_W);
	//配對
	
	 
}
void input(vector<vector<int> >&vec){
	for(int i=0;i!=10;i++){
		for(int j=0;j!=10;j++)
			cin>>vec[i][j];
	}
}
void output();
