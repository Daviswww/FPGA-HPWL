#include<queue>
struct CLB_Dim{
	int width;
	int high;
};

struct Num_IO{
	int width;
	int high;	
};

struct block{
	int x;
	int y;
	int q;
};

struct Hight{
	int top;
	int bottom;
};

struct Width{
	int left;
	int right;
};

struct CLB{
	Width top;
	Width bottom;
	Hight left;
	Hight right;
};


