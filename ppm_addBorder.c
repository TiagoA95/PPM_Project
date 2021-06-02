#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 7){
    printf("Error! Use:./ppm_addBorder < input.ppm > output.ppm\n./ppm_addBorder input.ppm > output.ppm\n./ppm_addBorder input.ppm output.ppm\n\n");
    exit(0);
  }

  if(argc == 7){
    FILE* fp = openfile(argv[5]);
    cor moldura;
    moldura.red = atoi(argv[2]);
    moldura.green = atoi(argv[3]);
    moldura.blue = atoi(argv[4]);
    image img = readimage_file(fp);
    image newimg = ppm_addBorder(img,atoi(argv[1]),moldura);
    print_in_file(newimg, argv[6]);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 6){
    FILE* fp = openfile(argv[5]);
    cor moldura;
    moldura.red = atoi(argv[2]);
    moldura.green = atoi(argv[3]);
    moldura.blue = atoi(argv[4]);
    image img = readimage_file(fp);
    image newimg = ppm_addBorder(img,atoi(argv[1]),moldura);
    print_in_output(newimg);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 5){
    cor moldura;
    moldura.red = atoi(argv[2]);
    moldura.green = atoi(argv[3]);
    moldura.blue = atoi(argv[4]);
    image img = readimage_input();
    image newimg = ppm_addBorder(img,atoi(argv[1]),moldura);
    print_in_output(newimg);

    free(img.data);
    return 0;
  }

  return 0;
}
