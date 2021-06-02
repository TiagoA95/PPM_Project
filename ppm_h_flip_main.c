int main(int argc, char* argv[]){
  if(argc > 3){
    printf("Error! Use:\n./ppm_h_flip < input.ppm > output.ppm\n./ppm_h_flip input.ppm > output.ppm\n./ppm_h_flip input.ppm output.ppm");
    exit(0);
  }

  if(argc == 3){
    FILE* fp = openfile(argv[1]);

    image img = readimage_file(fp);
    image newimg = ppm_h_flip(img);
    print_in_file(newimg, argv[2]);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 2){
    FILE* fp = openfile(argv[1]);

    image img = readimage_file(fp);
    image newimg = ppm_h_flip(img);
    print_in_output(newimg);

    free(img.data);
    fclose(fp);
    return 0;
  }

  if(argc == 1){
    image img = readimage_input();
    image newimg = ppm_h_flip(img);
    print_in_output(newimg);

    free(img.data);
    return 0;
  }
  
  return 0;
}