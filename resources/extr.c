#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BSIZE 2048


struct mdata
{
    char name[255];
    FILE *fp;
    int size;
    int nsize;
    int ssize;
    struct mdata *next;
};

struct mdata *mhead = NULL, *current = NULL;

int min(int x, int y)
{
    if(x < y) return x;
    else return y;
}
int getsize(FILE *fp)
{
    int size = 0;
    fseek(fp, 0L, SEEK_END);
    size  = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return size;
}

int add(char *name, int size)
{
    char ntemp[255];
    struct mdata *newm;
    newm = (struct mdata *)malloc(sizeof(struct mdata));
    strcpy(newm->name, name);
    newm->size = size;
    newm->nsize = strlen(name);
    sprintf(ntemp, "%d", newm->size);
    newm->ssize = strlen(ntemp);
    newm->next = NULL;
    printf("File %s is being processed...\n", name);
    if(mhead == NULL)
    {
        mhead = newm;
        current = newm;
    }
    else
    {
        current->next = newm;
        current = newm;
    }
	return (0);
}

int readh(FILE *fp1)
{
    int i = 0, j= 1 ;
    int hsize = 0, size = 0;
    int byte;
    char shsize[50];
    char name[255];
    char ssize[50];
    while((byte = fgetc(fp1))!='/')
    {
        shsize[i] = (char)byte;
        i++;
    }
    shsize[i] = '\0';
    hsize = atoi(shsize);
    hsize += strlen(shsize);
    printf("The total size of header is %d.\n", hsize);
    printf("Contents starts at %dth byte.\n", hsize);
    //COLLECT NAMES AND SIZES
    j = strlen(shsize)+1;
    while(j <= hsize-1)
    {
        i = 0;
        while((byte = fgetc(fp1))!='/')
        {
            name[i++] = byte;
            j++;
        }
        j++;
        name[i] = '\0';
        i = 0;
        while((byte = fgetc(fp1))!='/')
        {
            ssize[i++] = byte;
            j++;
        }
        j++;
        ssize[i] = '\0';
        size = atoi(ssize);
        printf("File '%s' with size %d added to list.\n", name, size);
        add(name, size);
        printf("File '%s' processing completed.\n", name);
    }
    printf("File meta data collection successfully completed.\n");
	return (0);
}

int main(int argc, char** argv)
{
    char block[BSIZE];
    char stsize[5];
    char shsize[100];
    int rsize = 0;
    int tnsize = 0, tssize = 0, hsize = 0, scount = 0;
    int totsize = 0;
    int unreadcount = 0;
    struct mdata *ptr;
    FILE *fpar, *fp;

    //COLLECTING HEADER
    printf("Opening file %s...\n", argv[1]);
    fpar = fopen(argv[1], "r+");
    if(fpar == NULL)
    {
        printf("Error opening file %s.\n", argv[1]);
    }
    readh(fpar);
    ptr = mhead;
    lseek((int)fpar, hsize+1, SEEK_SET);
    while(ptr != NULL)
    {
        totsize = 0;
        printf("Creating file %s...\n", ptr->name);
        fp = fopen(ptr->name, "w+");
        printf("Writing %d bytes of %s...\n", ptr->size, ptr->name);
        unreadcount = ptr->size;
        while(unreadcount > 0)
        {
            if(sizeof(block)>= unreadcount)
            {
                rsize = fread(block, 1, unreadcount, fpar);
            }
            else
            {
                rsize = fread(block, 1, sizeof(block), fpar);
            }
            unreadcount -= rsize;
            totsize += rsize;
            fwrite(block, 1, rsize, fp);
        }
        printf("Written %d bytes to file %s.\n", totsize, ptr->name);
        ptr = ptr->next;
    }
    printf("Extraction completed.\n");
    fclose(fpar);
    return 0;
}
