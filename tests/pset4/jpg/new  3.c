/**
	 declared FILE* ouptr twice ;)
**/

typedef uint8_t BYTE;

    // ensure proper usage
    // open input file    //declare a buffer
    BYTE buffer[512];
    // store image filename
    char image_name[8];
   
    //Declare JPG counter
    
    // keep track of when an image is found
    bool image_being_written = false;
 
    // pointer to current jpeg file on hard disk 
    FILE *outptr = NULL;
    
    while(fread(buffer,sizeof(buffer),1,inptr)!= 0)
    {         //check if it is the start of a new JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        { 
            // If there was already an open JPG file -> close it
            //set image_being_written to true
            //print name
            //increase JPG counter
            
            FILE* outptr = fopen(image_name, "w");            
           //If the file can't open -> quit
        
            fwrite(&buffer, sizeof(BYTE), 512, outptr);       
        }
        else
        {
            if (image_being_written == true)
            {
                fwrite(&buffer, sizeof(BYTE), 512, outptr);
            }
            else
            {
                continue;
            }
        } 
    }
    // close card.raw
    // close last jpg
    // return 0
}