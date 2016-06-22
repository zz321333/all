#ifndef ZZAPPPARAMS_H
#define ZZAPPPARAMS_H

#include "zzdefines.h"

/*
 */

namespace zz {
class zzappparams {
public:
  zzappparams() {
  }
  const zzappparams & operator=(const zzappparams &) {
    return *this; 
  }
  void clear() {
  }
private: // pure
  zzappparams(const zzappparams &);
};
}

#endif
