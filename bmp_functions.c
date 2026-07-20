#include<stdio.h>
#include<bmp.h>
#include<stdint.h>
#include<stdlib.h>

struct BMPheader bmp_header;

FILE *src,*dest;

uint32_t pixel_size;
uint8_t *pixel_buffer;

int bmp_checker(struct BMPheader *bmp){
    
    if(bmp->sign != 0x4D42){
        return 1;
    }
    if(bmp->bit_per_pixel != 24){
        return 1;
    }
    if(bmp->compression != 0){
        return 1;
    }

    return 0;
}

uint32_t pixel_size_cal(struct BMPheader *bmp){
    return bmp->file_size - bmp->pixel_offset;
}

int bmp_init(){

    char filename[100];
    char destination[100];

    printf("Enter file name to read: ");
    scanf("%[^\n]",filename);

    printf("Enter file name to save: ");
    scanf(" %[^\n]",destination);

    src = fopen(filename,"rb");
    dest = fopen(destination,"wb");

    if(src==NULL){
        printf("File not opened!\n");
        return 0;
    }

    if(fread(&bmp_header,sizeof(struct BMPheader),1,src)!=1){
        printf("Error, could not read header!\n");
        return 0;
    }

    if(bmp_checker(&bmp_header)){
        printf("Invalid FIle, could not process!\n");
        return 0;
    };

    pixel_size = pixel_size_cal(&bmp_header);

    pixel_buffer = (uint8_t *)malloc(pixel_size);

    if(pixel_buffer==NULL){
        printf("Memory failed to allocate\n");
        return 0;
    }

    if(fseek(src,bmp_header.pixel_offset,SEEK_SET)!=0){
        printf("Invalid offset!\n");
        return 0;
    }

    size_t bytes_read = fread(pixel_buffer,1,pixel_size,src);

    if(bytes_read != pixel_size){
        printf("Invalid size of pixel array!\n");
        return 0;
    }

    return 1;
}



