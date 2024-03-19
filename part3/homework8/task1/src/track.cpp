#include "track.h"
#include <iomanip>
#include <iostream>

Track::Track(std::string newTrackName, const std::tm newTrackDate,
             unsigned newTrackDuration) {
  name = newTrackName;
  date = newTrackDate;
  duration = newTrackDuration;
}

std::string Track::getName() { return name; }

std::tm Track::getDate() { return date; }

unsigned Track::getDuration() { return duration; }

bool Track::operator==(std::string &trackName) const {
  return name == trackName;
};

std::ostream &operator<<(std::ostream &out, const Track &track) {
  out << "Track name: " << track.name << std::endl
      << "Date of creation: " << std::put_time(&track.date, "%d.%m.%Y")
      << std::endl
      << "Duration: " << track.duration << " s" << std::endl;

  return out;
}
