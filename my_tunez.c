#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

struct song_node *library[26] = {NULL};

void add_song(char *n, char *a) {


  int index = a[0] - 97;
  library[index] = insert_order(library[index], n, a);
}

void main() {
  char n[] = "name";
  char a[] = "drtist";
  add_song(n, a);
  print_list(library[3]);
}
