#include"header.h"

using namespace std;

int main(){
	int count[5] = {0};
	string tmp, str, v[10000];
	CLB_Dim clb_dim;
	Num_IO num_io;
	double p, x, y;
	int q, n, m, num, set, Num_Inst;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/diffeq_4.info");
	// CLB_Dim
	fin >> tmp >> clb_dim.width >> clb_dim.high;
	// Num_I/O_Pad
	fin >> tmp >> num_io.width >> num_io.high;
	p = pace(clb_dim.width, num_io.width);
	// Num_PI
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		count[q]++;
		if(q == 0) {
			cout << x <<":" << y << endl;
		}
	}
	// Num_PO
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		count[q]++;
	}
	fin.close();
	// Nets
	fin.open("../benchmarks/diffeq_4.nets");
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
			if(input[v[i]] == 0) {
				input[v[i]] = set;
			}
		}
	}
	cout << "GG" << endl;
	for (map<string,int>::iterator it=input.begin(); it!=input.end(); ++it){
		count[it->second]++;
	}
	// layout
	for(int i = 0; i < 5; i++){
		cout << count[i] << endl;
	}
	cout  <<  (clb_dim.width / 2) * (clb_dim.width / 2) * 2;
	cout  <<  (clb_dim.high / 2) * (clb_dim.high / 2) * 2;
	return 0;	
}

