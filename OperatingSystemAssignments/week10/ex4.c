#include "string.h"
#include "stdio.h"
#include "dirent.h"
#include "sys/stat.h"
#include "stdlib.h"

struct dirent *entry;
struct stat buff;
struct file {
int counter;
long inode;
char *files;
};

char char *str1, char *str2 {
char *res = malloc(strlen(str1) + strlen(str2) + 1);
strcpy(res, str1);
memcpy(res + strlen(str1), str2, strlen(str2) + 1);
return res;
}

int main() {
DIR *dir = opendir("tmp");

if (dir == NULL) {
printf("Unsuccessfully opened\n");
return 1;
}

struct file files[100];
for (int i = 0; i < 100; i++) {
files[i].counter = 0;
files[i].files = NULL;
files[i].inode = 0;
}

int counter = 0, i;
while ((entry = readdir(dir)) != NULL) {
char *dest = concat("tmp/", entry->d_name);
stat(dest, &buff);

for (i = 0; i < counter; i++) {
if (files[i].inode == buff.st_ino) {
files[i].counter++;
files[i].files = concat(files[i].files, entry->d_name);
}
}
if (i == counter) {
files[counter].files = entry->d_name;
files[counter].counter = 1;
files[counter].inode = buff.st_ino;
counter++;
}
free(dest);
}

for (i = 0; i < counter; i++)
if (files[i].counter > 1) printf("I-node: %lu; files: %s\n", files[i].inode, files[i].files);
closedir(dir);
return 0;
} 
