#include <stdio.h>
#include <string>

const char * get_file_mime_type (const char *filename) {
	/*
	* This function uses popen - pipe to/from shell command.
	* FILE *popen(const char *command, const char *type);
	* On macOS use : file -I -b "filename" or file --mime -b "filename"
	* On Linux use : file -i -b "filename"
	*/
	
	FILE *fp;
	std::string file_name = filename;
	std::string command_string = "file -I -b " + file_name;
	const char *command = command_string.c_str();
	
	char *buf = (char *)malloc(100);
	std::string output;
	fp = popen(command, "r");
	
	while (fscanf(fp, "%s", buf) == 1)
		output += buf;
	
	pclose(fp);
		
	return output.c_str();
}