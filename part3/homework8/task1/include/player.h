#pragma once
#include "track.h"
#include <string>
#include <vector>

enum class PlayerStatus { Stop, Play, Pause };

class Player {
  std::vector<Track> playList;
  std::vector<Track>::iterator currentTrack;
  PlayerStatus status = PlayerStatus::Stop;

public:
  void addToPlayList(Track);
  void play(void);
  void pause(void);
  void next(void);
  void stop(void);
};