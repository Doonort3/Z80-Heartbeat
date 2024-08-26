//
// Created by doonort3 on 23.08.2024.
//

#include "memory.h"
#include <string.h>

void memory_init(Memory* memory)
{
    memset(memory->data, 0, sizeof(memory->data)); // Заполняем поле типа unsigned int размером 16 бит data в структуре memory нулями
}

uint8_t memory_read(const Memory* memory, const uint16_t address)
{
    return memory->data[address]; // Возвращаем данные по переданному адресу в памяти
}

void memory_write(Memory* memory, const uint16_t address, const uint8_t value)
{
    memory->data[address] = value; // Записываем значение по переданному адресу
}
