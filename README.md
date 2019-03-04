#### To test the project run the following code

```
g++ -c file_attributes.cpp
g++ -c mime_type.cpp
g++ -c linked_list.cpp
```

```
ar cr libfile.a file_attributes.o mime_type.o linked_list.o
```
```
g++ -o client client.cpp -L. -lfile
```
