#include<iostream>
#include<map>
#include<fstream>
#include"header.h"

using namespace std;

int main(){
	string tmp;
	CLB_Dim clb_dim;
	Num_IO num_io;
	int p;
	int n;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/alu4_4.info");

	fin >> tmp >> clb_dim.width >> clb_dim.high;
	fin >> tmp >> num_io.width >> num_io.high;
	fin >> tmp >> n;
	p = pace(clb_dim.width, num_io.width);

	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		
		input[tmp] = q;
		if(q == 1){
			q1++;
		}else if(q == 2){
			q2++;
		}else if(q == 3){
			q3++;
		}else{
			q4++;
		}
	}
	
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		
		input[tmp] = q;
		if(q == 1){
			q1++;
		}else if(q == 2){
			q2++;
		}else if(q == 3){
			q3++;
		}else{
			q4++;
		}
	}
	
	printf("%d:::%d:::%d:::%d>>%d", q1, q2, q3, q4, input.size());
	
	return 0;	
}

