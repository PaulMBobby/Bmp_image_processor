# BMP Image Processing Engine

A C-based BMP image processing engine featuring a CLI menu, luminance-based grayscale conversion, dynamic brightness adjustment with clamping, and RGB channel extraction. Built entirely with the C Standard Library to manipulate binary BMP pixel data.

---

# Overview

The C-BMP Image Processing Engine is a bare-metal, modular command-line application designed to read, manipulate, and write 24-bit uncompressed Bitmap (BMP) images. Built entirely without third-party graphics libraries, this project demonstrates a strong understanding of low-level file I/O, dynamic memory management, byte-level data parsing, and pixel-based image processing.

By operating directly on the binary pixel array, the engine performs efficient image transformations while maintaining memory safety and preserving the BMP file format.

---

# Features

## Luminance-Based Grayscale

Converts full-color images to grayscale using the standard luminance formula:

```text
0.2126R + 0.7152G + 0.0722B
```

This weighting closely matches human visual perception by giving greater importance to green and less to blue.

## Dynamic Brightness Adjustment

Adjusts image brightness while safely clamping pixel values to the valid range (0–255), preventing integer overflow and color distortion.

## RGB Channel Extraction

Extracts individual Red, Green, or Blue channels by preserving the selected channel and masking the remaining channels.

## Interactive CLI

Provides a menu-driven command-line interface that allows users to:

- Load BMP images
- Apply multiple filters sequentially
- Preview available operations
- Save the modified image

## BMP Header Validation

Validates the BMP file before processing by ensuring:

- Valid BMP signature
- 54-byte BMP header
- 24-bit color depth
- Uncompressed image format

This prevents invalid files from being loaded and avoids undefined behavior.

---

# Project Structure

```
.
├── main.c
├── bmp.h
├── bmp_functions.c
├── bmp_filters.c
└── README.md
```

### `bmp.h`

Defines the packed BMP header structures used throughout the project, ensuring the correct 54-byte layout required by the BMP specification.

### `bmp_functions.c`

Implements the core image processing pipeline, including:

- File loading
- File saving
- Header validation
- Memory allocation
- Memory cleanup

### `bmp_filters.c`

Contains all image-processing algorithms, including:

- Grayscale conversion
- Brightness adjustment
- RGB channel extraction
- BMP row padding (stride) calculations

### `main.c`

Implements the interactive command-line interface and coordinates the complete image-processing workflow.

---

# Getting Started

## Prerequisites

- GCC or Clang
- A 24-bit uncompressed BMP image

---

## Compilation

Clone the repository:

```bash
git clone https://github.com/yourusername/your-repo-name.git

cd your-repo-name
```

Compile the project:

```bash
gcc main.c bmp_functions.c bmp_filters.c -o bmp_engine
```

If you're using GCC and want additional warnings enabled:

```bash
gcc -Wall -Wextra -std=c11 main.c bmp_functions.c bmp_filters.c -o bmp_engine
```

---

# Usage

Run the executable:

```bash
./bmp_engine
```

The program will guide you through the following steps:

1. Enter the input BMP filename.
2. Select an image-processing operation.
3. Apply one or more filters as desired.
4. Enter the output filename.
5. Save the processed image.

---

# Processing Pipeline

```
Input BMP
     │
     ▼
Header Validation
     │
     ▼
Load Pixel Data
     │
     ▼
Apply Selected Filter(s)
     │
     ▼
Write Output BMP
```

---

# Technologies Used

- C
- C Standard Library
- File I/O
- Dynamic Memory Management
- Binary Data Processing
- Image Processing
- Command-Line Interface (CLI)

---

# Concepts Demonstrated

- Binary file parsing
- BMP file format handling
- Low-level file operations
- Pointer arithmetic
- Dynamic memory allocation
- Memory management
- Pixel manipulation
- Image processing algorithms
- Modular software architecture
- Defensive programming

---

# Supported BMP Format

| Property | Supported |
|----------|-----------|
| File Format | BMP |
| Compression | None (BI_RGB) |
| Color Depth | 24-bit |
| Header Size | 54 bytes |

---

# Future Improvements

- Image rotation
- Horizontal and vertical flipping
- Image scaling
- Blur filter
- Sharpen filter
- Edge detection
- Negative filter
- Sepia filter
- Histogram generation
- Batch image processing

---

# License

This project is intended for educational and learning purposes.

