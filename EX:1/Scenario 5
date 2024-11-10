#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONG_LENGTH 100
typedef struct Song {
    char title[MAX_SONG_LENGTH];
    struct Song* next;
} Song;
Song* head = NULL;
void add_song(const char* song_title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, song_title);
    newSong->next = head;
    head = newSong;
}
void remove_song(const char* song_title) {
    Song *temp = head, *prev = NULL;
    if (temp != NULL && strcmp(temp->title, song_title) == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->title, song_title) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void display_playlist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    Song* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->title);
        temp = temp->next;
    }
}
int main() {
    add_song("Song 1");
    add_song("Song 2");
    add_song("Song 3");
    printf("Playlist:\n");
    display_playlist();
    remove_song("Song 2");
    printf("\nUpdated Playlist:\n");
    display_playlist();
    return 0;
}
