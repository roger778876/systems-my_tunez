#include "linkedlist.c"
#include "playlist.h"

struct song_node *library[26] = {NULL};

void convert_lower(char str[]) {
  int i = 0;
  for (i; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

int convert_index(char str[]) {
  int index = str[0] - 97;
  return index;
}

void add_song(char n[], char a[]) {
  convert_lower(n);
  convert_lower(a);

  int index = convert_index(a);
  library[index] = insert_order(library[index], n, a);
}

struct song_node *search_song(char n[], char a[]) {
  convert_lower(n);
  convert_lower(a);
  return find_song(library[convert_index(a)], n, a);
}

struct song_node *search_artist(char a[]) {
  convert_lower(a);
  return find_artist(library[convert_index(a)], a);
}

struct song_node *search_artist_r(char a[], struct song_node *start) {
  convert_lower(a);
  return find_artist(start, a);
}

void print_lib_letter(char a) {
  convert_lower(&a);
  struct song_node *curr = library[convert_index(&a)];
  int i = 0;
  while (curr) {
    printf("%d. \"%s\" by %s\n", i, curr->name, curr->artist);
    i++;
    curr = curr->next;
  }

}

int print_artist(char a[]) {
  convert_lower(a);
  struct song_node *curr = search_artist(a);
  if (!curr) {
    printf("No artist found.\n");
    return 0;
  }
  else {
    int i = 0;
    while (search_artist_r(a, curr)) {
      printf("%d. \"%s\" by %s\n", i, search_artist_r(a, curr)->name, search_artist_r(a, curr)->artist);
      i++;
      curr = curr->next;
    }
    return 1;
  }
}

void print_library() {
  char letter = 'a';
  int c = 0;
  int print_count = 0;
  for (c; c < 26; c++) {
    if (library[c]) {
      printf("%c:\n", letter);
      print_lib_letter(letter);
      print_count++;
    }
    letter++;
  }
  if (print_count == 0) {
    printf("Library is empty!\n");
  }
}

void print_shuffle(int count) {
  int i = 0;
  while (count) {
    int rand_index = randint(26);
    if (library[rand_index]) {
      struct song_node *rand_song = random_song(library[rand_index]);
      printf("%d. \"%s\" by %s\n", i, rand_song->name, rand_song->artist);
      i++;
      count--;
    }
  }
}

void delete_song(char n[], char a[]) {
  convert_lower(n);
  convert_lower(a);
  remove_song(library[convert_index(a)], n, a);
}

void delete_library() {
  int i = 0;
  for (i; i < 26; i++) {
    free_list(library[i]);
  }
}

void main() {
  char n[] = "Name";
  char n2[] = "name2";
  char a[] = "Dartist";
  char a2[] = "dd2";
  add_song(n, a);
  add_song(n2, a);
  add_song(n, a2);
  
  
  /*
  print_list(library[3]);

  printf("%p\n", search_song(n, a));
  printf("%p\n", search_artist(a));

  print_lib_letter('d');
  print_artist(a);
  print_library();
  print_shuffle(5);
  */
  print_library();
  delete_song(n2, a);
  print_library();

  delete_library();
  print_library();
}
