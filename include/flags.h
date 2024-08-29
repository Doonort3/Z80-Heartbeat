//
// Created by shirakibaka on 29.08.2024.
//
#include <stdint.h>

#ifndef FLAGS_H
#define FLAGS_H

#define FLAG_CARRY     0x01  // 00000001 If the operation results in a transfer to a higher digit
#define FLAG_SUBTRACT  0x02  // 00000010 Add/subtract flag
#define FLAG_PARITY    0x04  // 00000100 Flag indicating even/oddness of the number as a result of arithmetic operations.
#define FLAG_UNUSED1   0x08  // 00001000 Not used !
#define FLAG_HALFCARRY 0x10  // 00010000 A flag that indicates a half-step in some arithmetic operations
#define FLAG_UNUSED2   0x20  // 00100000 Not used !
#define FLAG_ZERO      0x40  // 01000000 If the result of the operation is zero
#define FLAG_SIGN      0x80  // 10000000 If the result of the operation is negative

void set_flag(uint8_t flag);
void clear_flag(uint8_t flag);
uint8_t get_flag_set(uint8_t flag);     // Return flag state (0 or 1)

void update_zero_flag(uint8_t result);
void update_sign_flag(uint8_t result);
#endif //FLAGS_H
