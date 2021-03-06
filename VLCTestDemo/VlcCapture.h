#ifndef _VLC_CAPTURE_ONBOARD__
#define _VLC_CAPTURE_ONBOARD__

#include "vlc\vlc.h"
#include "opencv\cv.h"

using namespace std;
using namespace cv;

#ifdef _WIN32
	#include <windows.h>
	#include <process.h>
	struct CriticalSection : public CRITICAL_SECTION 
	{
		CriticalSection()	{ InitializeCriticalSection(this); 	}	
		~CriticalSection() 	{ DeleteCriticalSection (this);    	}

		void lock()			{ EnterCriticalSection( this );		}
		void unlock()		{ LeaveCriticalSection( this );		}
	};
	//class Mutex {
	//	HANDLE mutex;
	//public:
	//	Mutex()              { mutex = CreateMutex(NULL,FALSE,NULL); }
	//	~Mutex()             { CloseHandle(mutex); }
	//	inline void lock()   { WaitForSingleObject(mutex,INFINITE); }
	//	inline void unlock() { ReleaseMutex(mutex); }
	//};
#else // ! _WIN32
	#include <pthread.h>
	#include <unistd.h>
	class Mutex {
		pthread_mutex_t mutex;
	public:
		Mutex()              { pthread_mutex_init(&(mutex),NULL); }
		~Mutex()             { pthread_mutex_destroy(&(mutex)); }
		inline void lock()   { pthread_mutex_lock(&(mutex)); }
		inline void unlock() { pthread_mutex_unlock(&(mutex)); }
	};
#endif


class VlcCapture
{
	libvlc_instance_t * inst;
	libvlc_media_player_t *mp;

	unsigned char * pixel;

	CriticalSection critter;

	Mat img;

	static void * cb_lock(void *opaque, void **plane);
	static void cb_unlock(void *opaque, void *picture, void *const *plane) ;
	static void cb_display(void *opaque, void *picture) ;

	unsigned char * updateSize();

public:
	int w,h;

	VlcCapture();
	~VlcCapture();

	Mat frame() { return img; }

	void start( const char * url = "dshow://", int wantW=640, int wantH=360  );
	void pause( bool paused );
};

#endif // _VLC_CAPTURE_ONBOARD__