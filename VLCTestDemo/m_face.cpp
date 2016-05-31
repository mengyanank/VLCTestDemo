#include <stdio.h>
#include <stdlib.h>


#include "VlcCapture.h"

#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "s_face.h"

using namespace std;
using namespace cv;
#define THRESH 15
#define FRAMEGROUP 5

void detectanddisplay( Mat frame,vector<int> &x_points,vector<int> &y_points );
struct camera_ptz{
	int z,p,t;
	camera_ptz()
	{
		z=0;
		p=0;
		t=0;
	}
};
//class sideROI{
//public:
//	double k02,k01,k13,k23;
//	double b01,b02,b13,b23;
//	bool k02vertical,k13vertical;
//	vector<Point> board;
//	void setROI();
//
//	sideROI(){
//		k02vertical=false;k13vertical=false;
//		board.reserve(4);
//	};
//
//};
// -> code to load classifier
String face_cascade_name = "C1.xml";
String hs_cascade_name = "C2.xml";
CascadeClassifier face_cascade, hs_cascade;
t_class tct("²©Ê¤ÖÇ´ï730E");
sideROI sr;
bool callback=false;
Point point1,point2,main_tl,main_br;
//Point board[4];
char *window_name="side camera";
char *display="first display Window";
Mat first,mf;
int drag = 0, select_flag = 0;

int main( int argc, char* argv[] )
{
	void mouseHandler(int event, int x, int y, int flags, void* param);
	void mouseHandler_main(int event, int x, int y, int flags, void* param);
	void Load(const char * fn,map<int,FOV> &m_mapFOV);
	bool check_change(vector<Point> &change);
	void set_marker(int dx,int dy);
	void camera_reset_position(int p,int t);
	void camera_zoom_initial();
	void camera_reset_position_beginning();
	//int check_writing(Rect r,Mat pre,Mat cur,Mat next,Mat side,int left,vector<Point> &change);
	Point detect(Mat m,bool &f,int left);

	char* url = "udp://@231.0.16.105:5001";		// udp address
	int w = 640;								// window width
	int h = 360;								// window height

	namedWindow("Display Window", CV_WINDOW_AUTOSIZE);

	if( !face_cascade.load( face_cascade_name ) )
	{ 
		printf("--(!)Error loading face cascade\n"); 
		return -1; 
	};
	if( !hs_cascade.load( hs_cascade_name ) )
	{ 
		printf("--(!)Error loading HS cascade\n"); 
		return -1; 
	};
	int com_num =5;
	tct.connect_serial( com_num );
	int count_main=0;
	vector<int> x_points;
	vector<int> y_points;
	camera_zoom_initial();
	cout<<tct.get_zoom_zhi()<<endl;
	tct.get_camera_position();
	camera_reset_position_beginning();
	int default_pan_position,default_tilt_position;
	tct.get_default_camera_position(default_pan_position,default_tilt_position);
	cout<<"default pan_position, tilt_position: "<<default_pan_position<<" "<<default_tilt_position<<endl;
	cout<<"loop start"<<endl;
	/*while(count_main<=12)
	{
		camera_reset_position();
	tct.get_camera_position();
	 count_main++;	 
	}*/
	// stream using vlc library
	VlcCapture cap;
	cap.start(url, w, h);
	/*int com_num =5;
	tct.connect_serial( com_num );*/

	// stream using opencv
	int left=1;
	/*printf("please input which side the camere is at (1: left    0: right) :\n");
	scanf_s("%d",&left);*/
	vector<Point> change;
	VideoCapture capture;
	Mat side,pre,cur,next;
	Mat d1,d2,motion;
	map<int,FOV> m_mapFOV;
	int focus_count=0;
	//char *filename="²©Ê¤ÖÇ´ï730E";
	//Load("²©Ê¤ÖÇ´ï730E",m_mapFOV);
	capture.open( 0 );
	if ( !capture.isOpened() )
	{
		printf("--(!)Error opening video capture from side camera\n"); 
	}
	capture.read(first);
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	imshow(window_name,first);
	setMouseCallback(window_name,mouseHandler,0);
	 for (;;)
	 {
		 if(callback)
        {
			for(int k=0;k<4;k++)
				cout<<sr.board[k].x<<" "<<sr.board[k].y<<endl;
			sr.setROI();
			/*point1=sr.board[0];
			point2=sr.board[3];*/
			//Rect r(point1.x, point1.y,point2.x-point1.x,point2.y-point1.y);
			Rect r(sr.point1.x, sr.point1.y,sr.point2.x-sr.point1.x,sr.point2.y-sr.point1.y);
			capture.read(pre);
			pre=pre(r);
	        cvtColor( pre, pre, CV_RGB2GRAY );
	        first=pre;
	        capture.read(cur);
			cur=cur(r);
	        cvtColor( cur, cur, CV_RGB2GRAY );
	        capture.read(side);
	        next=side.clone();
			next=next(r);
	        cvtColor( next, next, CV_RGB2GRAY );
	        break;
		 }
		 waitKey(5);
	 }
	//destroyWindow(window_name);
	 callback=false;
	drag = 0; select_flag = 0;
	
	/*camera_reset_position();
	tct.get_camera_position();*/
	mf = cap.frame();
	Mat first_main=mf.clone();
	//namedWindow(display,CV_WINDOW_AUTOSIZE);
	imshow(display,first_main);
	tct.get_camera_position();
	setMouseCallback(display,mouseHandler_main,0);
	for (;;)
	 {
		 if(callback)
        {
			//Rect r(point1.x, point1.y,point2.x-point1.x,point2.y-point1.y);
			break;
		 }
		 waitKey(5);
	 }
	//destroyWindow(display);
	cout<<"after click"<<endl;
	camera_reset_position(default_pan_position,default_tilt_position);
	tct.get_camera_position();
	/*bool go_to_reset=false;
	bool go_to_focus=false;*/
	bool setting=false;
	bool back_face=false;
	bool writing_focused=false;
	camera_ptz front,rear;
	int dx=0;
	int dy=0;
	int last_write_y,last_write_x;
	//tct.zoom_test();
	//tct.pan_tilt_test();
	while ( 1 )
	{
		//cout<<tct.get_zoom_zhi()<<" "<<tct.last_zoom<<endl;
		bool writing=false;
		double y_write_ratio;
		double x_write_ratio;
		Mat& frame = cap.frame();
		capture>>side;
		if(side.empty()||frame.empty())
		{
			cout<<"cannot display"<<endl;
			break;
		}
		/*else
		{*/	
		    //Rect r(point1.x, point1.y,point2.x-point1.x,point2.y-point1.y);
			Rect r(sr.point1.x, sr.point1.y,sr.point2.x-sr.point1.x,sr.point2.y-sr.point1.y);
		    pre=cur.clone();
			cur=next.clone();
			next=side.clone();
		    next=next(r);
			cvtColor( next, next, CV_RGB2GRAY );
		    absdiff(cur,next,d1);
            threshold( d1, d1, 50, 255,0 );
		    absdiff(pre,next,d2);
		    threshold( d2, d2, 50, 255,0 );
		    bitwise_and(d1,d2,motion);
			bool f=false;
			Point center;
			if(setting)
			{
				f=false;
				//cout<<"cannot detect motion+++++++++++++"<<" "<<setting<<" "<<go_to_reset<<" "<<go_to_focus<<endl;
			}
			else
			  center=detect(motion,f,left);
			//cout<<"f!!!!!!!!!!!!!!!!!!!   "<<f<<endl;
			if(f)
			{
				if(change.size()<FRAMEGROUP-1)
				change.push_back(center);
				else
				{
					change.push_back(center);
				    writing=check_change(change);
				    if(writing)
					{
						//cout<<"writing----------"<<endl;	
						center.x+=sr.point1.x;
				        center.y+=sr.point1.y;
						y_write_ratio=sr.cal_y(center.x,center.y);
						cout<<"y_write_ratio ::::::::::: "<<y_write_ratio<<endl;
						x_write_ratio=(double)(center.x-sr.point1.x)/(double)(sr.point2.x-sr.point1.x);
						cout<<"x_write_ratio ::::::::::: "<<x_write_ratio<<endl;
						//cout<<"the ratio is    "<<y_write_ratio<<endl;
						//cout<<"writing   "<<center.x<<" "<<center.y<<" "<<y_write_ratio<<" "<<motion.rows<<endl;
						int radius = cvRound( 50);
						circle( side, center, radius, Scalar( 255, 255, 0 ), 4, 8, 0 );
					}
				}
			}
			else
			{
				if(writing_focused)
				{
					//tct.zoom_initial();
					focus_count++;
					writing_focused=false;
					cout<<"writing_focused is set to be false-----------------++++++++++++++++++" <<endl;
				}
			}
		imshow("side camera",side);
		int c = waitKey(10);
		if( (char)c == 27 )
		{ 
			break; 
		}
			//continue;
		//}
		if(writing&&writing_focused)
		{
			int y_write=(int)((main_br.y-main_tl.y)*y_write_ratio)+main_tl.y;
			int x_write=(int)((main_br.x-main_tl.x)*x_write_ratio)+main_tl.x;
			if(fabs((double)y_write-last_write_y)>50||fabs((double)x_write-last_write_x)>50)
			{
				//tct.zoom_initial();
				//focus_count++;
				writing_focused=false;
				dy=y_write-frame.rows/2;
			    dx=x_write-frame.cols/2;
				last_write_y=y_write;
			    last_write_x=x_write;
				setting=true;
				set_marker(dx,dy);
				//tct.set_marker_read(dx,dy);
				imshow("Display Window", frame);					
				int k = cvWaitKey(30);
			    if( (char)k == 27 )
			    {
				      tct.send_stop();
				      tct.zoom_initial();
				       break;
			    }
				cout<<"writing_focused is set to be false-----------------++++++++++++++++++" <<endl;
				continue;
			}
		}
		if(writing&&(!writing_focused))
		{
			//Mat& frame = cap.frame();
			/*if ( !frame.empty() )
			{*/
			//tct.zoom_initial();
			int y_write=(int)((main_br.y-main_tl.y)*y_write_ratio)+main_tl.y;
			int x_write=(int)((main_br.x-main_tl.x)*x_write_ratio)+main_tl.x-10;
			cout<<"writing:  "<<y_write<<" "<<x_write<<" rows: "<<frame.rows<<endl;
			Point center(x_write,y_write);
			int radius = cvRound( 10);
			Mat first_copy;
			first_copy=first_main.clone();
			circle( first_copy, center, radius, Scalar( 255, 255, 0 ), 4, 8, 0 );
			imshow(display,first_copy);
			//imshow( "Display Window", frame );	
			dy=y_write-frame.rows/2;
			//int dx;
			dx=x_write-frame.cols/2;
			last_write_y=y_write;
			last_write_x=x_write;
			//go_to_reset=true;
			//go_to_focus=true;
			set_marker(dx,dy);
			//tct.set_marker_read(dx,dy);
			tct.zoom_to_write();
			setting=true;
			imshow("Display Window", frame);					
			int k = cvWaitKey(30);
			if( (char)k == 27 )
			{
				  tct.send_stop();
				  tct.zoom_initial();
				  break;
			 }
			continue;
		}
		//if(go_to_reset)
		//{
		//	int c;
		//	int fcount=1;
		//	//Mat& frame = cap.frame();
		//	/*if ( !frame.empty() )
		//	{*/
		//		/*c=tct.get_zoom_zhi();
		//		cout<<"process in zooming ti init: "<<c<<endl;
	 //           if(c>0)
		//		{
		//           tct.zoom_initial_step();	               			   			     		  
		//		}	
		//		else
		//		{
		//			tct.send_stop();
		//			go_to_reset=false;
		//			go_to_focus=true;
		//		}*/

		//		//tct.zoom_initial();
		//		go_to_reset=false;
		//		go_to_focus=true;

		//		   imshow("Display Window", frame);	
		//		   cout<<"frame count: "<<fcount<<endl;
		//		    int k = cvWaitKey(30);
		//	      if( (char)k == 27 )
		//	      {
		//		      tct.send_stop();
		//		      tct.zoom_initial();
		//		       break;
		//	      }	
		//	//}
		//	continue;
		//}
		////if(go_to_focus&&(tct.get_zoom_zhi()==0))
		//if(go_to_focus)
		//{
		//	//camera_reset_position(default_pan_position,default_tilt_position);
		//		/*tct.get_camera_position();
		//		cout<<"zoom value before set_marker: "<<tct.get_zoom_zhi()<<endl;
		//	if(fabs((double)dy)>=30||fabs((double)dx)>=30)
		//	{
		//	  set_marker(dx,dy);
		//	  tct.zoom_to_write();
		//	}
		//	else
		//	{
		//		tct.zoom_to_write();
		//		cout<<"only zoom till: "<<tct.get_zoom_zhi()<<endl;
		//	}*/
		//	//Mat& frame = cap.frame();
		//	int zv=tct.get_zoom_zhi();
		//	/*if ( !frame.empty() )
		//	{*/
		//	/*if(zv==0)
		//	{*/
		//	  //cout<<"zv "<<zv<<endl;
		//	  set_marker(dx,dy);
		//	  tct.zoom_to_write();
		//	  go_to_focus=false;
		//	  setting=true;
		//	//}
		//	imshow("Display Window", frame);	
		//	 int k = cvWaitKey(30);
		//	if( (char)k == 27 )
		//	 {
		//		 tct.send_stop();
		//		 tct.zoom_initial();
		//		  break;
		//	  }	
		//	//}
		//	continue;
		//}
		/*if(y_write)
		  cout<<"writing   "<<y_write<<endl;*/
		/*if(y_dis!=0)
		{
			tct.get_camera_position();
			Mat& frame = cap.frame();
			if ( !frame.empty() )
			{
				if(y_dis<0)
				{
					tct.send_down(20);
					cout<<"y_dis "<<y_dis<<endl;
					y_dis++;
				}
				else
				{
					tct.send_up(20);
					cout<<"y_dis "<<y_dis<<endl;
					y_dis--;
				}
				if(y_dis==0)
				{
					tct.send_stop();
					tct.zoom_to_write(m_mapFOV);
				}
				imshow( "Display Window", frame );
				int k = cvWaitKey(30);
			   if( (char)k == 27 )
			   {
				 tct.send_stop();
				 tct.zoom_initial();
			 	 break;
			   }
			}
			continue;
		}*/
		//Mat& frame = cap.frame();
		/*if ( !frame.empty() )
		{*/
			// -> code for detection & tracking
			/*cout<<count_main<<endl;
			count_main++;*/
			//detectanddisplay(frame);
			if(setting)
			{
			  imshow( "Display Window", frame );
			  front=rear;
			  rear.z=tct.get_zoom_zhi();
			  tct.get_default_camera_position(rear.p,rear.t);			  
			  //cout<<"setting rear z p t: "<<rear.z<<" "<<rear.p<<" "<<rear.t<<endl;
			 // cout<<"setting front z p t: "<<front.z<<" "<<front.p<<" "<<front.t<<endl;
			  if(rear.z==front.z&&rear.p==front.p&&rear.t==front.t)
			  {
				  setting=false;
				  if(!back_face)
				    writing_focused=true;
				  else
					  back_face=false;
				  //cout<<"setting is false ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				  //cout<<"writing_focused     "<<writing_focused<<endl;
				  cout<<"back_face     "<<back_face<<endl;
				  tct.set_zoom_stop();
				  tct.send_stop();
			  }
			  //continue;
			}
			else if(writing_focused)
			{
				imshow( "Display Window", frame );
				//tct.get_camera_position();
				//cout<<"writing    focused: "<<writing_focused<<endl;
				//continue;
			}
			else if(focus_count>0)
			{
				imshow( "Display Window", frame );
				//cout<<"focus_count   "<<focus_count<<endl;
				focus_count=(focus_count+1)%50;
				if(focus_count==0)
				{
					//tct.zoom_initial();
					setting=true;
					back_face=true;
					tct.zoom_back_face();
				}
			}
			else
			{
				//rectangle( frame, Point(270,110), Point(450,230), Scalar(0,0, 255), 1, 8, 0);
				//rectangle( frame, Point(160,60), Point(480,270), Scalar(255,0, 0), 1, 8, 0);
				if(count_main==0)
				{
				  detectanddisplay(frame,x_points,y_points);
				  
				}
				else
					imshow( "Display Window", frame );
				count_main=(count_main+1)%40;
				//continue;
				/*cout<<"rear z p t: "<<tct.get_zoom_zhi()<<" ";
				tct.get_camera_position();*/
			    /*tct.get_default_camera_position(rear.p,rear.t);
				cout<<"rear z p t: "<<rear.z<<" "<<rear.p<<" "<<rear.t<<endl;*/
			    //cout<<"front z p t: "<<front.z<<" "<<front.p<<" "<<front.t<<endl;
			}
			/*if(setting)
			{
				imshow( "Display Window", frame );
				tct.get_camera_position();
				cout<<"stable zoom "<<tct.get_zoom_zhi();
			}
			else
				detectanddisplay(frame);*/

			//cout<<"final zoom: "<<tct.get_zoom_zhi()<<endl;
			/*if(count_main!=1)
			  imshow( "Display Window", frame );*/
			int k = cvWaitKey(30);
			if( (char)k == 27 )
			{
				tct.send_stop();
				tct.zoom_initial();
				break;
			}
		//}
	}
	return 0;
}

//int check_writing(Rect r,Mat pre,Mat cur,Mat next,Mat side,int left,vector<Point> &change)
//{
//	Point detect(Mat m,bool &f,int left);
//	bool check_change(vector<Point> &change);
//	Mat d1,d2,motion;
//	        pre=cur.clone();
//			cur=next.clone();
//			next=side.clone();
//		    next=next(r);
//			cvtColor( next, next, CV_RGB2GRAY );
//		    absdiff(cur,next,d1);
//            threshold( d1, d1, 50, 255,1 );
//		    absdiff(pre,next,d2);
//		    threshold( d2, d2, 50, 255,1 );
//		    bitwise_and(d1,d2,motion);
//			bool f=false;
//			
//			Point center=detect(motion,f,left);
//			if(f)
//			{
//				if(change.size()<FRAMEGROUP-1)
//				change.push_back(center);
//				else
//				{
//					change.push_back(center);
//				    bool writing=check_change(change);
//				    if(writing)
//					{
//						cout<<"writing----------"<<endl;
//						center.x+=point1.x;
//				        center.y+=point1.y;
//						//cout<<"writing   "<<center.x<<" "<<center.y<<endl;
//						int radius = cvRound( 50);
//						circle( side, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
//						return center.y;
//					}
//				}
//			}
//			return 0;
//}

void camera_zoom_initial()
{
	int c=tct.get_zoom_zhi();
	while(c>0){
		tct.zoom_initial_step();
	c=tct.get_zoom_zhi();
	cout<<"process in zooming ti init: "<<tct.get_zoom_zhi()<<endl;
	}
}

void camera_reset_position_beginning()
{
	int c=1;
	while(c<=5){
	tct.camera_reset_position();
	c++;
	tct.get_camera_position();
	}
}

void camera_reset_position(int p,int t)
{
	int c=1;
	cout<<"reset begins "<<endl;
	tct.camera_reset_position();
	while(c<=50){
	//tct.camera_reset_position();
	c++;
	tct.get_camera_position();
	}
	
	
	/*int pan_p,tilt_p;
	cout<<"reset position to: "<<p<<" "<<t<<endl;
	tct.get_default_camera_position(pan_p,tilt_p);
	cout<<"reset position from: "<<pan_p<<" "<<tilt_p<<endl;
	if(tilt_p!=t)
	{
	while(1)
	{
		if(tilt_p>t)
		{
			tct.send_down(20);
			tct.get_default_camera_position(pan_p,tilt_p);
	        cout<<"process in reset pan tilt: "<<pan_p<<" "<<tilt_p<<endl;
		}
		else
		{
			tct.send_up(20);
	     tct.get_default_camera_position(pan_p,tilt_p);
	     cout<<"process in reset pan tilt: "<<pan_p<<" "<<tilt_p<<endl;
		}
	  if(tilt_p==t)
	  {
		  tct.get_default_camera_position(pan_p,tilt_p);
	      cout<<"process in reset pan tilt: "<<pan_p<<" "<<tilt_p<<endl;
		  tct.send_stop();
		  break;
	  }
	}
	}*/
}

void set_marker(int dx,int dy)
{
	tct.set_marker(dx,dy);
}
void Load(const char * fn,map<int,FOV> &m_mapFOV)
{
	FILE * fp=fopen(fn,"rt");
	if(fp==NULL)
		cout<<"cannot open file"<<endl;
	int zoom;
	double pan,tilt;
	m_mapFOV.empty();
	while(fscanf(fp,"%d %lf %lf",&zoom,&pan,&tilt)>0){
		m_mapFOV[zoom]=FOV(pan,tilt);
	}
	fclose(fp);
}

bool check_change(vector<Point> &change)
{
	int px=change.back().x;
	int py=change.back().y;
	if(!(sr.isIn(px,py)))
		return false;
	int len=change.size();
	vector<double> r;
	int i,j;
	for(i=0;i<len;i++)
	{
		int j=i+1;
		while(j<len)
		{
			double a=sqrt(pow((double)(change[j].x-change[i].x),2.0)+pow((double)(change[j].y-change[i].y),2.0));
			r.push_back(a);
			j++;
		}
	}
	change.clear();
	for(i=0;i<r.size();i++)
	{
		if(r[i]>THRESH)
			return false;
	}
	return true;
}

Point detect(Mat m,bool &f,int left)
{
	int i,j;
	int minx,miny,maxx,maxy;
	minx=m.cols;
	miny=m.rows;
	maxx=0;
	maxy=0;
	if(left==1)
	{
	for(i=0;i<m.rows;i++)
		for(j=0;j<m.cols;j++)
		{
			if((int)(m.at<uchar>(i,j))==255)
			{
				f=true;
				if(minx>j)
				{
					minx=j;
					miny=i;
				}
			}
		}
		//cout<<minx<<" "<<miny<<" "<<f<<endl;
	//cout<<(int)(m.at<uchar>(miny, minx))<<endl;
	Point center(minx,miny);
	return center;
	}
	else
	{
	for(i=0;i<m.rows;i++)
		for(j=0;j<m.cols;j++)
		{
			if((int)(m.at<uchar>(i,j))==255)
			{
				f=true;
				if(maxx<j)
				{
					maxx=j;
					maxy=i;
				}
			}
		}
		cout<<maxx<<" "<<maxy<<" "<<f<<endl;
	//cout<<(int)(m.at<uchar>(miny, minx))<<endl;
	Point center(maxx,maxy);
	return center;
	}
	
}

void mouseHandler_main(int event, int x, int y, int flags, void* param)
{
	if (event == CV_EVENT_LBUTTONDOWN&& !drag && !select_flag)
    {

        main_tl = cv::Point(x, y);
        drag = 1;
    }

    if (event == CV_EVENT_MOUSEMOVE && drag && !select_flag)
    {
        cv::Mat img1 = mf.clone();
        main_br = cv::Point(x, y);
        cv::rectangle(img1, main_tl, main_br, CV_RGB(255, 0, 0), 3, 8, 0);
		cv::imshow(display, img1);
    }

    if (event == CV_EVENT_LBUTTONUP && drag && !select_flag)
    {
        cv::Mat img2 = mf.clone();
        main_br = cv::Point(x, y);
        drag = 0;
        select_flag = 1;
        cv::imshow(display, img2);
        callback = true;
    }
}

void mouseHandler(int event, int x, int y, int flags, void* param)
{
    /*if (event == CV_EVENT_LBUTTONDOWN&& !drag && !select_flag)
    {

        point1 = cv::Point(x, y);
        drag = 1;
    }

    if (event == CV_EVENT_MOUSEMOVE && drag && !select_flag)
    {
        cv::Mat img1 = first.clone();
        point2 = cv::Point(x, y);
        cv::rectangle(img1, point1, point2, CV_RGB(255, 0, 0), 3, 8, 0);
        cv::imshow(window_name, img1);
    }

    if (event == CV_EVENT_LBUTTONUP && drag && !select_flag)
    {
        cv::Mat img2 = first.clone();
        point2 = cv::Point(x, y);
        drag = 0;
        select_flag = 1;
        cv::imshow(window_name, img2);
        callback = true;
    }*/
	
	Mat* rgb = (Mat*) param;
	
	if (event == CV_EVENT_LBUTTONDOWN&&!select_flag)
	{
			//printf("%d %d \n", x, y);
		/*if(drag==0)
			cout<<"please select left up point: "<<endl;*/
		/*switch(drag) {
           case 0 : cout<<"please select left up point: "<<endl;
           case 1 : cout<<"please select right up point: "<<endl;
		   case 2 : cout<<"please select left bottom point: "<<endl;
		   case 3 : cout<<"please select right bottom point: "<<endl;
           }*/
		printf("%d %d \n", x, y);
		sr.board[drag]=cv::Point(x, y);
		drag++;
		if(drag==4){
		callback = true;
		select_flag=1;
	}
	}
	
	//cout<<"callback "<<callback<<endl;
	/*Mat* rgb = (Mat*) param;
    if (event == CV_EVENT_LBUTTONDOWN) 
    { 
        printf("%d %d \n", x, y);
    }*/
}

void detectanddisplay( Mat frame,vector<int> &x_points,vector<int> &y_points )
{
	//void set_face( vector<int>& x_points, vector<int>& y_points, vector<int>& h_length, int& zoom_val, uint32_t panning, uint32_t tilting );
	/*vector<int> x_points;
	vector<int> y_points;*/
	vector<int> h_length;
	vector<Rect> face_s;
	uint32_t p_speed;
	uint32_t t_speed;
	bool face_det=true;
	vector<Rect> faces;
	Mat frame_gray, new_gray;
	int downsampling_factor = 1;  // for now.  

	Size size( (frame.cols >> downsampling_factor), (frame.rows >> downsampling_factor) );

	//Mat cen_point;
	cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
	equalizeHist( frame_gray, frame_gray );

	//--. Detect face
	face_cascade.detectMultiScale( frame_gray, faces, 1.25, 4, 0|CV_HAAR_SCALE_IMAGE, Size(40, 40),Size(180, 180) );
	//cout<<"faces detected   "<<faces.size()<<endl;
	for( int i = 0; i < faces.size(); i++ )
	{
		//Mat faceROI = frame_gray( faces[i] );
		Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
		int length = faces[i].height;
		//cout<<"face height   "<<length<<endl;
		// rectangle over face
		//cout<<"drawing rectangles "<<faces[i].x<<" "<<faces[i].y<<" "<<faces[i].width<<" "<<faces[i].height<<endl;
		rectangle( frame, Point(faces[i].x,faces[i].y), Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height), Scalar(0, 255, 0), 1, 8, 0);
		// int radius = cvRound((faces[i].width+faces[i].height)*.009);
		tct.save_as_vect( center, x_points, y_points, length, h_length );
	}
	if ( !faces.size() ) // face detection fails, switch to HS detection
	{
		face_det=false;
		resize( frame_gray, new_gray, size );  // Downsampling needed to speed up HS detection
		hs_cascade.detectMultiScale(new_gray, faces, 1.1, 3, 0, Size(80, 80) );

		for( size_t i = 0; i < faces.size(); i++ )
		{
			faces[i].x = faces[i].x << downsampling_factor;  // To compensate for downsampling
			faces[i].y = faces[i].y << downsampling_factor;
			/*if( faces.size() >0)
			{
				cout<<"HS detected"<<endl;
			}*/
			//faces[i].width = faces[i].width << downsampling_factor; faces[i].height = faces[i].height << downsampling_factor;
			faces[i].x += faces[i].width >>1;  // rectangle scaled down by factor of two to be comparable to the face rectangle
			faces[i].y += faces[i].height >>1;  
			int length = faces[i].height;
			//cout<<"HS height   "<<length<<endl;
			Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
			tct.save_as_vect( center, x_points, y_points, length, h_length );
			
			// rectangle over head/shoulder
			rectangle( frame, faces[i], CV_RGB(255, 0, 0), 1, 8, 0 );
		}
	}
	if ( !faces.size() )
	{
		tct.zoom_initial();
		//cout<<"no  face dectected "<<endl;
	}
	int zoom = 0;
	if( faces.size() == 1)
	{
		p_speed = 0x04;
		t_speed = 0x06;
		//cout<<"one face     face_det"<<" "<<face_det<<endl;
		//std::thread second (&t_class::set_face,&tct,x_points, y_points, h_length, zoom, p_speed, t_speed);
		//std::thread second(set_face);
		tct.set_face( x_points, y_points, h_length, zoom, p_speed, t_speed );	// face tracking
	}
	else if( faces.size() > 1 || faces.empty() )
	{
		//cout<<"multi faces "<<faces.size()<<"----------------"<<faces.empty()<<endl;
		//tct.zoom_initial();
		tct.set_zoom_stop();
		tct.send_stop();
		//cout<<"face empty, stop!"<<endl;
		//tct.zoom_initial();
	}
		/*int zoom_zhi=tct.get_zoom_zhi();
	    cout<<"display zoom value    "<<zoom_zhi<<endl;*/
	//--. Display
	
	imshow( "Display Window", frame );
}
//void set_face()
//{
//	cout<<"q"<<endl;
//}