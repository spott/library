/* 	hash.h
 *  Andrew Spott
 *
 *  create a hash table for recording what 
 *  locations in the code write to memory, 
 *  and how much memory they write.
 */

#ifndef HASH_H
#define HASH_H

#define BIGPRIME 982451653

#define hash(A,B) BIGPRIME % A % B


typedef struct hash_node_ {
	int keyi;
	float keyf;
	char *keys;
	void *value;
	hash_node *next, *prev;
} hash_node;

typedef struct hash_ {
	int count;
	hash_node **entry;
} hash

/* initial memory used should be linearly 
 * proportional to table_size.  (maybe 2 times
 * table size.
 */
hash *new_hash_table(int table_size);

/* dispose of all data, replacing values
 * with zero
 */
void free_hash_table(hash *ht);

/* associate value with key. return nonzero 
 * if key is already in use and then don't 
 * add entry.  (I guess a linked list for each
 * value would be a bad thing?
 */
int hash_add_i(hash *ht, int key, void *value);
int hash_add_f(hash *ht, float key, void *value);
int hash_add_s(hash *ht, char *key, void *value);



/* resolve key and place value in dest_value. 
 * If do_remove is nonzero then remove the hash
 * entry as well if found. return nonzero if key
 * was found. if key was not found, return zero 
 * and do not alter *dest_value.
 */
int hash_find_i(hash *ht, int key, void *dest_value, int do_remove);
int hash_find_f(hash *ht, float key, void *dest_value, int do_remove);
int hash_find_s(hash *ht, char *key, void *dest_value, int do_remove);

#endif
