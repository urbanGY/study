/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
 // + : 1 | 0 = 1
 // 0 : 0 | 0 = 0
 // - : 0 | -1 = -1
int sign(int x) {
    int a = !!x;
    return a | (x >> 31);
}
/*
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
 // 0000 0100
 // 0 -> 1
 // 1 > -> 0
 // 111111111111111111111
 // 000000000000000000000 -> 0
 // 111111111111111111111
 // 000000000000000000001 -> 1
int upperBits(int n) {
  int x __attribute__((unused));
  int a __attribute__((unused));
  x = !n;
  a = 1;
  a = a<<31;
  a = a >> (n + (~0 + x));
  n = a << x;
  return n;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
 // 0100  1011
 // 0010 &1101
 //       1001 -> 0110
 // 0100 1011
 // 0101 1010 -> 1010
int bitXor(int x, int y) {
  return ~(~(x & ~y) & ~(y & ~x));
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
 //0010
 //1110 -> 0001 + 1 = 0010
 //1111 -> 0000 + 1 = 0001 & 1111
 //0010 -> 1101 + 1 = 1110 & 0010
 //1000 0000 0000 0000 0000 0000 0000 0001
 //0111 1111 1111 1111 1111 1111 1111 1111
 //0010 0011 0000 0111 1100 0101 1100 0011
 //1101 1100 1111 1000 0011 1010 0011 1101
int absVal(int x) {
  int a = x;
  a = a >> 31;
  return (x^a)+(a&1);
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  n = n << 3;
  return (x >> n) & 255;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int mask, a, b, c, d, e, f;
  mask = x >> 31;
  x = (~mask & x)|(~x & mask);
  a = !!(x >> 16);
  a = a << 4;
  x = x >> a;

  b = !!(x >> 8);
  b = b << 3;
  x = x >> b;

  c = !!(x >> 4);
  c = c << 2;
  x = x >> c;

  d = !!(x >> 2);
  d = d << 1;
  x = x >> d;

  e = !!(x >> 1);
  x = x >> e;

  f = x;

  return a + b + c + d + e + f + 1;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int a, b, c;
  a = x >> 31;
  b = y >> 31;
  c = !(a^b)&!((x + ~y) >> 31);
  return c|((!a)&b);
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
 // 0111 1111 1111 1111 1111 1111 1111 1111
 //        0
int rotateRight(int x, int n) {
  int m = ~n+1;
  int c = !n;
  int f = ~(1 << 31);
  int a = f | (c << 31);
  int mask = 0;
  a = a >> (31 + m);
  a = a&x;
  a = a << (32 + m);
  x = x >> n;
  mask = f >> ((n + c) + ~0);
  x = x & mask;

  return x|a;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
// 1111 1111 0000 0000 0000 0001
// 1111 1111 1111 1111 1111 1111
// 1111 1110 1111 1111        00
// 0000 0001 1111 1111
int bang(int x) {
  int a = x + ~0;
  int b = a & ~x;
  b = b >> 31;
  return b&1;
}
/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
 // + - 0 > 1, +inf -inf -> 1 , -nan, +nan -> 0,
int floatIsEqual(unsigned uf, unsigned ug) {
    unsigned a = uf<<1;
    unsigned b = ug<<1;
    unsigned c = !!((uf << 9)&~0);//멘티사 확인 있으면 1
    unsigned d = !!((ug << 9)&~0);
    unsigned e = !((a>>24)^0xff);//익스포텐셜 모두1 이면 1
    unsigned f = !((b>>24)^0xff);//unsigned는 logical shift!
    if(!(a|b))//+0 -0
      return 1;
    if( (c&e)||(d&f) )//nan
      return 0;
    if(!(uf^ug))
      return 1;
    return 0;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *    s
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 41
 */
unsigned floatPower2(int x) {
    if(!!(x >> 31))
      return 0;
    if(!(x>>7))
      return (x + 127) << 23;
    return (0xff << 23);
}
/*
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {
  int a = 1<<31;
  int sign = x&a;
  int exp = 158;//E 31
  int frac = 0;
  if(!x) return 0;
  if(x == a) return 0xcf << 24;
  if(sign) x = ~x + 1;
  while(!(x&a)){
    x = x<<1;
    exp = exp - 1;
  }
  frac = (x&(~a)) >> 8;
  if(x&0x80 && ((x&0x7F) > 0 || frac&1))
    frac = frac + 1;
  exp = exp << 23;
  return sign + exp + frac;
}


// int a = x + 127;
// if(a>=255) a = 255;
// else if(a < 1) a = 0;
// a = a << 23;
// return a;

// if(x > 127)
//   return 0x7f800000;
// else if(x < -149)
//   return 0;
// else {
//   if(x > -127)
//     return (x + 127) << 23;
//   else
//     return 1 << (149 + x);
// }
