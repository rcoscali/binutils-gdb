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
    { ARC_CD,     ARC_OPCODE_ARCV2,   "CD",     "code-density" },
    { ARC_NPS400, ARC_OPCODE_ARC700,  "NPS400", "nps400" },
    { ARC_SPFP,   ARC_OPCODE_ARCFPX,  "SPFP",   "single-precision FPX" },
    { ARC_DPFP,   ARC_OPCODE_ARCFPX,  "DPFP",   "double-precision FPX" },
    { ARC_FPUDA,  ARC_OPCODE_ARCv2EM, "FPUDA",  "double assist FP" }
  };

#ifndef CONFLICT_LIST
#define CONFLICT_LIST conflict_list
#endif

/* A table with conflicting features.  */
unsigned CONFLICT_LIST [] = {
  ARC_NPS400 | ARC_CD | ARC_FPUDA,
  ARC_DPFP | ARC_FPUDA
};
#endif
