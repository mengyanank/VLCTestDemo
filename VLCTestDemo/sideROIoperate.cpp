#include "s_face.h"
sideROI::sideROI(){
		k02vertical=false;k13vertical=false;
		Point p(0,0);
		for(int i=0;i<4;i++)
			board.push_back(p);
	};
void sideROI::setROI(){
	double k02,k01,k13,k23;
	//bool k02vertical=false,k13vertical=false;
	double b01,b02,b13,b23;
	if(board[0].x!=board[2].x)
	 k02=double(board[0].y-board[2].y)/(board[0].x-board[2].x);
	else
       k02vertical=true;
	k01=double(board[0].y-board[1].y)/(board[0].x-board[1].x);
	if(board[1].x!=board[3].x)
	 k13=double(board[1].y-board[3].y)/(board[1].x-board[3].x);
	else
		k13vertical=true;
	k23=double(board[2].y-board[3].y)/(board[2].x-board[3].x);
	//cout<<"k23 "<<k23<<endl;
	b01=board[0].y-board[0].x*k01;
	if(!k02vertical)
	 b02=board[0].y-board[0].x*k02;
	if(!k13vertical)
	 b13=board[1].y-board[1].x*k13;
	b23=board[2].y-board[2].x*k23;
	//cout<<"b23 "<<b23<<endl;
	point1.x=min(board[0].x,board[2].x);
	point1.y=min(board[0].y,board[1].y);
	point2.x=max(board[1].x,board[3].x);
	point2.y=max(board[2].y,board[3].y);
};
bool sideROI::isIn(Point a)
{
	int x=a.x,y=a.y;
	cout<<"writing x y "<<x<<" "<<y<<endl;
	bool in01,in02,in13,in23;
	in01=((k01*x+b01)<y);
	cout<<"in01 "<<in01<<endl;
	in23=((k23*x+b23)>y);
	cout<<"k23 : "<<k23<<endl;
	cout<<"in23 "<<in23<<endl;
	if(!k02vertical)
		in02=((y-b02)/k02<x);
	else
		in02=(board[0].x<x);
	cout<<"in02 "<<in02<<endl;
	if(!k13vertical)
		in13=((y-b13)/k13)>x;
	else
		in13=(board[2].x>x);
	cout<<"in13 "<<in13<<endl;
	return (in01&&in02&&in13&&in23);
};