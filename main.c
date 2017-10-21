#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "linkedlist.h"

int main() {
  struct song_node *library[26] = {NULL};
  // adding songs
  char n1[] = "What Do You Do";
  char a1[] = "ASAP Ferg";
  char n2[] = "rockstar";
  char a2[] = "Post Malone";
  char n3[] = "Backseat Freestyle";
  char a3[] = "Kendrick Lamar";
  char n4[] = "Don't Quit";
  char a4[] = "DJ Khaled";
  char n5[] = "Need Some";
  char a5[] = "NAV";
  char n6[] = "Plain Jane";
  char a6[] = "ASAP Ferg";
  char n7[] = "Minute";
  char a7[] = "NAV";
  char n8[] = "White Iverson";
  char a8[] = "Post Malone";
  char n9[] = "DNA";
  char a9[] = "Kendrick Lamar";
  char n10[] = "Jealous";
  char a10[] = "PnB Rock";

  add_song(n1, a1);
  add_song(n2, a2);
  add_song(n3, a3);
  add_song(n4, a4);
  add_song(n5, a5);
  add_song(n6, a6);
  add_song(n7, a7);
  add_song(n8, a8);
  add_song(n9, a9);
  add_song(n10, a10);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("LINKEDLIST.c TESTS\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing print_node
  printf("Testing print_node:\n");
  print_node(library[0]);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing print_list
  printf("Testing print_list: (printing artists beginning with 'p')\n");
  print_list(library[15]);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing insert_front & insert_order
  printf("Testing insert_front & insert_order: \"song test\" by artist test\n");
  char n11[] = "song test";
  char a11[] = "artist test";
  library[0] = insert_order(library[0], n11, a11);
  print_list(library[0]);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing find_song
  printf("Testing find_song: \"white iverson\" by post malone\n");
  print_node(find_song(library[15], n8, a8));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing find_artist
  printf("Testing find_artist: post malone\n");
  print_node(find_artist(library[15], a8));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing list_len
  printf("Testing list_len: artists beginning with 'p'\n");
  printf("%d\n", list_len(library[15]));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing randint
  printf("Testing randint: range = 26\n");
  printf("%d\n", randint(26));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing random_song
  printf("Testing random_song: artists beginning with 'p'\n");
  print_node(random_song(library[15]));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing remove_song
  printf("Testing remove_song: \"white iverson\" by post malone\n");
  library[15] = remove_song(library[15], n8, a8);
  print_list(library[15]);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing free_list
  printf("Testing free_list: artists beginning with 'p'\n");
  library[15] = free_list(library[15]);
  printf("remaining p library:\n");
  print_list(library[15]);

  printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  printf("PLAYLIST.c TESTS\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing convert_lower
  printf("Testing convert_lower:\n");
  char cl[] = "TeSt stRINg";
  printf("original string: [%s]\n", cl);
  convert_lower(cl);
  printf("new string: [%s]\n", cl);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing convert_index
  printf("Testing convert_index\n");
  printf("library index of [%s]: %d\n", cl, convert_index(cl));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing add_song
  printf("Testing add_song: \"white iverson\" by post malone\n");
  add_song(n8, a8);
  print_list(library[15]);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing search_song
  printf("Testing search_song: \"minute\" by nav\n");
  print_node(search_song(n7, a7));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing search_artist
  printf("Testing search_artist: nav\n");
  print_node(search_artist(a7));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing search_artist_r
  printf("Testing search_artist_r: nav\n");
  print_node(search_artist_r(a7, search_artist(a7)->next));

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing print_lib_letter
  printf("Testing print_lib_letter: a\n");
  print_lib_letter('a');

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing print_artist
  printf("Testing print_artist: nav\n");
  print_artist(a7);
  printf("Testing print_artist: nonexistent\n");
  char pa[] = "nonexistent";
  print_artist(pa);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing print_library
  printf("Testing print_library:\n");
  print_library();

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


  // testing print_shuffle
  printf("Testing print_shuffle: 1\n");
  print_shuffle(1);

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing delete_song
  printf("Testing delete_song: \"what do you do\" by asap ferg\n");
  delete_song(n1, a1);
  print_lib_letter('a');

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  // testing delete_library
  printf("Testing delete_library:\n");
  delete_library();
}