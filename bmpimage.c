#include<stdio.h>
#include<bmp.h>
#include<bmp_functions.c>
#include<bmp_filters.c>
#include<stdlib.h>

int main(){

    if(!bmp_init()){
        printf("Initialisation Failed\n");
        return 0;
    }

    int option;

    while(1){
        printf("1. Grayscale\n2. Brightness Adjustment\n3. Colour Inversion\n4. Save\n5. Exit\nEnter an option: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            {
                gray_scale(pixel_buffer,bmp_header.width,bmp_header.height);
                break;
            }

            case 2:
            {
                int brightness;
                printf("Enter brightness amount(+ve to increase,-ve to decrese): ");
                scanf("%d",&brightness);

                brightness_adjust(pixel_buffer,bmp_header.width,bmp_header.height,brightness);
                break;
            }

            case 3:
            {
                char colour_tag;
                printf("Enter the colour to invert to: ");
                scanf(" %c",&colour_tag);

                colour_channel(pixel_buffer,bmp_header.width,bmp_header.height,colour_tag);
                break;
            }

            case 4:
            {
                fwrite(&bmp_header,sizeof(struct BMPheader),1,dest);

                fseek(dest,bmp_header.pixel_offset,SEEK_SET);

                fwrite(pixel_buffer,1,pixel_size,dest);

                break;
            }

            case 5:
            {
                free(pixel_buffer);
                fclose(src);
                fclose(dest);

                return 0;

            }
        }
    }

return 0;
}
