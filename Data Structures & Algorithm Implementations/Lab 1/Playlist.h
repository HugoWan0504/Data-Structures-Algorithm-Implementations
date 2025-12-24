#ifndef _Playlist_H_
#define _Playlist_H_

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode{
    public:
        //Default constructor (1 pt)
        PlaylistNode();
        //Parameterized constructor (1 pt)
        PlaylistNode(string id, string SongName, string ArtistName, int songLength);
        //InsertAfter() (1 pt)
        void InsertAfter(PlaylistNode* Node);
        //SetNext() - Mutator (1 pt)
        void SetNext(PlaylistNode* nextNode);
        //GetID() - Accessor
        string GetID() const;
        //GetSongName() - Accessor
        string GetSongName() const;
        //GetArtistName() - Accessor
        string GetArtistName() const;
        //GetSongLength() - Accessor
        int GetSongLength() const;
        PlaylistNode* GetNext();
        //void PrintPlaylistNode(); //optional

    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;

    public:
        void Playlist();
        void AddSong();
        void RemoveSong();
};

class Playlist{
    protected:
        PlaylistNode* head;
        PlaylistNode* tail;
};


#endif /*_Playlist_H_*/
