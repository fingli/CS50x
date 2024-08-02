/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a BMP-file piece by piece.
 *
 * by Yulian Yordanov
 *     CS50 2013
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize number infile outfile\n");
        return 1;
    }
    
    // resizefactor n
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

	// temporary bi2 container for outfile
	BITMAPINFOHEADER bi2;
		bi2.biSize = bi.biSize; 
		bi2.biWidth = bi.biWidth * n; 
		bi2.biHeight = bi.biHeight * n; 
		bi2.biPlanes = bi.biPlanes; 
		bi2.biBitCount = bi.biBitCount; 
		bi2.biCompression = bi.biCompression; 
	int padding_outptr = (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
		bi2.biSizeImage = abs(bi2.biHeight) * ((bi2.biWidth * sizeof(RGBTRIPLE)) + padding_outptr);
		bi2.biXPelsPerMeter = bi.biXPelsPerMeter; 
		bi2.biYPelsPerMeter = bi.biYPelsPerMeter; 
		bi2.biClrUsed = bi.biClrUsed; 
		bi2.biClrImportant = bi.biClrImportant;
		
		// temporary bf2 container for outfile
	BITMAPFILEHEADER bf2;
		bf2.bfType = bf.bfType;
		bf2.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi2.biSizeImage;
		bf2.bfReserved1 = bf.bfReserved1;
		bf2.bfReserved2 = bf.bfReserved2;
		bf2.bfOffBits = bf.bfOffBits;	
	
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);
	
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
		// iterate vertically, resizefactor times
        for (int v = 0; v < n; v++)
	    {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {   
			    // temporary storage
			    RGBTRIPLE triple;
		
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

				// write RGB triple to outfile, resizefactor times
			    for (int w = 0; w < n; w++)
				{   
				    // write RGB triple to outfile
				    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
				}    
	
            }
		
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
		
			// add padding to outputr
			for (int k = 0; k < padding_outptr; k++)
				fputc(0x00, outptr);
				
		    // reset cursor to the begining		
		    if (v != (n - 1))
		    {
		        int x = (bi.biWidth * sizeof(RGBTRIPLE)) + padding;
		            fseek(inptr, -x, SEEK_CUR);
		    }

	    }
		
    }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
