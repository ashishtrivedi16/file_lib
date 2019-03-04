#ifndef FILEATTR_H
#define FILEATTR_H
// file_attributes.cpp
struct stat64 get_file_attr (const char *);
// mime_type.cpp
const char* get_file_mime_type (const char *);
// linked_list.cpp
std::forward_list<std::pair<const char *, struct stat64> > create_ll ();
void insert_data_ll (std::forward_list<std::pair<const char *, struct stat64> > &list, std::pair<const char *, struct stat64> data);
void clear_ll (std::forward_list<std::pair<const char *, struct stat64> > &list);
bool comp_size(std::pair<const char *, struct stat64> p1, std::pair<const char *, struct stat64> p2);
bool comp_name(std::pair<const char *, struct stat64> p1, std::pair<const char *, struct stat64> p2);
bool comp_access_date(std::pair<const char *, struct stat64> p1, std::pair<const char *, struct stat64> p2);
void clear_ll (std::forward_list<std::pair<const char *, struct stat64> > &list);
void sort_size(std::forward_list<std::pair<const char *, struct stat64> > &list);
void sort_name(std::forward_list<std::pair<const char *, struct stat64> > &list);
void sort_access_date(std::forward_list<std::pair<const char *, struct stat64> > &list);
#endif