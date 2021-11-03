#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>


#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  printf("Statistics for directory: ./\n");

  unsigned long directory_size = 0;
  DIR *d = opendir("./");
  struct dirent *entry;
  entry = readdir(d);
  while (entry != NULL) {
        struct stat entry_info;
        stat(entry->d_name, &entry_info);
        if (entry->d_type == DT_DIR) {
            printf("%s (directory)\n", entry->d_name);
        }
        else {
            printf("%s\n", entry->d_name);
        }
        directory_size += entry_info.st_size;
        entry = readdir(d);
    }
  printf("Total Diectory Size: %d Bytes\n", directory_size);


}
