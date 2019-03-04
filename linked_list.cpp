#include <forward_list>
#include <sys/stat.h>
#include <string.h>

struct file_details {
	const char * filename;
	struct stat64 file_attr;
};

bool comp_size(struct file_details p1, struct file_details p2) {
	return p1.file_attr.st_size < p2.file_attr.st_size;
}

bool comp_name(struct file_details p1, struct file_details p2) {
	if (strcmp(p1.filename, p2.filename) != 0)
		return true;
	else
		return false;
}

bool comp_access_date(struct file_details p1, struct file_details p2) {
	return p1.file_attr.st_atime < p2.file_attr.st_atime;
}

std::forward_list<struct file_details> create_ll () {
	std::forward_list<struct file_details> list;
	return list;
}

void insert_data_ll (std::forward_list<struct file_details> &list, struct file_details data) {
	list.push_front(data);
	return;
}

void clear_ll (std::forward_list<struct file_details> &list) {
	list.clear();
	return;
}

void sort_size(std::forward_list<struct file_details> &list) {
	list.sort(comp_size);
	return;
}

void sort_name(std::forward_list<struct file_details> &list) {
	list.sort(comp_name);
	return;
}

void sort_access_date(std::forward_list<struct file_details> &list) {
	list.sort(comp_access_date);
	return;
}
