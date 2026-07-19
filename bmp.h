#ifndef BMP_H
#define BMP_H

#include<stdint.h>

#pragma pack(push,1)

struct BMPheader{

    uint16_t sign;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixel_offset;
    uint32_t dib_header_size;
    uint32_t width;
    uint32_t height;
    uint16_t colour_plane;
    uint16_t bit_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    uint32_t horizontal_resolution;
    uint32_t vertical_resolution;
    uint32_t colour_palette;
    uint32_t important_colours;

};

#pragma pack(pop)


#endif

































