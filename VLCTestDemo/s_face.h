#ifndef S_FACE_H
#define S_FACE_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv\highgui.h>
#include <opencv\cv.h>
// #include "control\ChannelsFromTcpConnection.h"
#include "opencv\cv.h"
#include "opencv2\highgui\highgui.hpp"
#include "visca\libvisca.h"

#include <iostream>
#include <conio.h>
#include <atlstr.h>

using namespace cv;
using namespace std;

struct FOV{
		double pan;
		double tilt;
		FOV(double p,double t){pan=p;tilt=t;}
		FOV(){}
	};

class t_class
{
public:
	
	typedef void* VSTOIP91Handle;
	VSTOIP91Handle h_hand;

	VISCAInterface_t v_interface;
	VISCACamera_t v_camera;
	map<int,FOV> m_mapFOV;
	bool setting;
	t_class(const char * fn);
	double theta_pan_pos,theta_tilt_pos;
	double m_dFOVPan,m_dFOVTilt;
	double theta_pan_moved,theta_tilt_moved;
	int last_zoom;
	int num_right,num_left,num_up,num_down;
	enum status{right,left,up,down,still};
	status move_status;

	void connect_serial(int nComId);
	void send_left(uint32_t panning);
	void send_right(uint32_t panning);
	void send_up(uint32_t tilting);
	void send_down(uint32_t tilting);
	void send_stop();
	void send_home();
	void set_zoom();
	void zoom_initial();
	void save_as_vect(Point rect_middle, vector<int>& x_p, vector<int>& y_p, int height, vector<int>& h_leng);
	void set_face( vector<int>& x_p, vector<int>& y_p, vector<int>& h_length, int& zoom_val, uint32_t panning, uint32_t tilting);
	void find(vector<int>& x_points, vector<int>& y_points, int& h_leng, int& zoom_val, uint32_t panning, uint32_t tilting );
	void z_find(int& h_leng, int zoom_val);

	bool shouldZoom(int h_leng,bool &zoom_in);
	bool shouldMove(int x ,int y);
	void PTZcontrol(int x,int y,int h_leng);
	void ZoomRectToWindow(int dx,int dy,int h_leng,bool zoom_in);
	void move_face(int dx,int dy);
	void move_face_pan(int x);
	void move_face_tilt(int y);
	void zoom_test();
	void pan_tilt_test();
	void clear_num_command();
	void clear_command_visca();
	void set_marker(int dx,int dy);
	void set_marker_read(int dx,int dy);
	void get_pan_tilt_pos();
	int get_zoom_zhi();
	int getFOV(int zoom,double & FOVpan,double & FOVtilt,map<int,FOV> &m_mapFOV);
	void getFOVValue(int zoom,int lower,FOV lowerFOV,int upper,FOV upperFOV,double & FOVpan,double &FOVtilt);
	int getZoomValueByFOVTilt(double FOVTilt,map<int,FOV> &m_mapFOV);
	int getZoomValue(double FOV,int zoom1,double FOV1,int zoom2,double FOV2);
	int set_up_down(int dx,int dy,map<int,FOV> &m_mapFOV);
	void zoom_to_write();
	void zoom_back_face();
	void camera_reset_position();
	void camera_reset_position_beginning();
	void get_camera_position();
	void get_default_camera_position(int &pan_position,int &tilt_position);
	void zoom_initial_step();
	void set_zoom_stop();

private:

};

class sideROI{
public:
	double k02,k01,k13,k23;
	double b01,b02,b13,b23;
	bool k02vertical,k13vertical;
	Point point1,point2;
	vector<Point> board;
public:
	void setROI();
	bool isIn(int x,int y);
	double cal_y(int x,int y);
	sideROI();

};



#endif