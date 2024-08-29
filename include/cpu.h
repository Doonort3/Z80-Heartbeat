//
// Created by doonort3 on 23.08.2024.
//

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "../include/memory.h"

/*
 * Немного о строении 8-битного процессора Z80:
 *
 * Есть поддержка 16-битных регистров для адресации памяти
 * Регистры общего назначения (8-битные):
 * Главный набор A, B, C, D, E, H, L; Но могут объединяться в 16-битные пары - BC, DE, HL и тд.
 * Регистр флагов F хранит информацию о состоянии процессора;
 * SP - хранит указатель на адрес следующего свободного места в стеке;
 * PC - Указывает, какую инструкцию нужно выполнять следующей;
 *
 * Стек - структура данных реализуемая стратегию LIFO (Последним вошёл, первым вышел)
 * Представьте тарелки, мы не можем достать последнюю тарелку,
 * пока не выложим те, что над ней и так же кладём и берём тарелки сверху
 *
 * Регистры SP и PC являются 16-битными;
 * I и R регистры для обработки прерываний.
 * И многие другие.
*/
typedef struct {
    uint8_t A;          // Accum
    uint8_t F;          // Flags

    /* Main register set */
    uint8_t B, C;
    uint8_t D, E;
    uint8_t H, L;

    /* Alternative register set */
    uint8_t A_, F_;
    uint8_t B_, C_;
    uint8_t D_, E_;
    uint8_t H_, L_;

    uint16_t SP;        // Stack Pointer
    uint16_t PC;        // Program Counter
    uint16_t IX, IY;    // Register Indexers

    uint8_t I;          // Interrupt Vector
    uint8_t R;          // Memory Refresh Register



} Z80;

void cpu_init(Z80* cpu);

void cpu_execute(Z80* cpu, const Memory* memory);

#endif // CPU_H
