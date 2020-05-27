#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum MusicSelected {
	OUTRIDE_A_CRISIS,
	SPRINTER,
	WINNING_RUN,
	HARD_ROAD
};

struct Color {
	int r;
	int g;
	int b;
	int a;
	Color() { r = 0; g = 0; b = 0; a = 0; }
	Color(int red, int green, int blue, int alpha) {
		r = red, g = green, b = blue, a = alpha;
	}
};

#define Green Color(0,255,0,255)

// Useful typedefs ---------
typedef unsigned int uint;

// Deletes a buffer
#define RELEASE( x ) \
    {									  \
       if( x != nullptr )   \
       {						      \
         delete x;                  \
	     x = nullptr;             \
       }                      \
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	{                              \
       if( x != nullptr )              \
       {                            \
           delete[] x;                \
	       x = nullptr;                    \
		 }                            \
                              \
	 }

// Configuration -----------
#define SCREEN_SIZE 1
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640
#define FPS 30
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Space Invader"
#endif //__GLOBALS_H__