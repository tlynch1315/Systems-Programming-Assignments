// Tommy Lynch
// walk.c

#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    
    DIR *dir;
    struct dirent *ent;
    dir = opendir("/afs/nd.edu/user26/tlynch2/cse20289/cse-20289-sp17-assignments/reading10/");
    struct stat statbuf;
    do{
        ent = readdir(dir);
        if(ent){
            printf("%s ", ent->d_name);
            if(!stat(ent->d_name, &statbuf)){
                printf("%u\n", (unsigned int)statbuf.st_size);
            }
            else{
                printf("Stats not available for file\n");
            }
        }
        if(dir == NULL) perror("Could not open directory");
    }
    while(ent);
    closedir(dir);



}
