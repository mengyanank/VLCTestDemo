#include "s_face.h"

	int drag=0;
	int select_flag = 0;
	bool callback = false;
	char *window_name="side";
Point point1,point2;
Mat first;
marker::marker()
{
}
void marker::stream_run()
{
	void mouseHandler(int event, int x, int y, int flags, void* param);
	capture.open( 0 );
	if ( !capture.isOpened() )
	{
		printf("--(!)Error opening video capture\n"); 
	}
	capture.read(first);
	//char* window_name = "Threshold Demo";
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	imshow(window_name,first);
	setMouseCallback(window_name,mouseHandler,0);
	for (;;)
	 {
		 if(callback)
        {
			Rect r(point1.x, point1.y,point2.x-point1.x,point2.y-point1.y);
			capture.read(pre);
			pre=pre(r);
	        cvtColor( pre, pre, CV_RGB2GRAY );
	        first=pre;
	        capture.read(cur);
			cur=cur(r);
	        cvtColor( cur, cur, CV_RGB2GRAY );
	        capture.read(cap);
	        next=cap.clone();
			next=next(r);
	        cvtColor( next, next, CV_RGB2GRAY );
	        break;
		 }
		 waitKey(5);;
	 }
}
void mouseHandler(int event, int x, int y, int flags, void* param)
{
    if (event == CV_EVENT_LBUTTONDOWN&& !drag && !select_flag)
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
    }
	
}