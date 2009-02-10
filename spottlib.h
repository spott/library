/*
 *  spottlib.h
 *  
 *	Basic lib with some usefull functions,
 *
 *  Created by Andrew Spott on 12/4/08.
 *  Copyright 2008 Andrew Spott. All rights reserved.
 *
 */
#include<string.h>

#ifndef SPOTTLIB_H
#define SPOTTLIB_H


/* creates a character array that is ascii for the value of the
 * int
 */
void itoa(int, char[]);

/* reverses a character array
 */
void reverse(char *);

#endif
