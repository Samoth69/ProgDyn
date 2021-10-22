// ! Le code de ce fichier viens en grande partie
// ! d'ici: https://stackoverflow.com/a/47785639

#include <stdio.h>

void generateBitmapImage(unsigned char *image, int height, int width, char *imageFileName);
unsigned char *createBitmapFileHeader(int height, int stride);
unsigned char *createBitmapInfoHeader(int height, int width);

void bitmap_init();
void bitmap_draw(int **tb, int size, int k, char *fileName);