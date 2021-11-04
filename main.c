#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>



int main(int argc, char *argv[]){

  if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
      return 0;
   }
   else if(argc != 2){
      printf("Enter a directory to scan.\n");
      return 0;
   }
   DIR *d = opendir(argv[1]);
   struct dirent *entry;
   if (d == NULL){
     printf("%s\n", strerror(errno));
     return 0;
   }
  printf("Statistics for directory: %s/\n", argv[1]);

  unsigned long directory_size = 0;

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
