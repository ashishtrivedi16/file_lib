#ifndef FILEATTR_H
#define FILEATTR_H
// file_attributes.cpp
struct stat64 get_file_attr (const char *);
// mime_type.cpp
const char* get_file_mime_type (const char *);
// linked_list.cpp
struct file_details {
	const char * filename;
	struct stat64 file_attr;
};
bool comp_size(struct file_details p1, struct file_details p2);
bool comp_name(struct file_details p1, struct file_details p2);
bool comp_access_date(struct file_details p1, struct file_details p2);
std::forward_list<struct file_details> create_ll ();
void insert_data_ll (std::forward_list<struct file_details> &list, struct file_details data);
void clear_ll (std::forward_list<struct file_details> &list);
void sort_size(std::forward_list<struct file_details> &list);
void sort_name(std::forward_list<struct file_details> &list);
void sort_access_date(std::forward_list<struct file_details> &list);
#endif