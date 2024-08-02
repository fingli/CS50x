while(not at end of file)
{
    // load next 512 B block
    
    // check to see if this block is the start of a jpg
    if(start of jpg)
    {
        // write a new jpg
    }
    else
    {
        if(there is a jpg already being written)
        {
            // continue writing the jpeg in progress
        }
        else
        {
            continue;
        }
    }
}

=====================

typedef uint8_t BYTE;

int main(void)
{
// open raw file

 

// declare output file and counter for jpegs

 

// declare a array of char type with 8 elements for filename


//while loop for reading infile . is this correct ((feof(inptr)==0)

          // create buffer of 512 bytes

         // read infile


           
         // if reading not proper than break

           if (fread(buffer,sizeof(buffer),1,inptr)!= 1) than break

 

        // check for four bytes 

 


            if yes than : close any files, use sprintf, increase count, open file created


        // if count greater than or equal to one


           than fwrite buffer to outfile




} // end of while loop


}

close out and in file

return 0;
}