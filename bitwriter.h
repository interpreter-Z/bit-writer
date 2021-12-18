#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../HNtree/HNtree.h"

#define BYTE_SZ 8

typedef struct BW{
  FILE* stream
  unsiged char buffer;
  int remain;   // 7654 3210
} BW;

BW* bw_open(char* fn);
void bw_close(BW* bw);
void writebuf(BW* bw);
void writebit(BW* bw, bool bi);
void writebyte(BW* bw, unsigned char by);
void writeHuffman(BW* bw, TreeNode* hnt);
