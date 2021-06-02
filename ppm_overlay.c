#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 6){
    printf("Error! Use:\n./ppm_overlay 10 20 overlay.ppm < input.pmm > output.ppm\n./ppm_overlay 10 20 overlay.ppm input.pmm > output.ppm\n./ppm_overlay 10 20 overlay.ppm input.pmm output.ppm\nWhere the first 2 integers are the X and Y position where the overlay corner happens\n\n");
    exit(0);
  }

  if(argc == 6){
    FILE* fp = openfile(argv[3]);
    image imgtop = readimage_file(fp);
    fp = openfile(argv[4]);
    image img = readimage_file(fp);
    image newimg = ppm_overlay(imgtop,img,atoi(argv[1]),atoi(argv[2]));
    print_in_file(newimg, argv[5]);

    free(imgtop.data);
    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 5){
    FILE* fp = openfile(argv[3]);
    image imgtop = readimage_file(fp);
    fp = openfile(argv[4]);
    image img = readimage_file(fp);
    image newimg = ppm_overlay(imgtop,img,atoi(argv[1]),atoi(argv[2]));
    print_in_output(newimg);

    free(imgtop.data);
    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 4){
    FILE* fp = openfile(argv[3]);
    image imgtop = readimage_file(fp);
    image img = readimage_input();
    image newimg = ppm_overlay(imgtop,img,atoi(argv[1]),atoi(argv[2]));
    print_in_output(newimg);

    free(img.data);
    free(imgtop.data);
    return 0;
  }
  
  return 0;
}
