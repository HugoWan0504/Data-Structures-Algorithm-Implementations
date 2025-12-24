#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"

using namespace std;

void PrintMenu(string Title);
void OutputFullPlaylist(string Title, int count, string uniqueID, string songName, string artistName, int songLength);
void PrintPlaylistNode(string id, string SongName, string ArtistName, int SongLength);

int main(){
    Playlist mylist; //mylist.RemoveSong()/AddSong()

    string playlistTitle = "none";
    char choice = '?';
    vector<int> list1;
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    int currPos;
    int newPos;
    int totalTime;
    int playlistCount = 0;

    PlaylistNode* head;
    PlaylistNode* tail;

    //cout << "Start Testing." << endl << endl;

    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    cout << endl;
    PrintMenu(playlistTitle);
    cin >> choice;
    while (choice != 'q' || choice != 'Q'){
        //QUIT double check
        if (choice == 'q' || choice == 'Q'){
            cout << endl;
            break;
        }
        //the options
        else if (choice == 'a' || choice == 'A'){
            cin.ignore();
            playlistCount++;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);
            cin.ignore();
            cout << "Enter song's name:" << endl;
            getline(cin, songName);
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;
            
            PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
            if (tail != nullptr) {
                tail->SetNext(newNode);
            }
            tail = newNode;
            if (head == nullptr) {
                head = newNode;
            }
        }
        else if (choice == 'd' || choice == 'D'){
            cin.ignore();
            playlistCount--;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);
            //do something to remove the id's playlist
            /* Put this into Playlist.cpp
            PlaylistNode* curNode = head;
            PlaylistNode* targetDeleteNode = nullptr;
            while (curNode != nullptr) {
                PlaylistNode* nextNode = curNode->GetNext();
                if (curNode == uniqueID){ //curNode's id finds and matches the id in the list
                    targetDeleteNode = curNode;
                    delete targetDeleteNode;
                }
                curNode = nextNode;
            }
            */
            cout << "\"" << songName << "\" removed" << endl;
        }
        else if (choice == 'c' || choice == 'C'){
            cin.ignore();
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> currPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            //do something to change the positions in the list
            cout << "\"" << songName << "\"" << " moved to position" << newPos << endl;
        }
        else if (choice == 's' || choice == 'S'){
            cin.ignore();
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            //do something to output the relavent playlists of the artist
        }
        else if (choice == 't' || choice == 'T'){
            cin.ignore();
            //do something to sum up the total time
            PlaylistNode* curNode = head;
            while (curNode != nullptr) {
                totalTime = totalTime + curNode->GetSongLength();
                curNode = curNode->GetNext();
            }
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << totalTime << " seconds" << endl;
            
        }
        else if (choice == 'o' || choice == 'O'){
            cin.ignore();
            //do something to output the full playlist
            OutputFullPlaylist(playlistTitle, playlistCount, uniqueID, songName, artistName, songLength);
        }
        //if entered none of the choice, ask for rechoose
        else{
            cout << endl;
            cout << "There is no " << choice << " option." << endl;
            cout << "Please rechoose the option." << endl;
            cin.ignore();
        }
        
        cout << endl;
        PrintMenu(playlistTitle);
        choice = 'q';
        cin >> choice;
    }

    //Free memory, using delete
    PlaylistNode* curNode = head;
    while (curNode != nullptr) {
        PlaylistNode* next = curNode->GetNext();
        delete curNode;
        curNode = next;
    }

    //cout << "End Testing." << endl << endl;

    return 0;
}


void PrintMenu(string Title){
    cout << Title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:";
}

void OutputFullPlaylist(string Title, int count, string uniqueID, string songName, string artistName, int songLength){
    cout << Title << " - OUTPUT FULL PLAYLIST" << endl;
    int i = 0;
    int num = i + 1;
    PlaylistNode printOutput;
    //if list empty, break
    if (count == 0){
        cout << "Playlist is empty" << endl;
    }
    else{
        for (i = 0; i < count; ++i){
            cout << num << "." << endl;
            PrintPlaylistNode(uniqueID, songName, artistName, songLength);
            cout << endl;
        }
    }
}

void PrintPlaylistNode(string uniqueID, string songName, string artistName, int songLength){
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl << endl;
}

