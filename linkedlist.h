struct song_node { 
  char name[256];
  char artist[256];
  struct song_node *next;
};
void print_list(struct song_node *node);
struct song_node *insert_front(struct song_node *node, char n[], char a[]);
struct song_node *insert_order(struct song_node *node, char n[], char a[]);
struct song_node *find_song(struct song_node *node, char n[], char a[]);
struct song_node *find_artist(struct song_node *node, char a[]);
int list_len(struct song_node *node);
int randint(int range);
struct song_node *random_song(struct song_node *node);
struct song_node *remove_song(struct song_node *node, char n[], char a[]);
struct song_node *free_list(struct song_node *node);
