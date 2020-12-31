#include<iostream>
#include<map>
#include<fstream>
#include"header.h"

using namespace std;

int main(){
	int count[5] = {0};
	string tmp, str, v[10000], k[10000];
	CLB_Dim clb_dim;
	Num_IO num_io;
	int p, n, m, num, set, Num_Inst;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/alu4_4.info");
	// CLB_Dim
	fin >> tmp >> clb_dim.width >> clb_dim.high;
	// Num_I/O_Pad
	fin >> tmp >> num_io.width >> num_io.high;
	p = pace(clb_dim.width, num_io.width);
	// Num_PI
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
	}
	// Num_PO
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
	}
	// Num_Inst
	fin >> tmp >> n >> m;
	Num_Inst = n + m;
	for(int i = 0; i < Num_Inst; i++){
		fin >> k[i];
	}
	fin.close();
	// Nets
	fin.open("../benchmarks/alu4_4.nets");
	fin >> n;
	for(int i = 0; i < n; i++){	
		num = 0, set = 0;
		getline(fin, str);
		
		while(str.find(" ") != -1){
			v[num++] = tmp.assign(str, 0, str.find(" "));
			str.erase(0, str.find(" ")+1);
		}
		v[num] = str;
		for(int i = 1; i <= num; i++){
			if(input[v[i]] > 0) {
				set = input[v[i]];
				break;
			}
		}
		for(int i = 1; i <= num; i++) {
			if(input[v[i]] == 0) {
				input[v[i]] = set;
			}
		}
	}
	for(int i = 0; i < Num_Inst; i++){
		count[input[k[i]]]++;
	}
	// layout
	for(int i = 0; i < 5; i++){
		cout << count[i] << endl;
	}
	return 0;	
}

