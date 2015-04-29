// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
// for example: "ACGAATTCCG". 
// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
// For example,
// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].


#include "uthash.h"

struct my_struct {
    int id;            /* we'll use this field as the key */
    char name[10];             
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_struct *users = NULL;

void add_user(struct my_struct *s) {
    HASH_ADD_INT( users, id, s );    
}

struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );  
    return s;
}

void delete_user(struct my_struct *user) {
    HASH_DEL( users, user);  
}

int main(){
	char name = "yeqing";

	add_user(10, name);

	HASH_FIND_INT()
}