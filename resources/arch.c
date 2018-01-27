#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int getsize(FILE *fp)
{
    int size = 0;
    fseek(fp, 0L, SEEK_END);
    size  = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return size;
}

int add(char *name)
{
    FILE *fp;
    char ntemp[255];
    struct mdata *newm;
    newm = (struct mdata *)malloc(sizeof(struct mdata));
    strcpy(newm->name, name);
    fp = fopen(name, "r+");
    newm->fp = fp;
    newm->size = getsize(fp);
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

int preproc(int argc, char** argv)
{
    int i;

    for(i = 1; i <= argc-2; i++)
    {
        add(argv[i]);
    }
	return (0);
}

int main(int argc, char** argv)
{
    char block[BSIZE];
    char stsize[5];
    char shsize[100];
    int rsize = 0;
    int tnsize = 0, tssize = 0, hsize = 0, scount = 0;
    struct mdata *ptr;
    FILE *fpar, *fp;

    //CREATE HEADER
    printf("Pre-processing the files to collect meta data...\n");
    preproc(argc, argv);
    printf("Pre-processing completed.\n");
    printf("Compiling header information.\n");
    fpar = fopen(argv[argc-1], "w+");
    ptr = mhead;
    while(ptr != NULL)
    {
        tnsize += ptr->nsize;
        tssize += ptr->ssize;
        ptr = ptr->next;
        scount +=2;
    }
    hsize = tnsize+tssize+scount+1;
    printf("Total length of file names is %d\n", tnsize);
    printf("Total length of file sizes is %d\n", tssize);
    printf("Total size of header except file size is %d.\n", hsize);
    sprintf(shsize, "%d/", hsize); //10 bytes of header size
    fwrite(shsize, 1, strlen(shsize), fpar);
    ptr = mhead;
    while(ptr != NULL)
    {
        fwrite(ptr->name, 1, ptr->nsize, fpar);
        fwrite("/", 1, 1, fpar);
        sprintf(stsize, "%d", ptr->size);
        fwrite(stsize, 1, ptr->ssize, fpar);
        fwrite("/", 1, 1, fpar);
        ptr = ptr->next;
    }
    printf("The header created and written to archieve file.\n");
    //CREATE BODY
    ptr = mhead;
    while(ptr != NULL)
    {
        fp = ptr->fp;
        while((rsize = fread(block, 1, sizeof(block), fp)))ls -
        {
            fwrite(block, 1, rsize, fpar);
        }
        ptr = ptr->next;
    }
    printf("Contents of all files written to archieve file.\n");
    fclose(fpar);
    return 0;
}
