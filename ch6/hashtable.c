/* Basic Hash Table */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {            /* node list of names and definitions */
    struct nlist *next;   /* next in the node list */
    char *name;           /* name of definition */
    char *defn;           /* definition (replacement text) */
};

#define HASHSIZE 101

/* the hash table (array of pointers to nodes) */
static struct nlist *hashtab[HASHSIZE];

/* hash: form hash value from string s */
unsigned
hash(char *s)
{
    /* hash should be non-negative */
    unsigned hashval;

    /* rudimentary hash: on each character of s, add 31 and 
     * multiply by itself
     */
    for (hashval = 0; *s != '\0'; s++) {
	hashval = *s + 31 * hashval;
    }

    /* return the hashval modulo HASHSIZE (the remainder) */
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist
*lookup(char *s)
{
    /* initialise pointer to node */
    struct nlist *np;

    /* hash values are used to index pointers to nodes in 
     * the hash table array.
     *
     * hashtab[hash(s)] contains the pointer to the node
     * in which the name, s, and it's definition are found.
     *
     * since the hash space is small collisions will occur so
     * a string that generates the same hash will be placed
     * next in the linked list (np->next)
     */
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
	if (strcmp(s, np->name) == 0) {
	    return np;
	}
    }

    return NULL;
}

/* install: put (name, defn) in hashtab */
struct nlist
*install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    /* look up name and set np as pointer to it if it exists 
     * otherwise it is NULL so contiue through code block
     */
    if ((np = lookup(name)) == NULL) {

	/* set aside storage for a new node and set np to point to it */
	np = malloc(sizeof(*np));

	/* hash table is out of space, return null */
	if (np == NULL || (np->name = strdup(name)) == NULL) {
	    return NULL;
	}

	/* hash the name */
	hashval = hash(name);

	/* set next in chain */
	np->next = hashtab[hashval];

	/* install pointer into hashtab at hashval index:
	 * for instance if hash("test") = 53 then 
	 * hashtab[53] will store a pointer to the node that holds
	 * the name and definition of "test".
	 */
	hashtab[hashval] = np;
    }

    /* lookup found name so free previous defn */
    else {
	free((void *) np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL) {
	return NULL;
    }

    return np;
}

int
main(void)
{
    /* insert some values into the hash table */
    install("IN", "1");
    install("OUT", "0");
    install("Please", "100");
    install("routine", "120");

    struct nlist *np;
    
    /* print filled entries in hash table */
    int i;
    for (i = 0; i < HASHSIZE; i++) {
	if (hashtab[i] != NULL) {
	    np = hashtab[i];
	    printf("hashtab[%d] contains the pointer %p\n\n", i, hashtab[i]);
	    printf("\tname: %s\n\tdefn: %s\n\tnext: %p\n\n",
		   np->name, np->defn, np->next);
	    if (np->next != NULL) {
		np = np->next;
		printf("\t\tname: %s\n\t\tdefn: %s\n\t\tnext: %p\n\n",
		       np->name,
		       np->defn,
		       np->next);
	    }
			   
	}
    }

    
}
