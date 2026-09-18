# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

.section .text
.global default_exc_handler
default_exc_handler:
1:
    j 1b



reset_handler:
  /* set all registers to zero */
  mv  x1, x0
  mv  x2, x1
  mv  x3, x1
  mv  x4, x1
  mv  x5, x1
  mv  x6, x1
  mv  x7, x1
  mv  x8, x1
  mv  x9, x1
  mv x10, x1
  mv x11, x1
  mv x12, x1
  mv x13, x1
  mv x14, x1
  mv x15, x1
  mv x16, x1
  mv x17, x1
  mv x18, x1
  mv x19, x1
  mv x20, x1
  mv x21, x1
  mv x22, x1
  mv x23, x1
  mv x24, x1
  mv x25, x1
  mv x26, x1
  mv x27, x1
  mv x28, x1
  mv x29, x1
  mv x30, x1
  mv x31, x1

  /* stack initilization */
  la   x2, _stack_start

_start:
  .global _start

  /* clear BSS */
  la x26, _bss_start
  la x27, _bss_end

  bge x26, x27, zero_loop_end

zero_loop:
  sw x0, 0(x26)
  addi x26, x26, 4
  ble x26, x27, zero_loop
zero_loop_end:


main_entry:
  /* jump to main program entry point (argc = argv = 0) */
  addi x10, x0, 0
  addi x11, x0, 0
  jal x1, main

  /* If execution ends up here just put the core to sleep */
sleep_loop:
  wfi
  j sleep_loop

/* =================================================== [ exceptions ] === */
/* This section has to be down here, since we have to disable rvc for it  */

  .section .vectors, "ax"
  .option norvc;

  // All unimplemented interrupts/exceptions go to the default_exc_handler.



/* Interrupt / Exception vector table */

  /* ID 0 */
  .org 0x00
      jal x0, default_exc_handler

  /* ID 1 */
  .org 0x04
      jal x0, default_exc_handler

  /* ID 2 */
  .org 0x08
      jal x0, default_exc_handler

  /* ID 3 */
  .org 0x0C
      jal x0, default_exc_handler

  /* ID 4 */
  .org 0x10
      jal x0, default_exc_handler

  /* ID 5 */
  .org 0x14
      jal x0, default_exc_handler

  /* ID 6 */
  .org 0x18
      jal x0, default_exc_handler

  /* ID 7: Machine Timer Interrupt */
  .org 0x1C
      jal x0, MachineTimer

  /* ID 8 */
  .org 0x20
      jal x0, default_exc_handler

  /* ID 9 */
  .org 0x24
      jal x0, default_exc_handler

  /* ID 10 */
  .org 0x28
      jal x0, default_exc_handler

  /* ID 11: Machine External Interrupt */
  .org 0x2C
      jal x0, default_exc_handler

  /* ID 12 */
  .org 0x30
      jal x0, default_exc_handler

  /* ID 13 */
  .org 0x34
      jal x0, default_exc_handler

  /* ID 14 */
  .org 0x38
      jal x0, default_exc_handler

  /* ID 15 */
  .org 0x3C
      jal x0, default_exc_handler

  /* ID 16 */
  .org 0x40
      jal x0, default_exc_handler

  /* ID 17 */
  .org 0x44
      jal x0, default_exc_handler

  /* ID 18 */
  .org 0x48
      jal x0, default_exc_handler

  /* ID 19 */
  .org 0x4C
      jal x0, default_exc_handler

  /* ID 20 */
  .org 0x50
      jal x0, default_exc_handler

  /* ID 21 */
  .org 0x54
      jal x0, default_exc_handler

  /* ID 22 */
  .org 0x58
      jal x0, default_exc_handler

  /* ID 23 */
  .org 0x5C
      jal x0, default_exc_handler

  /* ID 24 */
  .org 0x60
      jal x0, default_exc_handler

  /* ID 25 */
  .org 0x64
      jal x0, default_exc_handler

  /* ID 26 */
  .org 0x68
      jal x0, default_exc_handler

  /* ID 27 */
  .org 0x6C
      jal x0, default_exc_handler

  /* ID 28 */
  .org 0x70
      jal x0, default_exc_handler

  /* ID 29 */
  .org 0x74
      jal x0, default_exc_handler

  /* ID 30 */
  .org 0x78
      jal x0, default_exc_handler

  /* ID 31 */
  .org 0x7C
      jal x0, default_exc_handler


  /* Reset vector */
  .org 0x80
      jal x0, reset_handler
    // reset vector
