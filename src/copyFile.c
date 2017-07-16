/*
 * CopyFile.c
 *
 *  Created on: Feb 09, 2017
 *      Author: Gajjan Jasani
 *     Purpose: Copy content of one file to another file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define READ_FAILURE 1	// constant for file read error
#define WRITE_FAILURE 2	// constant for file write error
#define LINE 150		// constant for user input length
#define BUFFER_SIZE 200	// constant for buffer size

char  user_input[LINE] = "";  // array to hold user input

void copy_file (FILE*, FILE*);

int main(void){

	FILE* input_file;	// input file pointer
	FILE* output_file;	// output file pointer

	printf("Please enter path for the input file:\n");
	fflush(stdout);
	// Reading the user input for input file path
	if(fgets(user_input, LINE, stdin) != NULL){
		// replacing newline character (which was added by fgets)
		// from the end of the user input with null character 
		size_t ln = strlen(user_input) - 1;
		if(user_input[ln] == '\n'){
			user_input[ln] = '\0';
		}

		input_file = fopen(user_input, "r");
		if(input_file == NULL){
			perror("Read error");
			fprintf(stderr, "ERROR: couldn't open %s for reading\n",
					user_input);
			exit(READ_FAILURE);		// return 1 if error in file reading
		}
	}

	printf("Please enter path for the output file:\n");
	fflush(stdout);
	// Reading the user input for output file path
	if(fgets(user_input, LINE, stdin) != NULL){
		// replacing newline character (which was added by fgets)
		// from the end of the user input with null character
		size_t ln = strlen(user_input) - 1;
		if(user_input[ln] == '\n'){
			user_input[ln] = '\0';
		}
		output_file = fopen(user_input, "w");
		if(output_file == NULL){
			perror("Read error");
			fprintf(stderr, "ERROR: couldn't open %s for writing\n",
					user_input);
			exit(WRITE_FAILURE);	// return 2 if error in file writing
		}
	}

	copy_file(input_file, output_file); // call to helper function

	fclose(input_file);
	fclose(output_file);

	printf("File copied successfully.\n");

	return (0);
}

/**
 * Helper function for copying file contents
 */
void copy_file(FILE* input_file, FILE* output_file){

	char buffer[BUFFER_SIZE];

	while(fgets(buffer, BUFFER_SIZE, input_file) != NULL){
		fprintf(output_file, "%s", buffer);
	}
}


