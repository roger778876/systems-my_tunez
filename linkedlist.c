#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
  if (!node) {
    return insert_front(node, n, a);
  }

  else {
    struct song_node *prev = NULL;
    struct song_node *curr = node;

    while (curr) {
      if (strcmp(curr->name, n) > 0) {
        if (prev == NULL) {
          return insert_front(curr, n, a);
        }
        else {
          prev->next = insert_front(curr, n, a);
          return node;
        }
      }
      else {
        prev = curr;
        curr = curr->next;
      }
    }

    struct song_node *new = (struct song_node *) malloc(sizeof(struct song_node));
    strncpy(new->name, n, 256);
    strncpy(new->artist, a, 256);
    prev->next = new;

    return node;
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

struct song_node *find_artist(struct song_node *node, char *a) {
  while (node != NULL) {
    if (strcmp(node->artist, a) == 0) {
      return node;
    }
    else {
      node = node->next;
    }
  }
  return 0;
}

int list_len(struct song_node *node) {
  int output = 0;
  while (node) {
    output++;
    node = node->next;
  }
  return output;
}

struct song_node *random_song(struct song_node *node) {
  int range = list_len(node) - 1;
  srand(time(NULL));
  int random = rand() % (range + 1);
  while (random > 0) {
    random--;
    node = node->next;
  }
  return node;
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

  list = insert_order(list, "c", "artist3");
  print_list(list);
  printf("\n");

  list = insert_order(list, "a", "artist1");
  print_list(list);
  printf("\n");

  list = insert_order(list, "b", "artist2");
  print_list(list);
  printf("\n");

  list = insert_order(list, "d", "artist4");
  print_list(list);
  printf("\n");

  printf("pointer: %p\n", find_song(list, "b", "artist2"));
  printf("next song: %s\n", find_song(list, "b", "artist2")->next->name);

  printf("pointer: %p\n", find_artist(list, "artist4"));
  printf("next song: %s\n", find_artist(list, "artist4")->next->name);

  printf("len: %d\n", list_len(list));

  printf("random: %s by %s\n", random_song(list)->name, random_song(list)->artist);
}
