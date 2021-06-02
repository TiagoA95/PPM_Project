#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//pixel color
typedef struct{
 int red;
 int green;
 int blue;
}cor;

//image structure
typedef struct{
  char magicnumber[2];
  int lines;
  int cols;
  int maxvalue;
  cor** data;
}image;

//open file for reading
FILE* openfile(char* str){
  return fopen(str,"r");
  if(str == NULL){ 
    printf("File not found\n"); 
    exit(0);
  }
}

//read image from .ppm file
image readimage_file(FILE *fp){
  image img;

  fgets(img.magicnumber,3,fp);
  fscanf(fp,"%d %d",&img.cols,&img.lines);

  img.data = (cor**)malloc(img.lines*sizeof(cor*));
  for(int i = 0; i < img.lines; i++) img.data[i] = (cor *)malloc(img.cols * sizeof(cor));

  fscanf(fp,"%d",&img.maxvalue);

  for(int i = 0; i < img.lines; i++)
    for(int j = 0; j < img.cols; j++)
      fscanf(fp,"%d %d %d",
      &img.data[i][j].red, 
      &img.data[i][j].green, 
      &img.data[i][j].blue);
  return img;
}

//read image from stdin
image readimage_input(){
    image img;

    scanf("%s", img.magicnumber);
    scanf("%d %d", &img.cols, &img.lines);

    img.data = (cor**)malloc(img.lines*sizeof(cor*));
      for(int i = 0; i < img.lines; i++) img.data[i] = (cor *)malloc(img.cols * sizeof(cor));

    scanf("%d", &img.maxvalue);

    for (int i = 0; i < img.lines; i++){
        for (int j = 0; j< img.cols; j++){
        scanf("%d %d %d",
        &img.data[i][j].red, 
        &img.data[i][j].green, 
        &img.data[i][j].blue);
        }
    }
    return img;
}

//print image in file
void print_in_file(image img, char* nome){
    FILE* output;
    output = fopen(nome, "w");
    fprintf(output,"%s\n", img.magicnumber);
    fprintf(output,"%d %d\n", img.cols, img.lines);
    fprintf(output,"%d\n", img.maxvalue);
    for (int i = 0; i < img.lines; i++){
        for (int j = 0; j < img.cols; j++){
            fprintf(output,"%d %d %d\n", 
            img.data[i][j].red, 
            img.data[i][j].green, 
            img.data[i][j].blue);
        }
    }
    fclose(output);
}

//print image in stdout
void print_in_output(image img){
    printf("%s\n", img.magicnumber);
    printf("%d %d\n", img.cols, img.lines);
    printf("%d\n", img.maxvalue);
    for (int i = 0; i < img.lines; i++){
        for (int j = 0; j < img.cols; j++){
            printf("%d %d %d\n", 
            img.data[i][j].red, 
            img.data[i][j].green, 
            img.data[i][j].blue);
        }
    }
}

//flip image horizontally
image ppm_h_flip(image img){
  image newimg = img;
  newimg.data = (cor**)malloc(img.lines*sizeof(cor*));
  for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(img.cols * sizeof(cor));

  for (int i = 0, l=0; i < img.lines; i++, l++){
    for(int j = img.cols-1, c = 0; j >= 0; j--, c++){
      newimg.data[l][c].red = img.data[i][j].red;
      newimg.data[l][c].green = img.data[i][j].green;
      newimg.data[l][c].blue = img.data[i][j].blue;
    }
  }
  return newimg;
}

//flip image vertically
image ppm_v_flip(image img){
  image newimg = img;
  newimg.data = (cor**)malloc(img.lines*sizeof(cor*));
  for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(img.cols * sizeof(cor));

  for(int i=img.lines-1, l=0; i>= 0; i--, l++){
        for(int j=0, c=0; j < img.cols; j++, c++){
            newimg.data[l][c].red = img.data[i][j].red;
            newimg.data[l][c].green = img.data[i][j].green;
            newimg.data[l][c].blue = img.data[i][j].blue;
        }
    }
  
  return newimg;
}

//flip image diagonally
image ppm_d_flip(image img){
  image newimg = img;
  newimg.data = (cor**)malloc(img.lines*sizeof(cor*));
  for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(img.cols * sizeof(cor));

  for(int i=img.lines-1, l=0; i>=0; i--, l++){
    for(int j=img.cols-1, c=0; j>=0; j--, c++){
      newimg.data[l][c].red=img.data[i][j].red;
      newimg.data[l][c].green=img.data[i][j].green;
      newimg.data[l][c].blue=img.data[i][j].blue;
      }
  }
  return newimg;
}

//add RBG color to image
image ppm_addRGB(image img, int dR, int dG, int dB){
  image newimg = img;
  newimg.data = (cor**)malloc(img.lines*sizeof(cor*));
  for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(img.cols * sizeof(cor));

  for (int i = 0; i < newimg.lines; i++){
    for(int j = 0; j < newimg.cols; j++){
      if(newimg.data[i][j].red + dR > newimg.maxvalue) newimg.data[i][j].red = newimg.maxvalue;
      else if(newimg.data[i][j].red + dR < 0) newimg.data[i][j].red = 0;
      else newimg.data[i][j].red = newimg.data[i][j].red + dR;

      if(newimg.data[i][j].green + dG > newimg.maxvalue) newimg.data[i][j].green = newimg.maxvalue;
      else if(newimg.data[i][j].green + dG < 0) newimg.data[i][j].green = 0;
      else newimg.data[i][j].green = newimg.data[i][j].green + dG;

      if(newimg.data[i][j].blue + dB > newimg.maxvalue) newimg.data[i][j].blue = newimg.maxvalue;
      else if(newimg.data[i][j].blue + dB < 0) newimg.data[i][j].blue = 0;
      else newimg.data[i][j].blue = newimg.data[i][j].blue + dB;
    }
  }
  return newimg;
}

//convert to grayscale
image ppm_grayscale(image img){
  float g;
  for (int i = 0; i < img.lines; i++){
    for(int j = 0; j < img.cols; j++){
    g = roundf(0.2126*img.data[i][j].red + 
        0.7152*img.data[i][j].green + 
        0.0722*img.data[i][j].blue);
    img.data[i][j].red = g;
    img.data[i][j].green = g;
    img.data[i][j].blue = g;
  }
  }
  return img;
}

//convert to black and white
image ppm_bw(image img, int threshold){
  if ((threshold < 0) || (threshold > img.maxvalue)){ 
    printf("ERRO:\n0 <= threshold <= ppm_maxcolor");
    exit(0);
  }

  float g;
  for (int i = 0; i < img.lines; i++){
    for(int j = 0; j < img.cols; j++){
          g = roundf(0.2126*img.data[i][j].red + 
               0.7152*img.data[i][j].green + 
               0.0722*img.data[i][j].blue);
    if(g > (float)threshold){
      img.data[i][j].red = img.maxvalue;
      img.data[i][j].green = img.maxvalue;
      img.data[i][j].blue = img.maxvalue;
    }

    else{
      img.data[i][j].red = 0;
      img.data[i][j].green = 0;
      img.data[i][j].blue = 0;
    }
  }
  }
  return img;
}

//rotate image right 90 degrees
image ppm_rot_right(image img){
  image newimg = img;
  newimg.lines = img.cols;
  newimg.cols = img.lines;
  newimg.data = (cor**)malloc(newimg.lines*sizeof(cor*));
  for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(newimg.cols * sizeof(cor));

  for(int i = 0; i < newimg.lines; i++){
        for(int j = 0, k = newimg.cols-1; j < newimg.cols; j++, k--){
            newimg.data[i][j].red   = img.data[k][i].red;
            newimg.data[i][j].green = img.data[k][i].green;
            newimg.data[i][j].blue  = img.data[k][i].blue;
        }
    }
  return newimg;
}

//rotate image left 90 degrees
image ppm_rot_left(image img){
  image newimg = img;
  newimg.lines = img.cols;
  newimg.cols = img.lines;
  newimg.data = (cor**)malloc(newimg.lines*sizeof(cor*));
  for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(newimg.cols * sizeof(cor));
  for(int i=0, l=img.cols-1; i<newimg.lines; i++, l--){
        for(int j=0; j<newimg.cols; j++){
            newimg.data[i][j].red=img.data[j][l].red;
            newimg.data[i][j].green=img.data[j][l].green;
            newimg.data[i][j].blue=img.data[j][l].blue;
        }
    }
  return newimg;
}

//add border to the image
image ppm_addBorder(image img, int add, cor moldura){
    image newimg = img;
    newimg.lines = img.lines+(2*add);
    newimg.cols = img.cols+(2* add);
    newimg.data = (cor**)malloc(newimg.lines*sizeof(cor*));
    for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(newimg.cols * sizeof(cor));
    for(int i=0, l=add; i<img.lines; i++, l++){
        for(int j=0, k=add; j<img.cols; j++, k++){
            newimg.data[l][k].red   = img.data[i][j].red;
            newimg.data[l][k].green = img.data[i][j].green;
            newimg.data[l][k].blue  = img.data[i][j].blue;
        }
    }
    for(int i=0; i<newimg.lines; i++){
        for(int j=0; j<newimg.cols; j++){
            if((i<add || j<add) || (i>=add+img.lines || j>=add+img.cols)){
                newimg.data[i][j].red   = moldura.red;
                newimg.data[i][j].green = moldura.green;
                newimg.data[i][j].blue  = moldura.blue;
            }
        }
    }
    return newimg;
}

//concatenate 2 images
image ppm_concat(image image1, image image2){
    image newimg = image1;
    if(image1.lines<image2.lines) newimg.lines=image1.lines;
    else newimg.lines=image2.lines;
    newimg.cols = image1.cols + image2.cols;
    newimg.data = (cor**)malloc(newimg.lines*sizeof(cor*));
    for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(newimg.cols * sizeof(cor));
    for(int i=0; i<newimg.lines; i++){
        for(int j=0; j<image1.cols; j++){
            newimg.data[i][j].red=image1.data[i][j].red;
            newimg.data[i][j].green=image1.data[i][j].green;
            newimg.data[i][j].blue=image1.data[i][j].blue;
        }
    }
    for(int i=0; i<newimg.lines; i++){
        for(int j=image1.cols, j2=0; j<newimg.cols; j++, j2++){
            newimg.data[i][j].red=image2.data[i][j2].red;
            newimg.data[i][j].green=image2.data[i][j2].green;
            newimg.data[i][j].blue=image2.data[i][j2].blue;
        }
    }
    return newimg;
}

//crop image
image ppm_crop(image img, int y1, int x1, int y2, int x2){
    image newimg = img;
    if(x2>=img.lines) newimg.lines=img.lines-x1;
    else newimg.lines=x2-x1+1;
    if(y2>=img.cols) newimg.cols=img.cols-y1;
    else newimg.cols=y2-y1+1;
    newimg.data = (cor**)malloc(newimg.lines*sizeof(cor*));
    for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(newimg.cols * sizeof(cor));

    for(int i=0, i2=x1; i<newimg.lines && i2<img.lines; i++, i2++){
        for(int j=0, j2=y1; j<newimg.cols && j2<img.cols; j++, j2++){
            newimg.data[i][j].red=img.data[i2][j2].red;
            newimg.data[i][j].green=img.data[i2][j2].green;
            newimg.data[i][j].blue=img.data[i2][j2].blue;
        }
    }
    return newimg;
}

//overlay an image with another
image ppm_overlay(image imgtop, image img, int y, int x){
    image newimg = img;
    newimg.data = (cor**)malloc(newimg.lines*sizeof(cor*));
    for(int i = 0; i < newimg.lines; i++) newimg.data[i] = (cor *)malloc(newimg.cols * sizeof(cor));
    newimg = img;
    for(int i = x, i2=0; i < newimg.lines && i2 < imgtop.lines; i++, i2++){
        for(int j = y, j2=0; j < newimg.cols && j2 < imgtop.cols; j++, j2++){
            newimg.data[i][j].red   = imgtop.data[i2][j2].red;
            newimg.data[i][j].green = imgtop.data[i2][j2].green;
            newimg.data[i][j].blue  = imgtop.data[i2][j2].blue;
        }
    }
    return newimg;
}

//make the "maxcolor" pop
image ppm_maxcolor(image img){
  int sumr = 0, sumg = 0, sumb = 0;
  for(int i = 0; i < img.lines; i++){
    for(int j = 0; j < img.cols; j++){
      sumr = sumr + img.data[i][j].red;
      sumg = sumg + img.data[i][j].green;
      sumb = sumb + img.data[i][j].blue;
    }
  }
  sumr = sumr/(img.lines*img.cols);
  sumg = sumg/(img.lines*img.cols);
  sumb = sumb/(img.lines*img.cols);
  if(sumr >= sumg && sumr >= sumb){
    for(int i = 0; i < img.lines; i++){
      for(int j = 0; j < img.cols; j++){
        img.data[i][j].green = 0;
        img.data[i][j].blue = 0;
      }
    }
  }
  if(sumg >= sumr && sumg >= sumb){
    for(int i = 0; i < img.lines; i++){
      for(int j = 0; j < img.cols; j++){
        img.data[i][j].red = 0;
        img.data[i][j].blue = 0;
      }
    }
  }
  if(sumb >= sumr && sumb >= sumg){
    for(int i = 0; i < img.lines; i++){
      for(int j = 0; j < img.cols; j++){
        img.data[i][j].red = 0;
        img.data[i][j].green = 0;
      }
    }
  }
  return img;
}

//adds horizontal bars to the image
image ppm_hbar(image img, int width, cor barra){
  int cont = 0;
  int pintar = 0;
  for(int i = 0; i < img.lines; i++){
    for(int j = 0; j < img.cols; j++){
      if(cont == width){
        cont = 0;
        if(pintar == 1) pintar = 0;
        else pintar = 1;
      }
      if(pintar != 0){
        img.data[i][j].red = barra.red;
        img.data[i][j].green = barra.green;
        img.data[i][j].blue = barra.blue;
      }
    }
    cont++;
  }
  return img;
}

//adds vertical bars to the image
image ppm_vbar(image img, int width, cor barra){
  int cont = 0;
  int pintar = 0;
  for(int i = 0; i < img.cols; i++){
    for(int j = 0; j < img.lines; j++){
      if(cont == width){
        cont = 0;
        if(pintar == 1) pintar = 0;
        else pintar = 1;
      }
      if(pintar != 0){
        img.data[j][i].red = barra.red;
        img.data[j][i].green = barra.green;
        img.data[j][i].blue = barra.blue;
      }
    }
    cont++;
  }
  return img;
}