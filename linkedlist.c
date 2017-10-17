#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node { 
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_list(struct song_node *node) {
  while (node) {
    printf("\"%s\" by %s\n", node->name, node->artist);
    node = node->next;
  }
}

struct song_node *insert_front(struct song_node *node, char *n, char *a) {
  struct song_node *front = (struct song_node *) malloc(sizeof(struct song_node));
  strncpy(front->name, n, 256);
  strncpy(front->artist, a, 256);
  return front;
}
/*
struct node *insert_i(struct song_node *node, char *n, char *a, int i) {
  struct node *front = (struct song_node *) malloc(sizeof(struct node));
  front->i = i;
  front->next = node;
  return front;
}

struct node *free_list(struct song_node *node) {
  struct node *first = node;
  struct node *next;
  while (node) {
    next = node->next;
    free(node);
    node = next;
  }
  return NULL; 
}
*/

void main(){
  struct song_node *list = NULL;
  print_list(list);

  list = insert_front(list, "name", "artist");
  print_list(list);
  
  
}
