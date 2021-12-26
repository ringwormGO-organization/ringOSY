// Includes
#include "print.h"

// Screen size
const static size_t NUM_COLS = 80; // Screen Colomns
const static size_t NUM_ROWS = 25; // Screen Rows

// Charator information
struct Char {
    uint8_t character;
    uint8_t color;
};

// Screen buffer address
struct Char* buffer = (struct Char*) 0xb8000;

#define VGA_MEMORY (uint8_t*)0xb8000
#define VGA_WIDTH 80

// Cursor information
size_t col = 0; // Current cursor coloum
size_t row = 0; // Current cursor row

// Text Color
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

// Clear a row
void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

// Clear the entire screen
void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void print_str(const char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }

        print_char(character);
    }
}

void print_str2(const char* str) {
    uint8_t* charPtr = (uint8_t*)str;
  uint16_t index = CursorPosition;
  while(*charPtr != 0)
  {
    switch (*charPtr) {
      case 10:
        index+= VGA_WIDTH;
        break;
      case 13:
        index -= index % VGA_WIDTH;
        break;
      default:
      *(VGA_MEMORY + index * 2) = *charPtr;
      *(VGA_MEMORY + index * 2 + 1) = color;
      index++;
    }

    charPtr++;
  }
  SetCursorPosition(index);
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}


uint16_t CursorPosition;
void SetCursorPosition(uint16_t position){

  outb(0x3D4, 0x0F);
  outb(0x3D5, (uint8_t)(position & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (uint8_t)((position >> 8) & 0xFF));

  CursorPosition = position;
}

uint16_t PositionFromCoords(uint8_t x, uint8_t y){
  return y * VGA_WIDTH + x;
}