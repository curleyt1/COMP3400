#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

/*
 * Returns TRUE is the file is a regular file (not a directory or link or char special device etc.)
 * Otherwise, it returns FALSE
 * links are ok, as long as they point to executables.
 */
int IsFileExecutable(char *file) {
	struct stat buf;

	if( stat(file, &buf) != 0 ) {
		perror("stat()");
                exit(-1);
        }

        if( S_ISREG(buf.st_mode) ) {			// is the file a regular file ?
		if( buf.st_mode & S_IEXEC ) 		// is the file executable by the the owner ?
			return TRUE;
	}

	return FALSE;
}


/*
 *
 */
main(int argc, char **argv) {
	int b;

	if( argc != 2 ) {
		fprintf(stderr, "USAGE: %s <file_name>\n", argv[0]);
		exit(-1);
	}

	b = IsFileExecutable(argv[1]);

	if( b == TRUE ) 	printf("[EXECUTABLE]         The file %s is a regular file and is executable.\n", argv[1]);
	else 			printf("[NOT and executable] The file %s is either not a regular file or not an executable.\n", argv[1]);

}
