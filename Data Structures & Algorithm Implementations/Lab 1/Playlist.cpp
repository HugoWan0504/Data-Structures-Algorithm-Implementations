#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"
//Default constructor
    PlaylistNode::PlaylistNode(){
        uniqueID = "none";
        songName = "none";
        artistName = "none";
        songLength = 0;
        nextNodePtr = 0;
    }

//Parameterized constructor (1 pt)
    PlaylistNode::PlaylistNode(string id, string SongName, string ArtistName, int SongLength){
        uniqueID = id;
        songName = SongName;
        artistName = ArtistName;
        songLength = SongLength;
        nextNodePtr = 0;
    }

//InsertAfter() (1 pt)
    void PlaylistNode::InsertAfter(PlaylistNode* Node){
        PlaylistNode* tempNext;
        tempNext = this->nextNodePtr;
        this->nextNodePtr = Node;
        Node->nextNodePtr = tempNext;
    }

//SetNext() - Mutator (1 pt)
    void PlaylistNode::SetNext(PlaylistNode* nextNode){
        nextNodePtr = nextNode;
    }

//GetID() - Accessor
    string PlaylistNode::GetID() const{
        return uniqueID;
    }

//GetSongName() - Accessor
    string PlaylistNode::GetSongName() const{
        return songName;
    }

//GetArtistName() - Accessor
    string PlaylistNode::GetArtistName() const{
        return artistName;
    }
        
//GetSongLength() - Accessor
    int PlaylistNode::GetSongLength() const{
        return songLength;
    }

//GetNext() - Accessor
    PlaylistNode* PlaylistNode::GetNext(){
        return this->nextNodePtr;
    }

void Playlist::Playlist(){
    head = nullptr;
    tail = nullptr;
}

//AddSong()
    void PlaylistNode::AddSong(){

    }

//RemoveSong()
    void PlaylistNode::RemoveSong(){
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
    }
/*
//PrintPlaylistNode() //optional 
//put this in main.cpp
    void PlaylistNode::PrintPlaylistNode(){
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Song Name: " << songName << endl;
        cout << "Artist Name: " << artistName << endl;
        cout << "Song Length (in seconds): " << songLength << endl;
    }
*/