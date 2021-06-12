#include "circleshape/wrap_circleshape.h"
#include "shape/wrap_shape.h"

using namespace love;

CircleShape* Wrap_CircleShape::CheckCircleShape(lua_State* L, int index)
{
    return Luax::CheckType<CircleShape>(L, index);
}

int Wrap_CircleShape::GetRadius(lua_State* L)
{
    CircleShape* self = Wrap_CircleShape::CheckCircleShape(L, 1);

    lua_pushnumber(L, self->GetRadius());

    return 1;
}

int Wrap_CircleShape::SetRadius(lua_State* L)
{
    CircleShape* self = Wrap_CircleShape::CheckCircleShape(L, 1);
    float radius      = luaL_checknumber(L, 2);

    self->SetRadius(radius);

    return 0;
}

int Wrap_CircleShape::GetPoint(lua_State* L)
{
    CircleShape* self = Wrap_CircleShape::CheckCircleShape(L, 1);

    float x, y;
    self->GetPoint(x, y);

    lua_pushnumber(L, x);
    lua_pushnumber(L, y);

    return 2;
}

int Wrap_CircleShape::SetPoint(lua_State* L)
{
    CircleShape* self = Wrap_CircleShape::CheckCircleShape(L, 1);

    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);

    self->SetPoint(x, y);

    return 0;
}

int Wrap_CircleShape::Register(lua_State* L)
{
    luaL_Reg funcs[] = { { "getRadius", GetRadius },
                         { "setRadius", SetRadius },
                         { "getPoint", GetPoint },
                         { "setPoint", SetPoint },
                         { 0, 0 } };

    return Luax::RegisterType(L, &CircleShape::type, Wrap_Shape::functions, funcs, nullptr);
}
