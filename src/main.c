//
// Created by doonort3 on 23.08.2024.
//

#include <stdio.h>
#include "cpu.h"
#include "memory.h"

/*
 * Основой любой ЭВМ является процессор и оперативная память;
 * Основной цикл программы инициализирует память и процессор;
 * Выводит информационное сообщение и запускает цикл процессора;
 *
 * Так как мы ничего не записываем в оперативную память, нам выведется NOP;
*/

int main()
{

    printf("Starting z80 heartbeat...\n");

    Memory memory;
    Z80 cpu;

    memory_init(&memory);
    cpu_init(&cpu);
    
    cpu_execute(&cpu, &memory);

    return 0;
}
