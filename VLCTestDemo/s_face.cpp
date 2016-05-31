#include "s_face.h"
#ifndef M_PI
#define _USE_MATH_DEFINES
#endif
#include<math.h>
#include <thread>
using namespace std;
using namespace cv;


#define DEGREE_TO_RAD(x) ((x)*M_PI/180.0)
#define RAD_TO_DEGREE(x) ((x)*180.0/M_PI)

t_class::t_class(const char * fn)
{
	setting=false;
	theta_pan_pos=0.0;
	theta_tilt_pos=0.0;
	theta_pan_moved=0.0;
	theta_tilt_moved=0.0;
	last_zoom=0;
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
	move_status=still;
	num_right=0;num_left=0;num_up=0;num_down=0;
}
void t_class::save_as_vect(Point rect_middle, vector<int>& x_points, vector<int>& y_points, int height, vector<int>& h_leng){
	if(x_points.size()==20)
		x_points.clear();
	if(y_points.size()==20)
		y_points.clear();
	x_points.push_back( rect_middle.x );
	y_points.push_back( rect_middle.y );
	h_leng.push_back( height );
}

void t_class::set_face( vector<int>& x_points, vector<int>& y_points, vector<int>& h_length, int& zoom_val, uint32_t panning, uint32_t tilting )
{
	/*if( x_points.size() > 1 )
	{
		int x_diff = x_points.back() - x_points.at( x_points.size() - 2 );
		int y_diff = y_points.back() - y_points.at( y_points.size() - 2 );
		if( abs(x_diff) > 15 ){
			panning = 0x05;
		}
		else if( abs(x_diff) > 25 ){
			panning = 0x07;
		}
	}*/
	int h_leng = h_length.back();
	find( x_points, y_points, h_leng, zoom_val, panning, tilting );
}

void t_class::find( vector<int>& x_points, vector<int>& y_points, int& h_leng, int& zoom_val, uint32_t panning, uint32_t tilting )
{
	//int cur_zoom=get_zoom_zhi();
	//int left_rec=270,right_rec=450,up_rec=110,down_rec=230;
	//if(cur_zoom>3000)
	//{
	//	left_rec=160;
	//	right_rec=480;
	//	up_rec=90;
	//	down_rec=270;
	//}
	//if( x_points.back() > left_rec && x_points.back() < right_rec && y_points.back() >up_rec&& y_points.back() < down_rec )
	//{
	//	cout<<"location----------------- "<<x_points.back()<<" "<<y_points.back()<<endl;
	//	cout<<num_right<<" "<<num_left<<" "<<num_down<<" "<<num_up<<endl;
	//	if(move_status!=still){
	//	send_stop();
	//	//clear_command_visca();
	//	move_status=still;
	//	}
	//	z_find( h_leng, zoom_val );
	//}
	//else if( x_points.back() > right_rec )
	//{
	//	cout<<"send_right "<<x_points.back()<<endl;
	//	if(move_status!=right)
	//	{
	//		//cout<<"change status to right "<<endl;
	//		clear_num_command();
	//		move_status=right;
	//		send_stop();
	//		//clear_command_visca();
	//		move_face_pan(x_points.back());
	//	}
	//	
	//	send_right(panning);
	//	num_right++;
	//}
	//else if( x_points.back() < left_rec)
	//{
	//	cout<<"send_left "<<x_points.back()<<endl;
	//	if(move_status!=left)
	//	{
	//		move_status=left;
	//		clear_num_command();
	//		//cout<<"change status to left "<<endl;
	//		send_stop();
	//		//clear_command_visca();
	//		move_face_pan(x_points.back());
	//	}
	//	
	//	num_left++;
	//	send_left(panning);
	//}
	//else if( y_points.back() >down_rec)
	//{
	//	if(move_status!=down)
	//	{
	//		move_status=down;
	//		clear_num_command();
	//		send_stop();
	//		//clear_command_visca();
	//		move_face_tilt(y_points.back());
	//	}
	//	//cout<<"send_down "<<y_points.back()<<endl;
	//	
	//	num_down++;
	//	send_down(tilting);
	//}
	//else if( y_points.back() < up_rec )
	//{
	//	if(move_status!=up)
	//	{
	//		move_status=up;
	//		clear_num_command();
	//		send_stop();
	//		clear_command_visca();
	//		move_face_tilt(y_points.back());
	//	}
	//	//cout<<"send_up "<<y_points.back()<<endl;
	//	
	//	num_up++;
	//	send_up(tilting);
	//}
	/*thread second(&t_class::PTZcontrol,this,x_points.back(),y_points.back(),h_leng);
	second.join();*/
	PTZcontrol(x_points.back(),y_points.back(),h_leng);
}  
void t_class::PTZcontrol(int x,int y,int h_leng)
{
	bool zoom_in=true;
	int dx=x-320;
	int dy=y-180;
	get_camera_position();
	if(shouldMove(x,y))
		move_face(dx,dy);
	else if(shouldZoom(h_leng,zoom_in))
	{
		cout<<"should zoom x y h_leng"<<x<<" "<<y<<" "<<h_leng<<endl;
		ZoomRectToWindow(dx,dy,h_leng,zoom_in);
	}

	//if(shouldZoom(h_leng,zoom_in))
	//{
	//	cout<<"should zoom x y h_leng"<<x<<" "<<y<<" "<<h_leng<<endl;
	//	ZoomRectToWindow(dx,dy,h_leng,zoom_in);

	//}
	//else if(shouldMove(x,y))
	//{
	//	//setting=true;
	//	//cout<<"should move x y "<<x<<" "<<y<<endl;
	//	move_face(dx,dy);
	//	
	//}
}
bool t_class::shouldZoom(int h_leng,bool &zoom_in)
{
	if( h_leng < 80 )
	{	
		zoom_in=true;
		return true;
	}
	else if( h_leng > 180)
	{
		zoom_in=false;
		return true;
	}
	else
		return false;
}
bool t_class::shouldMove(int x ,int y)
{
	return !(x > 270 && x < 450 && y > 110 && y< 230);
}
void t_class::ZoomRectToWindow(int dx,int dy,int h_leng,bool zoom_in)
{
	/*if(dx>50||dy>50||dx<-50||dy<-50)
	{
		cout<<"zoom shi move:  "<<endl;
	  move_face(dx,dy);
	}*/
	double FOVTilt;
	double m_dh=180;
	if(zoom_in)
	  FOVTilt=RAD_TO_DEGREE(atan((h_leng/2.0/(m_dh/tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))))));
	else
		FOVTilt=RAD_TO_DEGREE(atan(m_dh*tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))/(h_leng/2.0)));
	int zoom_to_be=getZoomValueByFOVTilt(FOVTilt,m_mapFOV);
	zoom_to_be=zoom_to_be/3;
	//cout<<"zoom to face "<<zoom_to_be<<"   cerrent zoom "<<get_zoom_zhi()<<endl;
	VISCA_set_zoom_value(&v_interface, &v_camera,(uint16_t)zoom_to_be);
}
void t_class::z_find(int& h_leng, int zoom_val)
{
	/*if( h_leng > 50 && h_leng < 120 )
	{
		VISCA_set_zoom_stop( &v_interface, &v_camera );
	}
	else if( h_leng < 50 )
	{	
		++zoom_val;
		VISCA_set_zoom_tele_speed( &v_interface, &v_camera, zoom_val );
	}
	else if( h_leng > 120 )
	{
		zoom_val--;
		VISCA_set_zoom_wide_speed( &v_interface, &v_camera, zoom_val );	
	}*/
	if( h_leng > 80 && h_leng < 150 )
	{
		//cout<<"stop zooming: "<<h_leng<<" "<<get_zoom_zhi()<<endl;
		VISCA_set_zoom_stop( &v_interface, &v_camera );
	}
	else if( h_leng < 80 )
	{	
		++zoom_val;
		//cout<<"h_length zoom_val: "<<h_leng<<" "<<get_zoom_zhi()<<endl;
		VISCA_set_zoom_tele_speed( &v_interface, &v_camera, zoom_val );
	}
	else if( h_leng > 150 )
	{
		zoom_val--;
		//cout<<"h_length zoom_val: "<<h_leng<<" "<<get_zoom_zhi()<<" "<<zoom_val<<endl;
		VISCA_set_zoom_wide_speed( &v_interface, &v_camera, zoom_val );	
	}
}

void t_class::zoom_test()
{
	VISCA_set_zoom_tele_speed( &v_interface, &v_camera,1 );
}

void t_class::camera_reset_position_beginning()
{
	//VISCA_set_pantilt_home(&v_interface, &v_camera);
	VISCA_set_pantilt_absolute_position(&v_interface, &v_camera, 10, 10, 0, 15);
}

void t_class::camera_reset_position()
{
	//VISCA_set_pantilt_home(&v_interface, &v_camera);
	VISCA_set_pantilt_absolute_position(&v_interface, &v_camera, 10, 10, 0, 15);
	uint32_t pan_pos=(uint32_t)(15);
	cout<<"unit32_t pan_pos  "<<pan_pos<<endl;
	uint32_t x=0;
	x+= (pan_pos & 0x0f000) >> 12;
    x+= (pan_pos & 0x00f00) >>  8;
    x+=(pan_pos & 0x000f0) >>  4;
   x+= (pan_pos & 0x0000f );
   cout<<"x   "<<x<<endl;
}

int t_class::set_up_down(int dx,int dy,map<int,FOV> &m_mapFOV)
{
	uint32_t p_speed;
	uint32_t t_speed;
	p_speed = 10;
	t_speed = 10;
	int T_dis=0;
	int zoom_zhi=get_zoom_zhi();
	double m_dFOVPan,m_dFOVTilt;
	getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	int pan_position,tilt_position;
	VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	cout<<"current zoom value, int pan_position, tilt_position: "<<zoom_zhi<<" "<<pan_position<<" "<<tilt_position<<endl;
	//cout<<"zoom fovtilt "<<zoom_zhi<<" "<<m_dFOVTilt<<endl;
	double thetaPan=0.0,thetaTilt=0.0;
	double m_dh=180;
	double m_dw=320;
	
	
		thetaPan=RAD_TO_DEGREE(atan(dx/m_dw*tan(DEGREE_TO_RAD(m_dFOVPan/2.0))));
	    thetaTilt=-RAD_TO_DEGREE(atan(dy/m_dh*tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))));
        //cout<<"m_dFOVTilt "<<m_dFOVTilt <<" tilt "<<thetaTilt<<endl;
		DWORD PPos=(DWORD)(int)((thetaPan*7.0)+0.5);   
		DWORD TPos=(DWORD)(int)((thetaTilt*7.0)+0.5);
		//cout<<"PPos PPos "<<(int)PPos<<endl;
		//cout<<"TPos TPos "<<(int)TPos<<endl;
		T_dis=2*(int)thetaTilt;
		//T_dis=(int)TPos;
	cout<<"T_dis "<<(int)T_dis<<endl;
	return T_dis;
}

void t_class::move_face(int dx,int dy)
{
	cout<<"move_face difference dx dy"<<dx<<" "<<dy<<endl;
		uint32_t p_speed;
	    uint32_t t_speed;
	    p_speed = 0x03;
	    t_speed = 10;
	    int zoom_zhi=get_zoom_zhi();
	    int pan_position,tilt_position;
	   // double m_dFOVPan,m_dFOVTilt;
	    getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	    cout<<"zoom fovtilt "<<zoom_zhi<<" "<<m_dFOVTilt<<endl;
	    double thetaPan=0.0,thetaTilt=0.0;
	    double m_dh=180;
	    double m_dw=320;
	
	  if(dx!=0)
		thetaPan=RAD_TO_DEGREE(atan(dx/m_dw*tan(DEGREE_TO_RAD(m_dFOVPan/2.0))));
	  if(dy!=0)
	    thetaTilt=-RAD_TO_DEGREE(atan(dy/m_dh*tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))));
        //cout<<"tilt  tilt "<<thetaTilt<<endl;
	  if(dx!=0 || dy!=0){
		  theta_pan_pos+=thetaPan;
		  theta_tilt_pos+=thetaTilt;
		DWORD PPos=(DWORD)(int)((thetaPan*11.0)+0.5);   
		DWORD TPos=(DWORD)(int)((thetaTilt*10.0)+0.5);
		cout<<"PPos PPos "<<(int)PPos<<endl;
		cout<<"TPos TPos "<<(int)TPos<<endl;
		cout<<"move facce thetaPan thetaTilt zoom_zhi"<<thetaPan<<" "<<thetaTilt<<" "<<zoom_zhi<<endl;
		//cout<<"move face theta_pan_pos theta_tilt_pos "<<theta_pan_pos<<" "<<theta_tilt_pos<<endl;
		VISCA_set_pantilt_relative_position(&v_interface, &v_camera, p_speed,t_speed,(int)PPos,(int)TPos);
	  }
}

void t_class::clear_command_visca()
{
	cout<<"VISCA_clear : "<<VISCA_clear(&v_interface)<<endl;
}
void t_class::clear_num_command()
{
	num_right=0;num_left=0;num_up=0;num_down=0;
}

void t_class::move_face_pan(int x)
{
	int dx=x-320;
	uint32_t p_speed;
	    uint32_t t_speed;
	    p_speed = 10;
	    t_speed = 10;
	    int zoom_zhi=get_zoom_zhi();
	    int pan_position,tilt_position;
	   // double m_dFOVPan,m_dFOVTilt;
	    getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	    //cout<<"zoom fovtilt "<<zoom_zhi<<" "<<m_dFOVTilt<<endl;
	    double thetaPan=0.0,thetaTilt=0.0;
	    double m_dh=180;
	    double m_dw=320;
	
	  if(dx!=0)
		thetaPan=RAD_TO_DEGREE(atan(dx/m_dw*tan(DEGREE_TO_RAD(m_dFOVPan/2.0))));

        //cout<<"tilt  tilt "<<thetaTilt<<endl;
	  if(dx!=0 ){
		  theta_pan_pos+=thetaPan;
		DWORD PPos=(DWORD)(int)((thetaPan*10.0)+0.5);   
		cout<<"move facce thetaPan theta_pan_pos "<<thetaPan<<" "<<theta_pan_pos<<endl;
	  }
}

void t_class::move_face_tilt(int y)
{
	int dy=y-180;
	uint32_t p_speed;
	    uint32_t t_speed;
	    p_speed = 10;
	    t_speed = 10;
	    int zoom_zhi=get_zoom_zhi();
	    int pan_position,tilt_position;
	   // double m_dFOVPan,m_dFOVTilt;
	    getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	    //cout<<"zoom fovtilt "<<zoom_zhi<<" "<<m_dFOVTilt<<endl;
	    double thetaPan=0.0,thetaTilt=0.0;
	    double m_dh=180;
	    double m_dw=320;

	  if(dy!=0)
	    thetaTilt=-RAD_TO_DEGREE(atan(dy/m_dh*tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))));
        cout<<"dy  tilt "<<dy<<" "<<thetaTilt<<endl;
	  if(dy!=0){
		  theta_tilt_pos+=thetaTilt;
		  cout<<"move facce thetaTilt theta_tilt_pos "<<" "<<thetaTilt<<" "<<theta_tilt_pos<<endl;
	  }
}

void t_class::set_marker(int dx,int dy)
{
	/*int i;
	uint32_t p_speed;
	uint32_t t_speed;
	p_speed = 0x03;
	t_speed = 0x06;
	if(y>110&&y<230)
	{
		send_stop();
		int h_leng=50;
		int zoom_val=0;
		z_find( h_leng, zoom_val );
	}
	else if(y>230)
	{ 
		send_down(t_speed);
		set_marker(y);
	}*/
	uint32_t p_speed;
	uint32_t t_speed;
	p_speed = 0x04;
	t_speed = 0x04;
	//int zoom_zhi=get_zoom_zhi();
	int zoom_zhi=0;
	int pan_position,tilt_position;
	//VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	//cout<<"current zoom value, int pan_position, tilt_position: "<<zoom_zhi<<" "<<pan_position<<" "<<tilt_position<<" "<<dy<<endl;
	double m_dFOVPan,m_dFOVTilt;
	getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	//cout<<"zoom fovtilt "<<zoom_zhi<<" "<<m_dFOVTilt<<endl;
	double thetaPan=0.0,thetaTilt=0.0;
	double m_dh=180;
	double m_dw=320;
	
	if(dx!=0)
		thetaPan=RAD_TO_DEGREE(atan(dx/m_dw*tan(DEGREE_TO_RAD(m_dFOVPan/2.0))));
	if(dy!=0)
	    thetaTilt=-RAD_TO_DEGREE(atan(dy/m_dh*tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))));
		//cout<<"thetaPan thetaTilt "<<thetaPan<<" "<<thetaTilt<<endl;
	cout<<"set_marker difference dx     dy   "<<dx<<" "<<dy<<endl;
	cout<<"mengyan thetaPan thetaTilt zoom_zhi"<<thetaPan<<" "<<thetaTilt<<endl;
	cout<<"mengyan theta_pan_pos theta_tilt_pos "<<theta_pan_pos<<" "<<theta_tilt_pos<<endl;
	if(dx!=0 || dy!=0){
		thetaPan-=theta_pan_pos;
		thetaTilt-=theta_tilt_pos;
		/*if(thetaPan>0)
			thetaPan+=1;
		if(thetaPan<0)
			thetaPan-=1;
		if(thetaTilt>0)
			thetaTilt+=1;
		if(thetaTilt<0)
			thetaTilt-=1;*/
		theta_pan_pos+=thetaPan;
		theta_tilt_pos+=thetaTilt;
        //cout<<"tilt  tilt "<<thetaTilt<<endl;
		DWORD PPos=(DWORD)(int)((thetaPan*11.0)+0.5);   
		DWORD TPos=(DWORD)(int)((thetaTilt*10.0)+0.5);
		theta_pan_moved+=thetaPan;theta_tilt_moved+=thetaTilt;
		cout<<"PPos PPos "<<(int)PPos<<endl;
		cout<<"TPos TPos "<<(int)TPos<<endl;
		
		cout<<"set marker thetaPan thetaTilt zoom_zhi"<<thetaPan<<" "<<thetaTilt<<" "<<zoom_zhi<<endl;
		cout<<"set marker theta_pan_pos theta_tilt_pos "<<theta_pan_pos<<" "<<theta_tilt_pos<<endl;
		//zoom_initial();
		//camera_reset_position();
		VISCA_set_pantilt_relative_position(&v_interface, &v_camera, p_speed,t_speed,(int)PPos,(int)TPos);
		//VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	}
	//cout<<"set hou int pan_position, tilt_position: "<<pan_position<<" "<<tilt_position<<endl;
	
	/*double FOVTilt;
	FOVTilt=RAD_TO_DEGREE(atan((100/2.0/(m_dh/tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))))));
	int zoom_to_be=getZoomValueByFOVTilt(FOVTilt,m_mapFOV);
	zoom_to_be=zoom_to_be/2;
	VISCA_set_zoom_value(&v_interface, &v_camera,(uint16_t)zoom_to_be);
	cout<<"zoom to be set: "<<zoom_to_be<<" "<<"current zoom: "<<zoom_zhi<<endl;*/
}

void t_class::set_marker_read(int dx,int dy)
{
	uint32_t p_speed;
	uint32_t t_speed;
	p_speed = 10;
	t_speed = 10;
	int zoom_zhi=0;
	int pan_position,tilt_position;
	double m_dFOVPan,m_dFOVTilt;
	getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	double thetaPan=0.0,thetaTilt=0.0;
	double m_dh=180;
	double m_dw=320;
	
	if(dx!=0)
		thetaPan=RAD_TO_DEGREE(atan(dx/m_dw*tan(DEGREE_TO_RAD(m_dFOVPan/2.0))));
	if(dy!=0)
	    thetaTilt=-RAD_TO_DEGREE(atan(dy/m_dh*tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))));
		//cout<<"thetaPan thetaTilt "<<thetaPan<<" "<<thetaTilt<<endl;
	cout<<"set_marker difference dx     dy   "<<dx<<" "<<dy<<endl;
	cout<<"mengyan thetaPan thetaTilt zoom_zhi"<<thetaPan<<" "<<thetaTilt<<endl;
	get_pan_tilt_pos();
	cout<<"mengyan theta_pan_pos theta_tilt_pos "<<theta_pan_pos<<" "<<theta_tilt_pos<<endl;
	if(dx!=0 || dy!=0){
		thetaPan-=theta_pan_pos;
		thetaTilt-=theta_tilt_pos;
		DWORD PPos=(DWORD)(int)((thetaPan*11.0)+0.5);   
		DWORD TPos=(DWORD)(int)((thetaTilt*7.0)+0.5);
		theta_pan_moved+=thetaPan;theta_tilt_moved+=thetaTilt;
		cout<<"PPos PPos "<<(int)PPos<<endl;
		cout<<"TPos TPos "<<(int)TPos<<endl;
		
		cout<<"set marker thetaPan thetaTilt zoom_zhi"<<thetaPan<<" "<<thetaTilt<<" "<<zoom_zhi<<endl;
		cout<<"set marker theta_pan_pos theta_tilt_pos "<<theta_pan_pos<<" "<<theta_tilt_pos<<endl;
		//zoom_initial();
		//camera_reset_position();
		VISCA_set_pantilt_relative_position(&v_interface, &v_camera, p_speed,t_speed,(int)PPos,(int)TPos);
	}
}

void t_class::get_pan_tilt_pos()
{
	int pan_position,tilt_position;
	VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	cout<<"pan_position read before /16: "<<pan_position<<endl;
	pan_position/=16;
	tilt_position/=16;
	cout<<"pan_position read : "<<pan_position<<endl;
	theta_pan_pos=(double)pan_position/11;
	cout<<"theta_pan_pos read : "<<theta_pan_pos<<endl;
	theta_tilt_pos=(double)tilt_position/10;
}

void t_class::pan_tilt_test()
{
	uint32_t p_speed;
	uint32_t t_speed;
	p_speed = 10;
	t_speed = 10;
	int pan_position,tilt_position;
	int i=0;
	while(i<3)
	{
	 VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	 cout<<"test pan tilt : "<<pan_position<<" "<<tilt_position<<endl;
	 VISCA_set_pantilt_relative_position(&v_interface, &v_camera, p_speed,t_speed,-10,-10);
	 i++;
	}
	VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	 cout<<"test pan tilt : "<<pan_position<<" "<<tilt_position<<endl;
}

void t_class::get_camera_position()
{
	int pan_position,tilt_position;
	VISCA_get_pantilt_position(&v_interface, &v_camera, &pan_position,&tilt_position);
	cout<<"int pan_position, tilt_position: "<<pan_position<<" "<<tilt_position<<endl;
}

void t_class::get_default_camera_position(int &pan_position,int &tilt_position)
{
	int p,t;
	VISCA_get_pantilt_position(&v_interface, &v_camera, &p,&t);
	pan_position=p;
	tilt_position=t;
}

void t_class::zoom_to_write()
{
	double FOVTilt;double m_dh=180;
	//double m_dFOVPan,m_dFOVTilt;
	int zoom_zhi=get_zoom_zhi();
	getFOV(zoom_zhi,m_dFOVPan,m_dFOVTilt,m_mapFOV);
	  FOVTilt=RAD_TO_DEGREE(atan((100/2.0/(m_dh/tan(DEGREE_TO_RAD(m_dFOVTilt/2.0))))));
	int zoom_to_be=getZoomValueByFOVTilt(FOVTilt,m_mapFOV);
	zoom_to_be=zoom_to_be/3*2;
	last_zoom=zoom_zhi;
	cout<<"last_zoom     zoom_to_be    "<<last_zoom<<"   "<<zoom_to_be<<endl;
	if(zoom_to_be>zoom_zhi)
	  VISCA_set_zoom_value(&v_interface, &v_camera,(uint16_t)zoom_to_be);

	//cout<<"zoom to be set: "<<zoom_to_be<<" "<<"current zoom: "<<zoom_zhi<<endl;
}

void t_class::zoom_back_face()
{
	uint32_t p_speed;
	uint32_t t_speed;
	p_speed = 10;
	t_speed = 10;
	cout<<"back to face :"<<last_zoom<<endl;
	VISCA_set_zoom_value(&v_interface, &v_camera,(uint16_t)last_zoom);
	double thetaPan=theta_pan_moved*(-1);
	double thetaTilt=theta_tilt_moved*(-1);
	theta_pan_pos+=thetaPan;
	theta_tilt_pos+=thetaTilt;
	theta_pan_moved=0.0;
	theta_tilt_moved=0.0;
	DWORD PPos=(DWORD)(int)((thetaPan*11.0)+0.5);   
	DWORD TPos=(DWORD)(int)((thetaTilt*10.0)+0.5);
	VISCA_set_pantilt_relative_position(&v_interface, &v_camera, p_speed,t_speed,(int)PPos,(int)TPos);
}

void t_class::send_left(uint32_t panning){
	VISCA_set_pantilt_left( &v_interface, &v_camera, panning, 0x00 );
}

void t_class::send_right(uint32_t panning){
	VISCA_set_pantilt_right( &v_interface, &v_camera, panning, 0x00 );
}

void t_class::send_stop(){
	VISCA_set_pantilt_stop( &v_interface, &v_camera, 0x00, 0x00 );	
	//VISCA_set_pantilt_stop( &v_interface, &v_camera, 0x05, 0x07 );
}

void t_class::send_up(uint32_t tilting){
	VISCA_set_pantilt_up( &v_interface, &v_camera, 0x00, tilting );
}

void t_class::send_down(uint32_t tilting){
	VISCA_set_pantilt_down( &v_interface, &v_camera, 0x00, tilting );
}

void t_class::send_home(){
	VISCA_set_pantilt_home( &v_interface, &v_camera );
}

void t_class::set_zoom_stop(){
	VISCA_set_zoom_stop( &v_interface, &v_camera );
}

void t_class::set_zoom(){
	uint16_t z;
	VISCA_get_zoom_value( &v_interface, &v_camera, &z );

	if( z > 6000 )
	{
		VISCA_set_zoom_value( &v_interface, &v_camera, 4000 );
	}
}

void t_class::zoom_initial(){
	VISCA_set_zoom_value( &v_interface, &v_camera, 0x00 );
	/*int z=-1;
	VISCA_set_zoom_wide_speed( &v_interface, &v_camera, z );*/
}

void t_class::zoom_initial_step(){
	//VISCA_set_zoom_value( &v_interface, &v_camera, 0x00 );
	int z=-1;
	VISCA_set_zoom_wide_speed( &v_interface, &v_camera, z );
}

int t_class::get_zoom_zhi(){
	uint16_t zoom_zhi;
	VISCA_get_zoom_value( &v_interface, &v_camera, &zoom_zhi );
	return (int)(zoom_zhi);
}

#define FLOAT_DIFF 0.001
int t_class::getZoomValueByFOVTilt(double FOVTilt,map<int,FOV> &m_mapFOV)
{
	int n=m_mapFOV.size();
	if(n<=0)
	{
		return 1;//assume the function called after initialized,will never go to here
	}

	map<int,FOV>::iterator it=m_mapFOV.begin();
	if(FOVTilt > it->second.tilt)
		return it->first;

	map<int,FOV>::iterator itlast=it;
	while(it!=m_mapFOV.end())
	{
		if(fabs(FOVTilt-it->second.tilt)< FLOAT_DIFF)
		{
			return it->first;
		}
		else if(FOVTilt < it->second.tilt){
     		itlast=it;
		    it++;
		}
		else
			return getZoomValue(FOVTilt,itlast->first,itlast->second.tilt,it->first,it->second.tilt);
	}
	return (int)itlast->first;
}

int t_class::getZoomValue(double FOV,int zoom1,double FOV1,int zoom2,double FOV2)
{
	double ratio=(FOV-FOV2)/(FOV1-FOV2);
	double zoom=(double)zoom2-(zoom2-zoom1)*ratio;
	return (int)(zoom+0.5);
}

void t_class::connect_serial(int nComId)
{
	CStringA strDevName;
	strDevName.Format( "COM%d:", nComId );
	if(VISCA_open_serial(&v_interface, (LPCSTR)strDevName) != VISCA_SUCCESS){
		printf("failure to connect!!");
	}
	v_interface.broadcast = 0;

	int nCameraNum = 0;
	v_camera.address = 1;
}

int t_class::getFOV(int zoom,double & FOVpan,double & FOVtilt,map<int,FOV> &m_mapFOV)
{
	int n=m_mapFOV.size();
	if(n<=0)
	{
		FOVpan=20;//default value
		FOVtilt=15;
		return 21;
	}
	map<int,FOV>::iterator it=m_mapFOV.find(zoom);
	if(it!=m_mapFOV.end())
	{
		FOVpan=it->second.pan;
		FOVtilt=it->second.tilt;
		return 0;
	}
	it=m_mapFOV.begin();
	map<int,FOV>::iterator itlast=m_mapFOV.begin();
	while(it!=m_mapFOV.end())
	{
		if(itlast->first < zoom  && it->first > zoom)
		{
			getFOVValue(zoom,itlast->first,itlast->second,it->first,it->second,FOVpan,FOVtilt);
			return 0;
		}
		itlast=it;
		it++;
	}
	FOVpan=itlast->second.pan;
	FOVtilt=itlast->second.tilt;
	return 0;
}
void t_class::getFOVValue(int zoom,int lower,FOV lowerFOV,int upper,FOV upperFOV,double & FOVpan,double &FOVtilt)
{
	double ratio=(zoom-lower)/(double)(upper-lower);
	FOVpan=upperFOV.pan+(lowerFOV.pan-upperFOV.pan)*pow((1-ratio),1.3);
	FOVtilt=upperFOV.tilt+(lowerFOV.tilt-upperFOV.tilt)*pow((1-ratio),1.3);
}
// counting time interval
/*
double t, ms, tms = 0;
t = (double)cvGetTickCount(); // start ticking time

t = (double)cvGetTickCount() - t; // end ticking time & find difference
ms = t / ((double)cvGetTickFrequency()*1000.);
printf( "detection time = %g ms\n", ms);
*/
sideROI::sideROI(){
		k02vertical=false;k13vertical=false;
		Point p(0,0);
		for(int i=0;i<4;i++)
			board.push_back(p);
	}
void sideROI::setROI(){

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
}
bool sideROI::isIn(int x,int y)
{
	x+=point1.x;
	y+=point1.y;
	//cout<<"writing x y "<<x<<" "<<y<<endl;
	bool in01,in02,in13,in23;
	bool result=false;
	in01=((k01*x+b01)<y);
	//cout<<"in01 "<<in01<<endl;
	in23=((k23*x+b23)>y);
	//cout<<"in23 "<<in23<<endl;
	//cout<<"b02 : "<<b02<<endl;
	//cout<<"k02 : "<<k02<<endl;
	if(!k02vertical)
		in02=((y-b02)/k02<x);
	else
		in02=(board[0].x<x);
	//cout<<"in02 "<<in02<<endl;
	if(!k13vertical)
		in13=((y-b13)/k13)>x;
	else
		in13=(board[3].x>x);
	//cout<<"in13 "<<in13<<endl;
	result=(in01&&in02&&in13&&in23);
	//cout<<"result of writing in  "<<result<<endl;
	return result;
}
double sideROI::cal_y(int x,int y){
	double ratio=(y-(k01*x+b01))/((k23*x+b23)-(k01*x+b01));
	return ratio;
}