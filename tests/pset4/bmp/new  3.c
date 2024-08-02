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
			for (int v = 0, biHeight = abs(bi2.biHeight); v < biHeight; v++)
			{
				// write RGB triple to outfile
				fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
				
				        // add padding
						for (int k = 0; k < padding_outptr; k++)
							fputc(0x00, outptr);
			}	
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        // for (int k = 0; k < padding; k++)
        //    fputc(0x00, outptr);
    }