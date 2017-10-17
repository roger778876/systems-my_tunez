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

// returns pointer to new node
struct song_node *insert_order(struct song_node *node, char *n, char *a) {
  if (node == NULL) {
    return insert_front(node, n, a);
  }

  else {
    struct song_node *front = node;
    struct song_node *new = (struct song_node *) malloc(sizeof(struct song_node));
    strncpy(new->name, n, 256);
    strncpy(new->artist, a, 256);
    // printf("new: %s, %s\n", new->name, new->artist);
    printf("%d\n", strcmp(node->name, new->name));
    while (strcmp(node->name, new->name) != 1) {
      node = node->next;
    }
    new->next = node->next;
    node->next = new;
    return front;
  }
}

struct song_node *find_song(struct song_node *node, char *n, char *a) {
  while (node != NULL) {
    if (strcmp(node->name, n) == 0 && strcmp(node->artist, a) == 0) {
      return node;
    }
    else {
      node = node->next;
    }
  }
  return 0;
}

struct node *free_list(struct song_node *node) {
  struct song_node *first = node;
  struct song_node *next;
  while (node) {
    next = node->next;
    free(node);
    node = next;
  }
  return NULL; 
}


void main() {
  struct song_node *list = NULL;
  print_list(list);

  

  list = insert_front(list, "c", "artist3");
  print_list(list);

  list = insert_front(list, "b", "artist2");
  print_list(list);

  list = insert_front(list, "a", "artist1");
  print_list(list);

  printf("pointer: %p\n", find_song(list, "b", "artist2"));
  
}
