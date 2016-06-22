#ifndef ZZAPP_H
#define ZZAPP_H

#include "zzdefines.h"

/*
 */

namespace zz {
class zzappparams;
namespace zzapp {
  void init(zzappparams &);
  void shutdown();
  void onstart();
  void onresume();
  void onpause();
  void onstop();
  void update(float);
  void draw();
}
}

#endif
