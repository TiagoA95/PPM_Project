#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 7){
    printf("Error! Use:\n$ ./ppm_crop 0 0 100 50 < input.ppm > output.ppm\n./ppm_crop 20 10 30 30 input.ppm > output.ppm\n./ppm_crop 100 100 200 200 input.ppm output.ppm\nWhere the first integers are (x0,y0) and (x1,y1) respectively\n\n");
    exit(0);
  }

  if(argc == 7){
    FILE* fp = openfile(argv[5]);
    image img = readimage_file(fp);
    image newimg = ppm_crop(img,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    print_in_file(newimg, argv[6]);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 6){
    FILE* fp = openfile(argv[5]);
    image img = readimage_file(fp);
    image newimg = ppm_crop(img,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    print_in_output(newimg);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 5){
    image img = readimage_input();
    image newimg = ppm_crop(img,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    print_in_output(newimg);

    free(img.data);
    return 0;
  }

  return 0;
}