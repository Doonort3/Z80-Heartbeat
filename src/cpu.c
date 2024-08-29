//
// Created by doonort3 on 23.08.2024.
//

#include "../include/cpu.h"
#include <stdio.h>

void cpu_init(Z80* cpu)
{
    // Main register set (8 bit)
    cpu->A, cpu->F, cpu->B, cpu->C,
    cpu->D, cpu->E, cpu->H, cpu->L = 0x00;

    // Alternative register set (8 bit)
    cpu->A_, cpu->F_, cpu->B_, cpu->C_,
    cpu->D_, cpu->E_, cpu->H_, cpu->L_ = 0x00;

    // Special registers (16 bit/8 bit)
    cpu->PC = 0x0000;
    cpu->SP = 0x0000;
    cpu->IX = 0x0000;
    cpu->IY = 0x0000;
    cpu->I = 0x00;
    cpu->R = 0x00;
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
    const uint8_t opcode = memory_read(memory, cpu->PC); // Fetch

    switch (opcode) { // Decode
        case 0x00:
            cpu->SP = opcode;
            printf("Executed NOP (No Operation)\n"); // Execute
            cpu->PC++; // Прибавляем к программному счётчику +1 для перехода к выполнению следующей инструкции
            break;
        default:
            printf("Unknown instruction: %02X\n", opcode);
        break;
    }
}
