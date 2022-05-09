#ifndef STATEKMKAR2020_LUZNY_HPP
#define STATEKMKAR2020_LUZNY_HPP

#include "Ladunek.hpp"

class Luzny : public Ladunek{
private:
    uint32_t masa;
public:
  explicit Luzny(std::string name, uint32_t masa);
  ~Luzny() override = default;
  uint32_t getMasaLadunku();
  uint32_t obliczMase() const override;
  std::string toString() const override;
};


#endif //STATEKMKAR2020_LUZNY_HPP
