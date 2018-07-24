#include "LuaWrap.h"


static void initLua()
{
	lua_State *L = luaL_newstate();
	lState = L;
	luaL_openlibs(L);
}



static int myadd(lua_State* L)
{
	int a = luaL_checknumber(L, 1);
	int b = luaL_checknumber(L, 2);
	a *= 2;
	b *= 3;
	lua_pushnumber(L, a + b);
	return 1;
}

