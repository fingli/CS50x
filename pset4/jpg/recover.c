/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 *
 * by Yulian Yordanov
 *     CS50 2013
 ***************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(void)
{
    // open input file 
    FILE* fp = fopen("card.raw", "r");
    if (fp == NULL)
    {
        printf("Could not open 'card.raw'.\n");
        return 1;
    }
	
	// declare output file
	FILE* outptr = NULL;
	
	// temporary storage
	BYTE buffer[512];
	
	// jpg counter
	int counter = 0;
	
    // title of jpg
	char title[8];
	
    // keep track of when an image is found
    bool jpg_being_written = false;
	
	//loop until end of card file
	while (fread(buffer, sizeof(buffer), 1, fp) != 0)
	{
		//check buffer for jpg start
		if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0) || (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1))
		{
			// if there was already an open JPG file
			if (outptr != NULL)
			{
				fclose(outptr); // close it
				jpg_being_written = true;
				counter++; //increase JPG counter
			}
			
			sprintf(title, "%03d.jpg", counter); // print file name
			outptr = fopen(title, "w");	// open output file
				if (outptr == NULL) // if the file can't open -> quit
				{
					fclose(fp);
					fprintf(stderr, "Could not create %s.\n", title);
					return 2;
				}
			
			fwrite(buffer, sizeof(buffer), 1, outptr);
        }
        
		else
		{
			if ((jpg_being_written == true) || (outptr != NULL))
				fwrite(buffer, sizeof(buffer), 1, outptr);
				
			else
			{
				continue;
			}
		}
		
	}
	
	// close last jpg
	fclose(outptr);	
	
    // close infile
    fclose(fp);	
	
	// happy end
	return 0;
}
