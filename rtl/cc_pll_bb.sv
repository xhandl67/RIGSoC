module CC_PLL #(
    parameter real REF_CLK = 25.0,
    parameter real OUT_CLK = 50.0,
    parameter PERF_MD = "ECONOMY",
    parameter LOW_JITTER = 1,
    parameter LOCK_REQ = 1,
    parameter CLK270_DOUB = 0,
    parameter CLK180_DOUB = 0,
    parameter CI_FILTER_CONST = 2,
    parameter CP_FILTER_CONST = 4
)(
    input  wire CLK_REF,
    input  wire USR_CLK_REF,
    input  wire CLK_FEEDBACK,
    input  wire USR_LOCKED_STDY_RST,

    output wire USR_PLL_LOCKED_STDY,
    output wire USR_PLL_LOCKED,

    output wire CLK0,
    output wire CLK90,
    output wire CLK180,
    output wire CLK270,
    output wire CLK_REF_OUT
);
endmodule