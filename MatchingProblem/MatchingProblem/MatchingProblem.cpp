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
void output(vector<int> &vec);
int search_index(vector<int> r_M);
int check(vector<int> r_M);
int n;
int main()
{
	//配置
	vector<vector<int> > p_M;//preferance of Man
	vector<vector<int> > p_W;//preferance of Woman
	vector<int> r_M;//Result of Man
	vector<int> r_W;//Result of Woman 
	int i,j,k,l;
	//初始化
	cin>>n; 
	p_M.resize(n);
	p_W.resize(n);
	for(i=0;i!=n;i++){
		p_M[i].resize(n);
		p_W[i].resize(n);
	}
	r_M.resize(n,-1);
	r_W.resize(n,-1);
	//輸入
	input(p_M);
	input(p_W);
	//------------------
	for(int i=0;i!=n;i++)	cout<<r_M[i]<<" ";
	cout<<"\n";
	for(int i=0;i!=n;i++)	cout<<r_W[i]<<" ";
	cout<<"\n";	
	
	//配對 
	int man_index,woman_index,man1_index=-1;
	while(check(r_M)==false){
		man_index=search_index(r_M);
		for(j=0;j!=n;j++){
			woman_index=p_M[man_index/*y*/][j/*y*/];
			if(r_W[woman_index-1]==-1){ //match success
				r_W[woman_index-1]=man_index;
				r_M[man_index]=woman_index;
				cout<<"woman "<<woman_index<<" and man "<<man_index+1<<" match success\n";
				for(int i=0;i!=n;i++)	cout<<r_M[i]<<" ";
				cout<<"\n";	
				break;
			}else{
				man1_index=r_W[woman_index-1];
				for(k=0;k!=n;k++){//error
					if(p_W[woman_index-1][k]==man1_index){//can't match
						cout<<"failed,next\n";
						for(int i=0;i!=n;i++)	cout<<r_M[i]<<" ";
						cout<<"\n";	
						break;
					}else {									//match success
						r_W[woman_index-1]=man_index;
						r_M[man_index]=woman_index;
						r_M[man1_index]=-1;	//kick!	
						cout<<"woman "<<woman_index<<" and man "<<man_index+1
							<<" match success , and man "<<man1_index+1<<" was kicked\n";
						for(int i=0;i!=n;i++)	cout<<r_M[i]<<" ";
						cout<<"\n";	
						break;
					}
				}
			}
		}
	}
	for(i=0;i!=n;i++)	cout<<r_M[i]<<" ";
	//output(r_M);
	return 0;
}
void input(vector<vector<int> >&vec){
	for(int i=0;i!=n;i++){
		for(int j=0;j!=n;j++)
			cin>>vec[i][j];
	}
}
void output(vector<int> &vec){
	for(int i=0;i!=n;i++)	cout<<"Man "<<i+1<<":\t"<<vec[i]<<endl;
}
int check(vector<int> r_M){
	for(int i=0;i!=r_M.size();i++){
		if(r_M[i]==-1)	return false;
	}
	return true;
}
int search_index(vector<int> r_M){
	for(int i=0;i!=r_M.size();i++)
		if(r_M[i]==-1)	return i;
} 






