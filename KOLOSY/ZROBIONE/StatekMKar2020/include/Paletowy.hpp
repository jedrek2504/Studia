#ifndef STATEKMKAR2020_PALETOWY_HPP
#define STATEKMKAR2020_PALETOWY_HPP

#include "Ladunek.hpp"

class Paletowy : public Ladunek{
private:
    uint32_t liczbaPalet;
    uint32_t masaPalety;
public:
  Paletowy(std::string nazwa, uint32_t masa, uint32_t ilosc);
  uint32_t obliczMase() const override;
  uint32_t getMasaPalety();
  uint32_t getLiczbaPalet();
  std::string toString() const override;
  ~Paletowy() override = default;
};


#endif //STATEKMKAR2020_PALETOWY_HPP
