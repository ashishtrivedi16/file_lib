#include <iostream>
#include <forward_list>
#include <string>
#include <sys/stat.h>
#include "file.h"

int main(void) {
	// Creeating a linked list to store files and data
	std::forward_list<struct file_details> list = create_ll();
	
	// Adding files and attribute data to the ll
	for(int i = 1; i <= 5; i++){
		
		std::string name = "files/" + std::to_string(i) + ".rtf";
		
		const char* filename = name.c_str();
		
		struct stat64 data_attr = get_file_attr(filename);
		
		struct file_details new_data;
		new_data.filename = filename;
		new_data.file_attr = data_attr;
		
		insert_data_ll(list, new_data);
		
	}
	
	std::cout << std::endl;
	
	// Prints the mime type of the file
	for(auto i = list.begin(); i != list.end(); i++){
		std::cout << get_file_mime_type(i->filename) << " " << i->file_attr.st_size << std::endl;
	}
	std::cout << std::endl;
	
	// Sorting according to name
	sort_name(list);
	for(auto j = list.begin(); j != list.end(); j++)
			std::cout << j->filename << " " << j->file_attr.st_size << " " << j->file_attr.st_ino  << std::endl;
	std::cout << std::endl;
	
	// Sorting according to size
	sort_size(list);
	for(auto j = list.begin(); j != list.end(); j++)
			std::cout << j->filename << " " << j->file_attr.st_size << " " << j->file_attr.st_ino  << std::endl;
	std::cout << std::endl;
	
	// Sorting according to access date
	sort_access_date(list);
	for(auto j = list.begin(); j != list.end(); j++)
			std::cout << j->filename << " " << j->file_attr.st_size << " " << j->file_attr.st_atime  << std::endl;
	std::cout << std::endl;
	
	return 0;
}