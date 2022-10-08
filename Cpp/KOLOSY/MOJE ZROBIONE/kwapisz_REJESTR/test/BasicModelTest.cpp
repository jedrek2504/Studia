#include <boost/test/unit_test.hpp>
#include <RejestrPojazdow.h>
#include <SamochodCiezarowy.h>
#include <SamochodOsobowy.h>

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(TworzeniePojazdowTest) {
        SamochodCiezarowy ciezarowy("1234", 100);
        BOOST_REQUIRE_EQUAL(ciezarowy.getLiczbaPrzejechanychKilometrow(), 0);
        BOOST_REQUIRE_EQUAL(ciezarowy.getLadownosc(), 100);
        SamochodOsobowy osobowy("12345", 4);
        BOOST_REQUIRE_EQUAL(osobowy.getLiczbaPrzejechanychKilometrow(), 0);
        BOOST_REQUIRE_EQUAL(osobowy.getLiczbaMiejsc(), 4);
    }

    BOOST_AUTO_TEST_CASE(DodanieKilometrowTest) {
        SamochodCiezarowy ciezarowy("WA1234", 100);
        SamochodOsobowy osobowy("EL12345", 4);

        ciezarowy.dodajPrzejechaneKilometry(1001);
        osobowy.dodajPrzejechaneKilometry(10);

        BOOST_REQUIRE_EQUAL(ciezarowy.getLiczbaPrzejechanychKilometrow(), 1001);
        BOOST_REQUIRE_EQUAL(osobowy.getLiczbaPrzejechanychKilometrow(), 10);
        BOOST_TEST_MESSAGE(ciezarowy.toString());
        BOOST_TEST_MESSAGE(osobowy.toString());
    }

    BOOST_AUTO_TEST_CASE(TworzenieRejestruTest) {
        RejestrPojazdow rejestr(2);
        BOOST_REQUIRE_EQUAL(rejestr.pobierzLiczbePojazdow(), 0);
        BOOST_REQUIRE_CLOSE(rejestr.pobierzSredniaLiczbePrzejechanychKilometrow(), 0.0, 0.0000001);

        SamochodOsobowy *osobowy = new SamochodOsobowy("EL10293", 2);
        osobowy->dodajPrzejechaneKilometry(10.0);
        rejestr.dodajPojazd(static_cast<Pojazd_ptr>(osobowy));

        BOOST_REQUIRE_EQUAL(rejestr.pobierzLiczbePojazdow(), 1);
        BOOST_REQUIRE_CLOSE(rejestr.pobierzSredniaLiczbePrzejechanychKilometrow(), 10.0, 0.0000001);
        BOOST_TEST_MESSAGE(rejestr.toString());
    }

BOOST_AUTO_TEST_SUITE_END()
