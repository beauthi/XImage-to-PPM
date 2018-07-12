#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

// image : the image object
// filename : the name of the output file
int converter(XImage *image, char* filename)
{
    if (!image)
        return 0;
 
   	unsigned long red_mask = image->red_mask;
   	unsigned long green_mask = image->green_mask;
   	unsigned long blue_mask = image->blue_mask;

    // unique name generation
   	FILE *fp = fopen(filename, "wb");
    if (!fp)
        return 0;
 
  	fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);

   	for (int y = 0; y < image->height; y++)
   	{
   		for (int x = 0; x < image->width ; x++)
   		{
   			unsigned char color[3];
   			unsigned long pixel = XGetPixel(image, x, y);
   			unsigned char blue = pixel & blue_mask;
   			unsigned char green = (pixel & green_mask) >> 8;
   			unsigned char red = (pixel & red_mask) >> 16;

   			color[0] = red;
   			color[1] = green;
   			color[2] = blue;
   			fwrite(color, 1, 3, fp);
   		}
   	}
  	fclose(fp);

    return 1;
}

int main(int argc, char* argv[])
{
    converter(NULL, "out.bpm");
}
