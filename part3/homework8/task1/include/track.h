#pragma once
#include <ctime>
#include <string>

class Track {
  std::string name;
  std::tm date;
  unsigned duration;

public:
  Track(std::string newTrackName, const std::tm newTrackDate,
        unsigned newTrackDuration);

  std::string getName(void);
  std::tm getDate(void);
  unsigned getDuration(void);
  friend std::ostream &operator<<(std::ostream &out, const Track &);
};