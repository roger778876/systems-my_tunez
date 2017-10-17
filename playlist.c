#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

struct song_node { 
  char name[256];
  char artist[256];
  struct song_node *next;
};


