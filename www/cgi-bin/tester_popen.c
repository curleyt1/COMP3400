////////////////////////////////////////////////////////////////////
// This program opens a pipe to the shell, executes a command, and
// we read the output of the command into this program (line by line).
// Then we print the output on the screen.
//
// Compile:  gcc -o tester_popen tester_popen.c
//
////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#define MAXLINELENGTH 256

main(int argc, char **argv) {
	FILE *fp;
	char line[MAXLINELENGTH];


	/*
	 * Open a pipe to the "/bin/ls -l" command.
	 * read the man page for popen()
	 */
	if( (fp = popen("/bin/ls -l", "r")) == NULL) {
		perror("popen");
		exit(-1);
	}


	/*
	 * Read MAXLINELENGTH characters from the pipe and print
	 * the buffer on the screen.
	 * fgets terminates the string with the null character.
	 * read the man page for fgets()
	 */
	while ( fgets(line, MAXLINELENGTH, fp) != NULL) {
		printf("%s", line);
	}

	/*
	 * We are done with the pipe, close it now.
	 */
	pclose(fp);

}
