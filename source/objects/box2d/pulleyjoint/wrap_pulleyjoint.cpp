#include "pulleyjoint/wrap_pulleyjoint.h"
#include "joint/wrap_joint.h"

using namespace love;

PulleyJoint* Wrap_PulleyJoint::CheckPulleyJoint(lua_State* L, int index)
{
    PulleyJoint* joint = Luax::CheckType<PulleyJoint>(L, index);

    if (!joint->IsValid())
        luaL_error(L, "Attempt to use destroyed joint!");

    return joint;
}

int Wrap_PulleyJoint::GetGroundAnchors(lua_State* L)
{
    PulleyJoint* self = Wrap_PulleyJoint::CheckPulleyJoint(L, 1);
    lua_remove(L, 1);

    return self->GetGroundAnchors(L);
}

int Wrap_PulleyJoint::GetLengthA(lua_State* L)
{
    PulleyJoint* self = Wrap_PulleyJoint::CheckPulleyJoint(L, 1);

    lua_pushnumber(L, self->GetLengthA());

    return 1;
}

int Wrap_PulleyJoint::GetLengthB(lua_State* L)
{
    PulleyJoint* self = Wrap_PulleyJoint::CheckPulleyJoint(L, 1);

    lua_pushnumber(L, self->GetLengthB());

    return 1;
}

int Wrap_PulleyJoint::GetRatio(lua_State* L)
{
    PulleyJoint* self = Wrap_PulleyJoint::CheckPulleyJoint(L, 1);

    lua_pushnumber(L, self->GetRatio());

    return 1;
}

int Wrap_PulleyJoint::Register(lua_State* L)
{
    luaL_Reg funcs[] = { { "getGroundAnchors", GetGroundAnchors },
                         { "getLengthA", GetLengthA },
                         { "getLengthB", GetLengthB },
                         { "getRatio", GetRatio },
                         { 0, 0 } };

    return Luax::RegisterType(L, &PulleyJoint::type, Wrap_Joint::functions, funcs, nullptr);
}
