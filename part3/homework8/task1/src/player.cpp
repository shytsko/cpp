#include "player.h"
#include "track.h"
#include <iostream>

void Player::addToPlayList(Track track) { playList.push_back(track); }

void Player::play(void) {
  if (status == PlayerStatus::Stop) {
    std::string trackName;
    std::cout << "Enter track name: ";
    std::cin >> trackName;
    for (currentTrack = playList.begin(); currentTrack != playList.end();
         currentTrack++) {
      if (currentTrack->getName() == trackName)
        break;
    }
    if (currentTrack == playList.end()) {
      std::cout << "Track not found" << std::endl;
    } else {
      std::cout << "Track playback started" << std::endl << *currentTrack;
      status = PlayerStatus::Play;
    }
  } else if (status == PlayerStatus::Pause) {
    std::cout << "Playback resumed" << std::endl << *currentTrack;
    status = PlayerStatus::Play;
  }
}

void Player::pause(void) {
  if (status == PlayerStatus::Play) {
    std::cout << "Playback paused" << std::endl;
    status = PlayerStatus::Pause;
  }
}

void Player::next(void) {
  if (playList.size()) {
    currentTrack = playList.begin() + std::rand() % playList.size();
    std::cout << "Track playback started" << std::endl << *currentTrack;
    status = PlayerStatus::Play;
  } else {
    std::cout << "Playlist empty" << std::endl;
  }
}

void Player::stop(void) {
  if (status != PlayerStatus::Stop) {
    std::cout << "Playback stoped" << std::endl;
    status = PlayerStatus::Stop;
  }
}