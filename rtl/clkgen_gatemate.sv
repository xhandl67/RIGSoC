//TODO: PLL erstellen für höhere Frequenzen
module clkgen_gatemate (
    input  logic IO_CLK,
    input  logic IO_RST_N,
    output logic clk_sys,
    output logic rst_sys_n
);
    logic new_clk_faster;
CC_PLL #(
.REF_CLK(25.0),
.OUT_CLK(50.0),
.PERF_MD("ECONOMY"), // LOWPOWER, ECONOMY, SPEED (optional, global
.LOW_JITTER(1), // 0: disable, 1: enable low jitter mode
.LOCK_REQ(1),
.CLK270_DOUB(0),
.CLK180_DOUB(0),
.CI_FILTER_CONST(2), // optional CI filter constant
.CP_FILTER_CONST(4) // optional CP filter constant
) pll_inst (
.CLK_REF(IO_CLK),
.USR_CLK_REF(),
.CLK_FEEDBACK(),
.USR_LOCKED_STDY_RST(),
.USR_PLL_LOCKED_STDY(),
.USR_PLL_LOCKED(),
.CLK0(new_clk_faster),
.CLK90(),
.CLK180(),
.CLK270(),
.CLK_REF_OUT()
);
    assign clk_sys = new_clk_faster;
    assign rst_sys_n =  IO_RST_N;
endmodule