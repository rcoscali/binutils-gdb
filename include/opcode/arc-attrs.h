/* Copyright (C) 1994-2016 Free Software Foundation, Inc.

   Contributed by Claudiu Zissulescu (claziss@synopsys.com)

   This file is part of GAS, the GNU Assembler, GDB, the GNU debugger, and
   the GNU Binutils.

   GAS/GDB is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS/GDB is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS or GDB; see the file COPYING3.  If not, write to
   the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#ifndef ATTRS_ARC_H
#define ATTRS_ARC_H

#ifndef FEATURE_LIST_NAME
#define FEATURE_LIST_NAME feature_list
#endif

/* A table with cpu features.  */
const struct feature_type
{
  unsigned feature;
  unsigned cpus;
  const char *attr;
  const char *name;
}  FEATURE_LIST_NAME [] =
  {
    { CVT,     ARC_OPCODE_ARCV2,    "CVT",     "FP conversion" },
    { BTSCN,   ARC_OPCODE_ARCALL,   "BTSCN",   "bit-scan" },
    { CD,      ARC_OPCODE_ARCV2,    "CD",      "code-density" },
    { COND,    ARC_OPCODE_ARCALL,   "COND",    "conditionals" },
    { DIV,     ARC_OPCODE_ARCV2,    "DIVREM",  "div/rem" },
    { DP,      ARC_OPCODE_ARCv2HS,  "DFPU",    "double-precision FPU" },
    { DPA,     ARC_OPCODE_ARCv2EM,  "FPUDA",   "double assist FP" },
    { DPX,     ARC_OPCODE_ARCFPX,   "DPFP",    "double-precision FPX" },
    { MPY1E,   ARC_OPCODE_ARCV2,    "MPY1E",   "mpy1e" },
    { MPY6E,   ARC_OPCODE_ARCMPY6E, "MPY6E",   "mpy6e" },
    { MPY7E,   ARC_OPCODE_ARCV2,    "MPY7E",   "mpy7e" },
    { MPY8E,   ARC_OPCODE_ARCV2,    "MPY8E",   "mpy8e" },
    { MPY9E,   ARC_OPCODE_ARCv2HS,  "MPY9E",   "mpy9e" },
    { NPS400,  ARC_OPCODE_ARC700,   "NPS400",  "nps400" },
    { QUARKSE, ARC_OPCODE_ARCv2EM,  "QUARKSE", "QuarkSE-EM" },
    { SHFT1,   ARC_OPCODE_ARCALL,   "SA",      "shift assist" },
    { SHFT2,   ARC_OPCODE_ARCALL,   "BS",      "barrel-shifter" },
    { SWAP,    ARC_OPCODE_ARCALL,   "SWAP",    "swap" },
    { SP,      ARC_OPCODE_ARCV2,    "SFPU",    "double-precision FPU" },
    { SPX,     ARC_OPCODE_ARCFPX,   "SPFP",    "single-precision FPX" },
  };

#ifndef CONFLICT_LIST
#define CONFLICT_LIST conflict_list
#endif

/* A table with conflicting features.  */
unsigned CONFLICT_LIST [] = {
  NPS400 | DPA,
  DPX | DPA,
  SP | DPX,
  SP | SPX,
  DP | DPX,
  DP | SPX
};
#endif
