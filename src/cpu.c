//
// Created by doonort3 on 23.08.2024.
//

#include "cpu.h"
#include <stdio.h>

void cpu_init(Z80* cpu)
{
    cpu->pc = 0x0000;   // Устанавливаем 16-битный адрес для программного счётчика
    cpu->a = 0x00;      // Устанавливаем 8-битный адрес для регистра a
    cpu->f = 0x00;      // Аналогично для регистра флага
}

/*
 * Продолжаю свой рассказ о строении процессора
 * Цикл работы любого процессора можно разбить на 3 основных этапа:
 * 1. Fetch - Получение команды из оперативной памяти;
 * 2. Decode - Декодирование полученной команды;
 * 3. Execute - Выполнение команды;
 * Этот цикл так и называется - "fetch-decode-execute cycle"
*/
void cpu_execute(Z80* cpu, const Memory* memory)
{
    const uint8_t opcode = memory_read(memory, cpu->pc); // Fetch

    switch (opcode) { // Decode
        case 0x00:
            printf("Executed NOP (No Operation)\n"); // Execute
            cpu->pc++; // Прибавляем к программному счётчику +1 для перехода к выполнению следующей инструкции
            break;
        default:
            printf("Unknown instruction: %02X\n", opcode);
        break;
    }
}
