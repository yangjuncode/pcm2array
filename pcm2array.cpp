#include <stdio.h>

void printUsage();
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printUsage();
    return 0;
  }

  FILE *inputFile = fopen(argv[1], "rb");
  if (inputFile == NULL) {
    printf("can not open file:%s\r\n", argv[1]);
    return -1;
  }

  short pcm[16];

  printf("short pcm[]={\n");

  bool isFirst = true;
  while (!feof(inputFile)) {
    auto readCount = fread(pcm, 2, 16, inputFile);
    if (readCount <= 0) {
      break;
    }

    for (int i = 0; i < readCount; ++i) {
      if (isFirst) {
        printf(" ");
        isFirst = false;
      } else {
        printf(",");
      }
      printf("%c0x%04X", (pcm[i] < 0) ? '-' : ' ',
             (pcm[i] < 0) ? -pcm[i] : pcm[i]);
    }
    printf("\n");

    if (readCount < 16) {
      break;
    }
  }

  printf("};\n");

  fclose(inputFile);

  return 0;
}
void printUsage() {
  printf("sox demo.wav --bits 16 --encoding signed-integer -c1 -r 8000 -L "
         "demo.raw \n");
  printf("pcm2array demo.raw > demo.c \n");
}
