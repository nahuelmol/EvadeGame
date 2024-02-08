typedef int s8;
typedef unsigned int u8;

typedef int s16;
typedef unsigned int u16;

typedef int s32;
typedef unsigned int u32;

typedef int s64;
typedef unsigned int u64;

#define global_variable static
#define internal static

inline int 
clamp(int min, int val, int max){
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

