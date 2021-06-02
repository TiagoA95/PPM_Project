#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "main.c"

int main(int argc, char* argv[]){
  if(argc > 6){
    printf("Error! Use:\n./ppm_ppm_addRGB +10 -1 +50 < input.ppm > output.ppm;\n./ppm_ppm_addRGB -20 +30 0 input.ppm > output.ppm\n./ppm_ppm_addRGB 0 0 +100 input.ppm output.ppm\nWhere the first 3 integers are (Red,Green,Blue) to be added\n\n");
    exit(0);
  }

  if(argc == 6){
    FILE* fp = openfile(argv[4]);

    image img = readimage_file(fp);
    image newimg = ppm_addRGB(img,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
    print_in_file(newimg, argv[5]);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 5){
    FILE* fp = openfile(argv[4]);

    image img = readimage_file(fp);
    image newimg = ppm_addRGB(img,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
    print_in_output(newimg);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 4){
    image img = readimage_input();
    image newimg = ppm_addRGB(img,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
    print_in_output(newimg);

    free(img.data);
    return 0;
  }

  return 0;
}
