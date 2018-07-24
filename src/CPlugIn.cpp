
#if _MSC_VER // this is defined when compiling with Visual Studio
#define EXPORT_API __declspec(dllexport) // Visual Studio needs annotating exported functions with this
#else
#define EXPORT_API // XCode does not need annotating exported functions, so define is empty
#endif

// ------------------------------------------------------------------------
// Plugin itself


// Link following functions C-style (required for plugins)
extern "C"
{
#include "lua.h"  
#include "lauxlib.h"  
#include "lualib.h"
#include "LuaWrap.h"
	const EXPORT_API void LuaStateInit()
	{
		initLua();
	}

	// The functions we will call from Unity.
	//
	const EXPORT_API char*  PrintHello(){
		return "Hello";
	}

	int EXPORT_API PrintANumber(){
		return 15;
	}

	int EXPORT_API AddTwoIntegers(int a, int b) {
		//return a + b;
		lua_pushnumber(lState, a);
		lua_pushnumber(lState, b);
		return myadd(lState);
	}

	float EXPORT_API AddTwoFloats(float a, float b) {
		return a + b;
	}

} // end of export C block
