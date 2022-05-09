#ifndef STATEKMKAR2020_STATEK_HPP
#define STATEKMKAR2020_STATEK_HPP
#include <vector>
#include <boost/shared_ptr.hpp>
#include <string>

class Ladunek;
typedef std::shared_ptr<Ladunek> ladunekPtr;

class Statek {
public:
    explicit Statek(uint32_t ladownosc);
    bool dodajLadunek(const ladunekPtr& ladunek);
    bool usunLadunek(ladunekPtr& ladunek);
    uint32_t pobierzLiczbeLadunkow() const;
    uint32_t pobierzLacznaMaseLadunkow() const;
    double pobierzSredniaMaseLadunkow() const;
    std::string toString() const;

private:
  uint32_t ladownosc;
  std::vector<ladunekPtr> statek;
};


#endif //STATEKMKAR2020_STATEK_HPP
