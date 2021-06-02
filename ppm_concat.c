#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 4){
    printf("Error! Use:\n./ppm_concat input1.ppm input2.pmm > output.ppm\n./ppm_concat input1.ppm input2.pmm output.ppm\n\n");
    exit(0);
  }

  if(argc == 4){
    FILE* fp = openfile(argv[1]);
    image img1 = readimage_file(fp);
    fp = openfile(argv[2]);
    image img2 = readimage_file(fp);
    image newimg = ppm_concat(img1,img2);
    print_in_file(newimg, argv[3]);

    free(img1.data);
    free(img2.data);
    fclose(fp);
    return 0;
  }

  if(argc == 3){
    FILE* fp = openfile(argv[1]);
    image img1 = readimage_file(fp);
    fp = openfile(argv[2]);
    image img2 = readimage_file(fp);
    image newimg = ppm_concat(img1,img2);
    print_in_output(newimg);

    free(img1.data);
    free(img2.data);
    fclose(fp);
    return 0;
  }

  if(argc == 2){
    image img = readimage_input();
    image newimg = ppm_concat(img,img);
    print_in_output(newimg);

    free(img.data);
    return 0;
  }

  return 0;
}