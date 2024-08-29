//
// Created by doonort3 on 29.08.2024.
//

/*
 * В данном коде мы реализуем функции, связанные с работой с флагами, используя побитовые операции (Bitwise)
 */
#include "../include/flags.h"

uint8_t flags = 0;

void set_flag(const uint8_t flag)
{
    flags |= flag;  // Set flag to 1
}

void clear_flag(const uint8_t flag)
{
    flags &= ~flag; // Set flag to 0
}

uint8_t get_flag_set(const uint8_t flag)
{
    return flags & flag;    // Bitwise OR. Compares flags. In case of a match, returns 1
}

void update_zero_flag(const uint8_t result)
{
    result == 0 ? set_flag(FLAG_ZERO) : clear_flag(FLAG_ZERO); // If result = 0 -> set_flag to zero, else clear flag
}

void update_sign_flag(const uint8_t result)
{
    result & 0x80 ? set_flag(FLAG_SIGN) : clear_flag(FLAG_SIGN);
}
