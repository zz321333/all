#include "zzapp.h"
#include "zzappparams.h"
#include "zzlog.h"

using namespace zz;

const char * mTag = "zzapp";
zzappparams mParams;

void zzapp::init(zzappparams & params)
{
  mParams = params;
}

void zzapp::shutdown()
{
  mParams.clear();
}

void zzapp::onstart()
{
  zzlog::print(zzlog::elInfo, mTag, "onstart().\n");
}

void zzapp::onresume()
{
  zzlog::print(zzlog::elInfo, mTag, "onresume().\n");
}

void zzapp::onpause()
{
  zzlog::print(zzlog::elInfo, mTag, "onstart().\n");
}

void zzapp::update(float dt)
{
  zzlog::print(zzlog::elInfo, mTag, "update(dt).\n");
}

void zzapp::draw()
{
  zzlog::print(zzlog::elInfo, mTag, "draw().\n");
}
