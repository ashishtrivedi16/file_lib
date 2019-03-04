#include <sys/stat.h>

struct stat64 get_file_attr (const char *filename) {
	/* 
	* Returns a struct stat64 with following members :
	* mode_t st_mode - Specifies the mode of the file
	* ino64_t st_ino - The file serial number
	* dev_t st_dev - Identifies the device containing the file
	* nlink_t st_nlink - The number of hard links to the file
	* uid_t st_uid - The user ID of the file’s owner
	* gid_t st_gid - The group ID of the file
	* off64_t st_size - This specifies the size of file in bytes
	* time_t st_atime - This is the last access time for the file
	* unsigned long int st_atime_usec - Fractional part of last access time
	* time_t st_mtime - Time of the last modification to the contents of the file
	* unsigned long int st_mtime_usec - Fractional part of the time of last modification
	* time_t st_ctime - time of the last modification to the attributes of the file
	* unsigned long int st_ctime_usec - Fractional part of the time of last modification   to the attributes
	* blkcnt64_t st_blocks - Amount of disk space that the file occupies, measured in 	   units of 512-byte blocks
	* unsigned int st_blksize - The optimal block size for reading of writing this file,   in bytes
	*/
	
	struct stat64 buf;
	stat64(filename, &buf);
	
	return buf;
}