#ifndef ZZSTRING_H
#define ZZSTRING_H

#include "zzlog.h"
#include <string.h>

/*
 * zzstring()
 * zzstring(zzstring)
 * zzstring(char *)
 * op=(zzstring)
 * op=(char *)
 * op==(char *)
 * cstr()
 * clear()
 */

namespace zz {
template<uint S>
class zzstring {
public:
  zzstring() {
    mStr[0] = 0;
  }
  zzstring(const zzstring<S> & o) {
    *this = o;
  }
  zzstring(const char * s) {
    *this = s;
  }
  const zzstring & operator=(const zzstring<S> & o) {
    strncpy(mStr, o.mStr, S);
    return *this;
  }
  const zzstring & operator=(const char * s) {
    if(zzlog::check(s != 0, zzlog::elWarn, "zzstring", "operator=(s) s is NULL.\n"))
    {
      strncpy(mStr, s, S);
      mStr[S - 1] = '\0';
    }
    return *this;
  }
  bool operator==(const char * s) const {
    if(!zzlog::check(s != 0, zzlog::elWarn, "zzstring", "operator==(s) s is NULL.\n"))
      return false;
    return strcmp(mStr, s) == 0;
  }
  const char * const cstr() const { return mStr; }
  void clear() { memset(mStr, 0, S); };
private:
  char mStr[S];
};
}

#endif
