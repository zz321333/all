#include "zzpool.h"
#include "zzlog.h"

using namespace zz;

const char * zzpool::mTag = "zzpool";

zzpool::zzpool(uint count, uint blockSize)
  : mData(0)
  , mHead(0)
  , mCount(count)
  , mBlockSize(blockSize)
  , mFree(count)
  , mNotFree(0)
{
  mData = new uchar[mCount * mBlockSize];
  mHead = mData;
}

zzpool::~zzpool()
{
  delete[] mData;
  mData = 0;
  mHead = 0;
  mCount = 0;
  mBlockSize = 0;
  mFree = 0;
  mNotFree = 0;
}

uchar * zzpool::addrFromIndex(uint i) const
{
  return mData + (i * mBlockSize);
}

uint zzpool::indexFromAddr(const uchar * p) const
{
  return (((uint)(p - mData)) / mBlockSize);
}

void * zzpool::allocate()
{
  if(!zzlog::check(mData != 0, zzlog::elError, mTag, "allocate() mData is NULL.\n"))
    return 0;
  if(mNotFree < mCount)
  {
    uint * p = (uint *)addrFromIndex(mNotFree);
    *p = ++mNotFree;
  }
  void * ret = 0;
  if(mFree > 0)
  {
    ret = (void *)mHead;
    if(--mFree != 0)
      mHead = addrFromIndex(*((uint *)mHead));
    else
      mHead = 0;
  }
  return ret;
}

void zzpool::free(void * block)
{
  if(mHead != 0)
  {
    (*(uint *)block) = indexFromAddr(mHead);
    mHead = (uchar *)block;
  }
  else
  {
    *((uint *)block) = mCount;
    mHead = (uchar *)block;
  }
  ++mFree;
}
