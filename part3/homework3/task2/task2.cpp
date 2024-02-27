/*Используя структуры данных, создайте подробную модель посёлка.
• Посёлок состоит из участков, и у каждого участка есть свой номер.
• На любом участке может стоять жилой дом, а также могут быть и другие
сооружения: — гараж, — сарай (бытовка), — баня. • У каждого здания есть
информация о площади, которую оно занимает на участке. • В доме может быть 1–3
этажа, на этаже — 2–4 комнаты: — спальня, — кухня, — ванная, — детская, —
гостиная. • У каждого этажа есть информация о количестве комнат и высоте потолка
на этаже. • У каждой комнаты есть информация о занимаемой площади. • В доме и
бане может быть печь с трубой. Для всех упомянутых сущностей нужно объявить
структуры данных.*/

#include <string>
#include <vector>

enum class RoomType { BEDROOM, KITCHEN, BATHROOM, KIDSROOM, LIVINGROOM };

enum class OutbuildingType { GARAGE, BARN, BATHHOUSE };

struct Room {
  RoomType type;
  float area;
};

struct Floor {
  std::vector<Room> rooms;
  float ceilingHeight;
};

struct House {
  std::vector<Floor> floors;
  float area;
  bool hasStove = false;
};

struct Outbuilding {
  OutbuildingType type;
  float area;
  bool hasStove = false;
};

struct LandPlot {
  unsigned number;
  House house;
  std::vector<Outbuilding> outbuildings;
};

struct Village {
  std::string name;
  std::vector<LandPlot> landPlots;
};
