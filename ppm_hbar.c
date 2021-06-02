#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 7){
    printf("Error! Use:\n./ppm_hbar 5 0 0 0 < input.ppm > output.ppm\n./ppm_hbar 1 255 0 0 input.ppm > output.ppm\n./ppm_hbar 15 255 255 255 input.ppm output.ppm\nWhere the first integer is the bar width, followed by its (R,G,B) color\n\n");
    exit(0);
  }

  if(argc == 7){
    FILE* fp = openfile(argv[5]);
    image img = readimage_file(fp);
    cor barra;
    barra.red = atoi(argv[2]);
    barra.green = atoi(argv[3]);
    barra.blue = atoi(argv[4]);
    image newimg = ppm_hbar(img,atoi(argv[1]),barra);
    print_in_file(newimg, argv[6]);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 6){
    FILE* fp = openfile(argv[5]);
    image img = readimage_file(fp);
    cor barra;
    barra.red = atoi(argv[2]);
    barra.green = atoi(argv[3]);
    barra.blue = atoi(argv[4]);
    image newimg = ppm_hbar(img,atoi(argv[1]),barra);
    print_in_output(newimg);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 5){
    image img = readimage_input();
    cor barra;
    barra.red = atoi(argv[2]);
    barra.green = atoi(argv[3]);
    barra.blue = atoi(argv[4]);
    image newimg = ppm_hbar(img,atoi(argv[1]),barra);
    print_in_output(newimg);

    free(img.data);
    return 0;
  }
  
  return 0;
}
