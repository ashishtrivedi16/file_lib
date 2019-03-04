#include <forward_list>
#include <sys/stat.h>
#include <string.h>

bool comp_size(std::pair<const char *, struct stat64> p1, std::pair<const char *, struct stat64> p2) {
	return p1.second.st_size < p2.second.st_size;
}

bool comp_name(std::pair<const char *, struct stat64> p1, std::pair<const char *, struct stat64> p2) {
	if (strcmp(p1.first, p2.first) != 0)
		return true;
	else
		return false;
}

bool comp_access_date(std::pair<const char *, struct stat64> p1, std::pair<const char *, struct stat64> p2) {
	return p1.second.st_atime < p2.second.st_atime;
}

std::forward_list<std::pair<const char *, struct stat64> > create_ll () {
	std::forward_list<std::pair<const char *, struct stat64> > list;
	return list;
}

void insert_data_ll (std::forward_list<std::pair<const char *, struct stat64> > &list, std::pair<const char *, struct stat64> data) {
	list.push_front(data);
	return;
}

void clear_ll (std::forward_list<std::pair<const char *, struct stat64> > &list) {
	list.clear();
	return;
}

void sort_size(std::forward_list<std::pair<const char *, struct stat64> > &list) {
	list.sort(comp_size);
	return;
}

void sort_name(std::forward_list<std::pair<const char *, struct stat64> > &list) {
	list.sort(comp_name);
	return;
}

void sort_access_date(std::forward_list<std::pair<const char *, struct stat64> > &list) {
	list.sort(comp_access_date);
	return;
}
