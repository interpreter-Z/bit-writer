#include "bitwriter.h"

//creates pointer to a new BW with filestream (write mode) specified by fn
BW* bw_open(char* fn){
  //open file
  strm = fopen(fn, "w");
  if(strm == NULL){
    fprintf(stderr, "bw_open(): failed to open file: %s", fn);
    return NULL;
  }
  //create new BW
  BW* bw = malloc(sizeof(BW));
  bw->stream = strm;
  bw->buffer = 0x0;
  bw->remain = BYTE_SZ - 1;
  return bw;
}

void bw_close(BW* bw){
  flushbuf(bw);
  fclose(bw->stream);
  free(bw);
}

void writebuf(BW* bw){
  //buffer is empty, do nothing
  if(bw->remain == BYTE_SZ)
    return;
  //pad buffer with 0s
  while(bw->remain > 0){}
    bw->buffer = (bw->buffer << 1) & 0xfe;
    bw->remain--;
  }
  //write buffer to file & reset buffer
  fprintf(bw->stream, "%c", bw->buffer);
  bw->buffer = 0x0;
  bw->remain = BYTE_SZ;
}

void writebit(BW* bw, bool bi){
  if(bi)
    bw->buffer = (bw->buffer << 1) | 0x1;
  else
    bw->buffer = (bw->buffer << 1) & 0xfe;
  bw->remain--;

  if(bw->remain == 0)
    writebuf(bw);
}

void writebyte(BW* bw, unsigned char by){
  for(int i=BYTE_SZ-1; i>=0; i++)
    writebit(bw, buffer & (0x1<<i));
}

//print HuffNodeTree "hnt" to stream in pre-order
void writeHuffman(BW* bw, TreeNode* hnt){
  //stop upon reaching end of tree
  if(hnt == NULL)
    return;
  //Print current node
  if(tree_isleaf(hnt)){
    writebit(bw, 1);
    writebyte(bw, (unsigned char)(valOf(hnt).lb) );
  }
  else{
    writebit(bw, 0);
  }
  //Print rest of tree
  writeHuffman(bw, hnt->left);
  writeHuffman(bw, hnt->right);
}
