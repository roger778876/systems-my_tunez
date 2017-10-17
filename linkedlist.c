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

// returns pointer to new front node
struct song_node *insert_front(struct song_node *node, char *n, char *a) {
  struct song_node *front = (struct song_node *) malloc(sizeof(struct song_node));
  strncpy(front->name, n, 256);
  strncpy(front->artist, a, 256);
  front->next = node;
  return front;
}

// returns pointer to new front node
struct song_node *insert_order(struct song_node *node, char *n, char *a) {
  struct song_node *new = (struct song_node *) malloc(sizeof(struct song_node));
  strncpy(new->name, n, 256);
  strncpy(new->artist, a, 256);
  
  while (strcmp(node->name, new->name) > 0) {
    
  }
  
  return front;
}

/*

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
  
  list = insert_front(list, "name2", "artist2");
  print_list(list);
  
  
}
