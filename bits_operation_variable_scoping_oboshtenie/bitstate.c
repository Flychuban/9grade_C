#include "bitstate.h"

static unsigned int allBits = 0; 

void SetBit(char usedBit){
    allBits |= 1 << (usedBit - 1); 
}

void UnSetBit(char usedBit){
    allBits &= ~(1 << (usedBit - 1));
}

void ToggleBit(char usedBit){
    allBits ^= 1 << (usedBit - 1);
}

char IsBitSet(char usedBit){
    unsigned int isbitset = allBits & (1 << (usedBit - 1));
    isbitset = isbitset == 0 ? 0 : 1;
    return isbitset;
}

unsigned int GetBitState(){
    return allBits;
}