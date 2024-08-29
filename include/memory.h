//
// Created by doonort3 on 23.08.2024.
//

#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

/*
 * Процессор Zilog Z80 мог адресовать до 64 КБ памяти.
 * Однако в это пространство включалась
 * не только оперативная память (RAM), но и постоянная память (ROM),
 * в которой содержалась базовая операционная система.
 * В ZX Spectrum 16 КБ из этих 64 КБ занимала ROM, что оставило лишь 48 КБ под оперативную память.
*/
typedef struct {
    uint8_t data[65536]; // 64 Кб (65536 элементов по 1 байту (uint8_t))
} Memory;

/*
 * Инициализация памяти
 * Мы принимаем ссылку на переменную memory
*/
void memory_init(Memory* memory);

/*
 * Чтение памяти
 * Мы передаём ссылку на memory для дальнейшей работы с полем data
*/
uint8_t memory_read(const Memory* memory, uint16_t address); //

/*
 * Запись в память
 * Мы получаем ссылку на память с которой будем работать и её адрес в 16-битах, так как у нас 16-битная шина памяти
*/
void memory_write(Memory* memory, uint16_t address, uint8_t value);

#endif // MEMORY_H
