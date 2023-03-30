#ifndef GUARD
#define GUARD

static unsigned int allBits;

extern void SetBit(char usedBit);
extern void UnSetBit(char usedBit);
extern void ToggleBit(char usedBit);
extern char IsBitSet(char usedBit);
extern unsigned int GetBitState();

#endif