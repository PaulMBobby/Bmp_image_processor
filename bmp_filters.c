#include<stdio.h>
#include<stdint.h>


void gray_scale(uint8_t *buffer,uint32_t width, uint32_t height){

    int stride = (width * 3) + ((4 - ((width*3)%4)) % 4);

    for(int i=0;i<height;i++){

        for(int j=0;j<width;j++){

            int index = (i*stride) + (j*3);

            uint8_t blue = buffer[index + 0];
            uint8_t green = buffer[index + 1];
            uint8_t red = buffer[index + 2];

            uint8_t gray = (uint8_t)(0.2126 * red + 0.7152 * green + 0.0722 * blue);

            buffer[index + 0] = gray;
            buffer[index + 1] = gray;
            buffer[index + 2] = gray;

        }

    }
    
}

uint8_t brightness_value(uint8_t colour, int brightness){

    int new_val = (int)colour + brightness;

    if(new_val > 255){
        return 255;
    }
    if(new_val < 0){
        return 0;
    }

    return (uint8_t)new_val;
}

void brightness_adjust(uint8_t *buffer,uint32_t width,uint32_t height, int brightness){

    int stride = (width * 3) + ((4 - ((width*3)%4)) % 4);

    for(int i=0;i<height;i++){
        
        for(int j=0;j<width;j++){

            int index = (i*stride) + (j*3);

            uint8_t blue = buffer[index + 0];
            uint8_t green = buffer[index + 1];
            uint8_t red = buffer[index + 2];

            buffer[index + 0] = brightness_value(blue,brightness);
            buffer[index + 1] = brightness_value(green,brightness);
            buffer[index + 2] = brightness_value(red,brightness);

        }

    }

}

void colour_channel(uint8_t *buffer,uint32_t width,uint32_t height,char colour_tag){

    int stride = (width * 3) + ((4 - ((width*3)%4)) % 4);

    for(int i=0;i<height;i++){

        for(int j=0;j<width;j++){

            int index = (i*stride) + (j*3);

            uint8_t blue = buffer[index + 0];
            uint8_t green = buffer[index + 1];
            uint8_t red = buffer[index + 2];

            if(colour_tag == 'R'){
                blue = 0;
                green = 0;
            }
            else if(colour_tag == 'G'){
                red = 0;
                blue = 0;
            }
            else if(colour_tag == 'B'){
                red = 0;
                green = 0;
            }
            else if(colour_tag == 'W'){
                red = 255;
                blue = 255;
                green = 255;
            }
            else if(colour_tag == 'D'){
                red = 0;
                blue = 0;
                green = 0;
            }

            buffer[index+0] = blue;
            buffer[index+1] = green;
            buffer[index+2] = red;

        }

    }

}

