// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Common Library: Clock Gating cell
//
// The logic assumes that en_i is synchronized (so the instantiation site might need to put a
// synchronizer before en_i).

module prim_generic_clock_gating #(
  parameter bit NoFpgaGate = 1'b0, // this parameter has no function in generic
  parameter bit FpgaBufGlobal = 1'b1 // this parameter has no function in generic
) (
  input        clk_i,
  input        en_i,
  input        test_en_i,
  output logic clk_o
);

  // GateMate has ONE global clock buffer. The latch+AND gate makes a second
  // clock domain (~900 core flops) that cannot get it, so it lands on general
  // routing: placement-dependent skew (core Fmax measured 13.8-32.7 MHz at a
  // 10 MHz target) plus heavy routing congestion. core_clock_gate_i is only a
  // sleep/power optimisation, so pass the clock through.
  logic unused_en;
  assign unused_en = en_i | test_en_i;
  assign clk_o = clk_i;

endmodule
