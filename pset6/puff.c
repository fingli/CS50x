/****************************************************************************
 * puff.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Takes a compressed (huffed) file and decompresses
 * (puffs) it into the outfile
 *
 * by Yulian Yordanov
 *     CS50 2013
 ***************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"

Tree* root = NULL; // hold the root of the tree

int tree_counter = 0; // count number of trees

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // open outfile
    FILE* outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
		printf("Could not open %s for writing.\n", argv[2]);
		return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // make forest
    Forest* forest = mkforest();

    // search for symbols that are non-zero frequency
    for (int i = 0; i < SYMBOLS; i++)
    {
        // make and plant the trees in the forest
        if (header.frequencies[i] >= 1)
            {
				Tree* new_tree = mktree();
				new_tree->frequency = header.frequencies[i];
				new_tree->symbol = i;
				new_tree->left = NULL;
				new_tree->right = NULL;
				plant(forest, new_tree);

				tree_counter++;
            }
    }

    // run loop until there is only one tree left
    bool done = false;
    while (!done)
    {
        // pick smallest tree
        Tree* a = pick(forest);
        
        // pick second smallest tree
        Tree* b = pick(forest);
        
        // if there is only one tree left in the forest, a is the huffman tree
        if (b == NULL)
        {
            done = true;
            root = a;
        }
        
        // combine two trees
        else
        {
			Tree* combined = mktree(); // create a new parent tree
			
			// make the parent's frequency the sum of its children's frequencies
			combined->frequency = ((a->frequency) + (b->frequency));

			// attach the smaller child to parent's left 
			combined->left = a;

			// attach the larger child to parent's right
			combined->right = b;

            // plant combined tree back in forest
            plant(forest, combined);
        }

    }

    // write message to file
	if (tree_counter == 1) // is a single-char file

		fprintf(outfile, "%c", root->symbol); // print the leaf

	else
	{
        int bit;
        Tree* iterator = root;
        while ((bit = bread(input)) != EOF)	
    	{
    		if (bit == 0) // go left

    			iterator = iterator->left;


    		else if (bit == 1) // go right

    			iterator = iterator->right;


    		// when you find a leaf
    		if ((iterator->left == NULL) && (iterator->right == NULL))
    		{
    			// print the leaf
    			fprintf(outfile, "%c", iterator->symbol);

    			// reset the iterator to root for the next iteration
    			iterator = root;
    		}
    	}
	}

	hfclose(input); // close input file

	fclose(outfile); // close output file

	rmtree(root); // free root

	rmforest(forest); // free forest


	return 0; // the end
}
