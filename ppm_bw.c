#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 4){
    printf("Error! Use:\n./ppm_bw 64 < input.ppm > output.ppm\n./ppm_bw 77 input.ppm > output.ppm\n./ppm_bw 100 input.ppm output.ppm\n");
    exit(0);
  }

  if(argc == 4){
    FILE* fp = openfile(argv[2]);

    image img = readimage_file(fp);
    image newimg = ppm_bw(img,atoi(argv[1]));
    print_in_file(newimg, argv[3]);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 3){
    FILE* fp = openfile(argv[2]);

    image img = readimage_file(fp);
    image newimg = ppm_bw(img,atoi(argv[1]));
    print_in_output(newimg);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 2){
    image img = readimage_input();
    image newimg = ppm_bw(img,atoi(argv[1]));
    print_in_output(newimg);

    free(img.data);
    return 0;
  }

  return 0;
}