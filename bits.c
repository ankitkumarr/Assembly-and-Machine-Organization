/* 
 * CS:APP Data Lab 
 * 
 * Ankit Kumar     akumar3
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2015 Free Software Foundation, Inc.
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
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x)&(~y) ;   //Demorgan's law to the rescue. Thanks to the TAs for showing us that
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {

 // return ((~0)+(!(x<<31)));   //could be more efficient
  return ((x<<31)>>31);		//if LSB is 1, left shifting it 31 times will make 1 in the MSB and then rightshifting will make it all 1s
				//if LSB is 0, left shifting it 31 times will make it 0 in the MSB and right shifting will make it all 0s
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return (!(x^y));
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {

        //(1<<highbit)-1 will give me all 1's highbit -1 times
        // Then, I shifted it left once and added 1 which gave me all 1's highbit times
        // Then, I just shifted right lowbit times and left lowbit times to get all 0's in position less than lowbit
	return ((((((1<<(highbit))+(~0)) <<1)+1)>>lowbit)<<lowbit);  
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int count;			// the variable to count the number of bits
  int mask = ((((((17<<8)+17)<<8)+17)<<8)+17);			//A mask for extracting last bit for every 4 bits
  int sum = mask & x;						//Grabbing the last bit for every 4 bits
  sum = sum + (mask & (x>>1));					//Grabbing the second last bit
  sum = sum + (mask & (x>>2));					//Third last bit for every 4 bits
  sum = sum + (mask & (x>>3));					//fourth bit for every 4 bits

  //adding each 4 bits by masking with 1111 together to get the count of the total bits
  count = (sum & 15) + ((sum >> 4) & 15) + ((sum >> 8) & 15) + ((sum >> 12) & 15) + ((sum >> 16) & 15)  + ((sum >> 20) & 15) + ((sum >> 24) & 15) + ((sum >> 28) & 15);
  return count;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return (~(1<<31));   //complement of 1 and all zeros will the maximum integer
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  return !(x>>31);  // x>>31 will be 0 only if x is positive. If it is 0, !0 is 1 so yeah!
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	int  a = !(x>>31); //1 if x is positive, 0 if negative
	int b = !(y>>31);  //1 if y is positive, 0 if negative
	int c = !((x+y)>>31);  //1 if x+y is poitive, 0 if negative
	return ((((a & b) & c) | (((!a)&(!b)) & (!c))) | (a^b)); // addition is only possible if 1) signs are same: x+y should retain it
							         // 2) signs are different: It will never overflow

  //return ((((!(x>>31))&(!(y>>31)))&(!((x+y)>>31)))|((!(!(x>>31)))&(!(!(y>>31)))&(!(!((x+y)>>31))))  //This is what I did but than I made it more efficient using simple tricks
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {

    int a = (1<<n)+(~0);   // create a mask of ones n - 1 times 
    int mask = ((x>>31)<<31)>>31;  //create a mask of all ones or all zeros depending on the positivity of the number
    int c = (x & a & (~mask)) | (mask & ((~(((~x)+1) & a))+1)) ; //only one or condition will be true depending on the sign of the number, mask takes care of that.
// if positive, simple anding will do the trick, if negative, I am converting it into positive, computing it and then converting it back.
    return c;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {

	int  a = !(x>>31);    // 1 is x is positive, 0 if negative
	int b = !(y>>31); 	// 1 if y is positive and 0 if negative
	int c = !((x+((~y) + 1))>>31); // 1 if x-y is positive and 0 if negative
        return (((((a & b) |
                 (!(a | b))) & !c) |
                ((a^b) & !a)));   //using the logic that x-y will be negative if x and y have same signs and x is less than y.
				  // If they have different signs, if x is negative, it is obviously less than y. 
				  // Using this fact and then demorgan's law because number of operators were exceeding
	//return ((((((a & b) & !c) | ((!(a|b)) & !c)))) | ((a^b) & !a)) ; //This is what I am actually doing but with demorgan
}


/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {

 int sign = (x>>31); // 1 if x is negative and 0 if it is positive
 int mask = ((sign<<31)>>31);  // will be all ones if x is negative and all 0s if x is positive
int c = ((mask & ((~x)+1)) | ((~mask) & x)); // either one will be true depending on the sign of x. If it's negative, convert into positive using 2's complement, if not, nothing to do.
  return c;
}



/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {

  int c = x & (x + (~0)) ;  // c will be 0 if x is a power of two. Because anding it with x -1 will and it will ones one less than bits of x
  int pos = !(x>>31); // 1 if x is positive and 0 if x is negative
  return (!c) & pos & !(!x); //returns 1 if c is 0, x is not 0 and number is positive, 0 otherwise
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 unsigned x = uf>>22; //stores the sign bit
 if ((x == ((1<<9) -1)) ) return uf;    //checks for NaN
 else if  (( x == ((1<<10) -1))) return uf;   //checks for NaN
 return (1<<31)^uf ;  //make it negative
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
int exponent, frac, sign, toxor;  
int x = uf>>23;                //to check for NaN and a constant
int mask9ones = ((1<<9)-1);     // 111111111 for NaN
int onelefteight = 1<<8;	// 100000000 for NaN purposes
int mask8ones = (onelefteight-1);	//11111111 for NaN
if (( x | onelefteight)==mask9ones) return uf;   //checking for NaN
exponent = x & (mask8ones);	//getting the exponent
frac = uf & ((1<<23)-1);	//getting the fraction
sign = (uf>>31) & 1;		//getting the sign bit
toxor = 0;			//xoring if exponent becomes zero after computation
if(uf == 2) return 1;		//all the special cases
if(uf ==0) return uf;
if (uf == (1<<31)) return uf;
if ( uf == 1) return 0;
if(exponent) {			//if any exponent other than zero, dividing it would mean reducing the exponenet by 1
  exponent = exponent - 1;
  toxor = 1;			//doing this so that I can xor later if exponent happens to become 0
}
if(!exponent) {
	int fracs = frac & 0x3;			//checking the last two digits if the mantissa will be rounded to an odd number
	frac = frac >> 1;			// dividing it by 2 
	if(fracs == 0x3) frac = frac +1;		// if it's odd, it will be made even by adding one
        if(toxor)
          frac = frac ^ (1 << 22);			//xorring to figure out the exponenet
}


return ((sign<<31) + (exponent<<23) + frac);		//returns the number in the form
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
//Did not attempt this part
unsigned float_i2f(int x) {
  return 2;
}
