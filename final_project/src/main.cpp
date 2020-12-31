#include"header.h"

using namespace std;

int main(){
	int count[5] = {0};
	string tmp, str, v[10000], inst[10000];
	CLB_Dim clb_dim;
	Num_IO num_io;
	double p, x, y;
	int Num_PO, Num_PI;
	int q, n, pi, po, num, set, Num_Inst = 0;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/clma_4.info");
	// CLB_Dim
	fin >> tmp >> clb_dim.width >> clb_dim.high;
	// Num_I/O_Pad
	fin >> tmp >> num_io.width >> num_io.high;
	p = pace(clb_dim.width, num_io.width);
	// Num_PI
	fin >> tmp >> Num_PI;
	for(int i = 0; i < Num_PI; i++){
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		count[q]++;
	}
	// Num_PO
	fin >> tmp >> Num_PO;
	for(int i = 0; i < Num_PO; i++){
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		count[q]++;
	}
	// Num_Inst
	fin >> tmp >> pi >> po;
	Num_Inst = pi + po;
	for(int i = 0; i < Num_Inst; i++){
		fin >> tmp;
		inst[i] = tmp;
	}
	fin.close();
	// Nets
	fin.open("../benchmarks/clma_4.nets");
	fin >> n;
	for(int j = 0; j < n; j++){
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
//			input[v[i]] = set;
			if(input[v[i]] == 0) {
				input[v[i]] = set;
			}
		}
	}
	cout << "done!" << endl;
//	for (map<string,int>::iterator it=input.begin(); it!=input.end(); ++it){
//		count[it->second]++;
//	}
	for(int i = 0; i < Num_Inst; i++){
		count[input[inst[i]]]++;
	}
	// layout
	for(int i = 0; i < 5; i++){
		cout << i <<":::" <<count[i] << endl;
	}
	cout  << "block:" <<(clb_dim.width / 2) * (clb_dim.high / 2) * 2;
	return 0;	
}

