#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef HNT_INC
#include "../HNtree/HNtree.h"
#endif

#define BYTE_SZ 8

typedef struct BW{
  FILE* stream;
  unsigned char buffer;
  int remain;   // 7654 3210
} BW;

BW* bw_open(char* fn);
void bw_close(BW* bw);
void writebuf(BW* bw);
void writebit(BW* bw, bool bi);
void writebyte(BW* bw, unsigned char by);
void writeHuffman(BW* bw, TreeNode* hnt);
