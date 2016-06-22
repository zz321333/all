#ifndef ZZPOOL_H
#define ZZPOOL_H

#include "zzdefines.h"

/*
 * zzpool(count, blockSize)
 * allocate()
 * free(ptr)
 */

namespace zz {
class zzpool {
private: // static
  static const char * mTag;
public:
  zzpool(uint count, uint blockSize);
  ~zzpool();
  void * allocate();
  void free(void *);
private:
  unsigned char * addrFromIndex(uint) const;
  unsigned int indexFromAddr(const uchar *) const;
  unsigned char * mData;
  unsigned char * mHead;
  unsigned int mCount;
  unsigned int mBlockSize;
  unsigned int mFree;
  unsigned int mNotFree;
private: // pure
  PURE_PRIVATE(zzpool)
};
}

#endif
