/****************************************************************************
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: number infile outfile\n");
        return 1;
    }
    
    // multiplicator
    int n = atoi(argv[1]);
    if (n < 1 || n > 100)
    {
        printf("N must be positive, less than 100.\n");
        return 1;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

	// temporary bf2 container for outfile
	BITMAPFILEHEADER bf2;
		bf2.bfType = bf.bfType;
		bf2.bfSize = bf.bfSize * n;
		bf2.bfReserved1 = bf.bfReserved1;
		bf2.bfReserved2 = bf.bfReserved2;
		bf2.bfOffBits = bf.bfOffBits;
	
	// temporary bi2 container for outfile
	BITMAPINFOHEADER bi2;
		bi2.biSize = bi.biSize * n; 
		bi2.biWidth = bi.biWidth * n; 
		bi2.biHeight = bi.biHeight * n; 
		bi2.biPlanes = bi.biPlanes; 
		bi2.biBitCount = bi.biBitCount; 
		bi2.biCompression = bi.biCompression; 
		bi2.biSizeImage = bi.biSizeImage * n; 
		bi2.biXPelsPerMeter = bi.biXPelsPerMeter * n; 
		bi2.biYPelsPerMeter = bi.biYPelsPerMeter * n; 
		bi2.biClrUsed = bi.biClrUsed; 
		bi2.biClrImportant = bi.biClrImportant;
	
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	
	// int padding_outptr =  (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
            fputc(0x00, outptr);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
