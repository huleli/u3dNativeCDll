extern "C"

{
#include "lua.h"  
#include "lauxlib.h"  
#include "lualib.h"  


}
static lua_State* lState;

static void initLua();

static int myadd(lua_State* L);


static const struct luaL_Reg mylib[] = {
	{ "add", myadd },
	{ NULL, NULL }
};
