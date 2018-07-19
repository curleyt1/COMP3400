#include <stdio.h>
#include <stdlib.h>
//
// Compile with:  gcc -o simpleCcgi simpleCcgi.c
//

main(int argc, char **argv) {
	FILE *fd =  NULL;
	int p=0;
	char buf[1024];

	printf( "<HTML>\n");
	printf( "<HEAD>\n");
	printf( "<TITLE>A simple cgi script</TITLE>\n");
	printf( "</HEAD>\n");
	printf( "<BODY bgcolor=\"#dddddd\" text=\"#000000\">\n");

	printf( "<H1>This is a simple cgi script written in C</H1>\n");


	printf( "<table border=1>\n");
		printf( "<tr><td>\n");
			printf( "<font color=red><B>");

			if( (fd = popen("/bin/date", "r")) == NULL) {
				perror("popen");
				exit(-1);
			}

			while ( fgets(buf, 1024, fd) != NULL) {
				printf("%s", buf);
			}

			pclose(fd);

			printf("</B></font>\n");
		printf( "</td></tr>\n");





		// the cal program
		printf( "<tr><td><pre>\n");
			if( (fd = popen("/bin/cal", "r")) == NULL) {
				perror("popen");
				exit(-1);
			}

			p=0;
			while ( fgets(buf, 1024, fd) != NULL) {
				if( p == 0 ) {
					p++;
					printf("<font color=green><B>%s</B></font>", buf);
				}
				else {
					printf("%s", buf);
				}
			}

			pclose(fd);

		printf( "</pre></td></tr>\n");






		printf( "<tr><td>\n");
		printf( "This is link to Dr. Deligiannidis' <A HREF=\"http://www.cs.uga.edu/~ldeligia\">home page</A>.\n");
		printf( "</td></tr>\n");

		printf( "</table>\n");



	printf("</BODY>\n");
	printf("</HTML>\n");
}
