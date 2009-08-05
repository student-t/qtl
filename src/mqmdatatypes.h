/**********************************************************************
 *
 * mqmdatatypes.h
 *
 * copyright (c) 2009 Ritsert Jansen, Danny Arends, Pjotr Prins and Karl Broman
 *
 * last modified Apr, 2009
 * first written Feb, 2009
 *
 *     This program is free software; you can redistribute it and/or
 *     modify it under the terms of the GNU General Public License,
 *     version 3, as published by the Free Software Foundation.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but without any warranty; without even the implied warranty of
 *     merchantability or fitness for a particular purpose.  See the GNU
 *     General Public License, version 3, for more details.
 *
 *     A copy of the GNU General Public License, version 3, is available
 *     at http://www.r-project.org/Licenses/GPL-3
 *
 * Several datastructures needed by the MQM algorithm are defined here
 * Contains:
 *
 **********************************************************************/

#ifdef __cplusplus
  extern "C" {
#endif

// Cross types
typedef unsigned int RqtlCrossType;
enum MQMCrossType { CUNKNOWN = 'U', CF2 = 'F', CBC = 'B', CRIL = 'R' };
const RqtlCrossType RC_F2  = 1;
const RqtlCrossType RC_BC  = 2;
const RqtlCrossType RC_RIL = 3;

// Marker locations/relations
const unsigned char MLEFT     = 'L';
const unsigned char MRIGHT    = 'R';
const unsigned char MMIDDLE   = 'M';
const unsigned char MUNLINKED = 'U';
const unsigned char MUNKNOWN  = 0;

// Marker genotypes (scored at marker)
const unsigned char MAA       = '0';  // Homozygous AA
const unsigned char MH        = '1';  // Heterozygous AB 
const unsigned char MBB       = '2';  // Homozygous BB
const unsigned char MNOTAA    = '3';  // Not AA
const unsigned char MNOTBB    = '4';  // Not BB 
const unsigned char MMISSING  = '9';  // Unknown (marker genotype missing)
const unsigned char MUNUSED   = '-';  // Unused parameter



/*------------------------------------------------------------------------
Datastructures for matrix and vector calculus
------------------------------------------------------------------------ */
typedef double*** Mmatrix;
typedef double** matrix;
typedef double*  vector;
typedef char**   cmatrix;
typedef char*    cvector;
typedef int*  ivector;


MQMCrossType determine_MQMCross(const int Nmark, const int Nind, const int **Geno, const RqtlCrossType rqtlcrosstype);

void change_coding(int *Nmark,int *Nind,int **Geno,cmatrix markers, const MQMCrossType crosstype);


/*------------------------------------------------------------------------
Basic routines for matrix and vector calculus
------------------------------------------------------------------------ */
vector newvector(int dim);
ivector newivector(int dim);
cvector newcvector(int dim);
matrix newmatrix(int rows, int cols);
Mmatrix newMmatrix(int rows, int cols,int depth);
void   printmatrix(matrix m, int rows, int cols);
void   printcmatrix(cmatrix m, int rows, int cols);
cmatrix newcmatrix(int rows, int cols);
void freematrix(void **m, size_t rows);
void freevector(void *v);
void delmatrix(matrix m, size_t rows);
void delMmatrix(Mmatrix m, size_t rows);
void delcmatrix(cmatrix m, size_t rows);
void copyvector(vector vsource, vector vdestination, int dim);

#ifdef __cplusplus
  }
#endif

/* end of mqmdata.h */