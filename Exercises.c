#include <stdio.h>
#include <math.h>

// Created by Laust Eberhardt on 11/28/2021.

// This struct represents a bit value of eight bits.
struct bits8 {
    unsigned int b0,b1,b2,b3,b4,b5,b6,b7;
};


/* CONVERTING TO AND FROM C INTEGERS
 *
 * In this task you must implement these three functions:
 *
 * Convert C integer to a bits8:
 * struct bits8 bits8_from_int(unsigned int x);
 *
 * Convert a bits8 to a C integer:
 * unsigned int bits8_to_int(struct bits8 x);
 *
 * Print the bits of a bits8 in the conventional order,
 * with no trailing newline:
 * void bits8_print(struct bits8 v);
 *
 * Implement this function:
 * struct bits8 bits8_add(struct bits8 x, struct bits8 y);
 *
 */


// Answers:

// Prints the bits and nothing more.
void bits8_print(struct bits8 v) {
    printf("%d%d%d%d%d%d%d%d",v.b7,v.b6,v.b5,v.b4,v.b3,v.b2,v.b1,v.b0);
}

// Used to make a default struct bits8, where b0 is last index and lowest value.
struct bits8 create_bits8() {
    struct bits8 x;
    x.b0 = 0;
    x.b1 = 0;
    x.b2 = 1;
    x.b3 = 0;
    x.b4 = 1;
    x.b5 = 1;
    x.b6 = 0;
    x.b7 = 0;
    return x;
}

struct bits8 bits8_from_int(unsigned int x) {
    struct bits8 bits;

    /* Checks if x is higher than the value of the bit,
     * in such case the bit is 1
     * and x will be subtracted.
     */

    if (x>=128) {
        bits.b7 = 1;
        x -= 128;
    } else {bits.b7 = 0;}

    if (x>=64) {
        bits.b6 = 1;
        x -= 64;
    } else {bits.b6 = 0;}

    if (x>=32) {
        bits.b5 = 1;
        x -= 32;
    } else {bits.b5 = 0;}

    if (x>=16) {
        bits.b4 = 1;
        x -= 16;
    } else {bits.b4 = 0;}

    if (x>=8) {
        bits.b3 = 1;
        x -= 8;
    } else {bits.b3 = 0;}

    if (x>=4) {
        bits.b2 = 1;
        x -= 4;
    } else {bits.b2 = 0;}

    if (x>=2) {
        bits.b1 = 1;
        x -= 2;
    } else {bits.b1 = 0;}

    if (x>=1) {
        bits.b0 = 1;
        x -= 1;
    } else {bits.b0 = 0;}

    return bits;
}

unsigned int bits8_to_int(struct bits8 x) {

    unsigned int decimal = 0, bit_value = 2;

    decimal += x.b0 * (unsigned int) pow(bit_value, 0);
    decimal += x.b1 * (unsigned int) pow(bit_value, 1);
    decimal += x.b2 * (unsigned int) pow(bit_value, 2);
    decimal += x.b3 * (unsigned int) pow(bit_value, 3);
    decimal += x.b4 * (unsigned int) pow(bit_value, 4);
    decimal += x.b5 * (unsigned int) pow(bit_value, 5);
    decimal += x.b6 * (unsigned int) pow(bit_value, 6);
    decimal += x.b7 * (unsigned int) pow(bit_value, 7);

    return decimal;
}


struct bits8 bits8_add(struct bits8 x, struct bits8 y) {
   return bits8_from_int(bits8_to_int(x) + bits8_to_int(y));
}

// This main will coordinate the program from the different functions of this class.
int main() {
    struct bits8 bits = create_bits8();

    printf("\n");
    bits8_print(bits8_from_int(bits8_to_int(bits)));

    printf("\n\n");
    bits8_print(bits8_add(bits,bits));

    printf("\n");
    // Will in this case end in a success.
    return 0;
}

