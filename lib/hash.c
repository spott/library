#include "hash.h"
#include <stdlib.h>


/* This should be as simple as just creating a new hash table and then
 * returning a pointer to it, right?
 */
hash *new_hash_table(int table_size) {
	hash *h; 
	h.count = table_size;
	h.hash_node = (hash_node *) calloc(table_size, sizeof(hash_node));

	free_hash_table(h);

	return h;
}


void free_hash_table(hash *ht) {
	int i = 0;
	while (i < ht.count) {
		(ht->entry + i)-> value = (void *)0;
		i++;
	}
}

int hash_table_add_i(hash *ht, int key, void *value) {

	int lk = hash( key , ht.count );

	if ((ht + lk)->value == 0){
		(ht + lk)->key = key;
		(ht + lk)->value = value;
		return 0;
	}
	else {
		return 1;
	}
}

int hash_table_find(hash_table *ht, int key, int *dest_value, int do_remove) {
	int lk = hash(key,size);
	int v = (ht + lk)->value;
	// check for collisions
	if ((ht + lk)->key != key)
		return 0;
	
	if (v) {   								//does hash entry exist?
		if (do_remove) 					//check if you should remove the value
			(ht + lk)->value = 0; 	//remove value
		return *dest_value = v; //return value
	}
	else
		return (ht + lk)->value;
}

