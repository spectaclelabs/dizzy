#include <limits>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "dizzy.h"

TEST(AddTest, AddsIntegers) {
    std::array<float, 4> a, b={520,933,26,933}, c={813,80,395,524}, d={1333,1013,421,1457};

    dizzy::add(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}

TEST(AddTest, AddsNegative) {
    std::array<float, 4> a, b={355,565,422,845}, c={-702,-22,-623,-647}, d={-347,543,-201,198};

    dizzy::add(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}


TEST(AddTest, AddsDecimal) {
    std::array<float, 4> a, b={928.2731204293668,170.75876030139625,228.07836788706481,651.8935258500278}, c={558.4024842828512,191.80249935016036,-307.2676961310208,-377.12726881727576}, d={1486.675604712218,362.5612596515566,-79.18932824395597,274.76625703275204};

    dizzy::add(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}

TEST(SubtractTest, SubtractsIntegers) {
    std::array<float, 4> a, b={748,874,314,105}, c={359,722,223,191}, d={389,152,91,-86};

    dizzy::sub(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}

TEST(SubtractTest, SubtractsNegative) {
    std::array<float, 4> a, b={327,183,417,75}, c={-687,-185,-228,-810}, d={1014,368,645,885};

    dizzy::sub(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}


TEST(SubtractTest, SubtractsDecimal) {
    std::array<float, 4> a, b={809.8935454618186,575.286474544555,663.9257813803852,380.0766367930919}, c={-216.6361277922988,831.4814930781722,-169.8223827406764,-274.6396795846522}, d={1026.5296732541174,-256.19501853361726,833.7481641210616,654.7163163777441};

    dizzy::sub(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}

TEST(MultiplyTest, MultipliesIntegers) {
    std::array<float, 4> a, b={126,234,144,382}, c={789,895,500,711}, d={99414,209430,72000,271602};

    dizzy::mul(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}

TEST(MultiplyTest, MultipliesNegative) {
    std::array<float, 4> a, b={687,911,931,614}, c={-401,-709,-555,-727}, d={-275487,-645899,-516705,-446378};

    dizzy::mul(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}


TEST(MultiplyTest, MultipliesDecimal) {
    std::array<float, 4> a, b={931.9279678165913,406.16391226649284,115.81271444447339,968.071170616895},c={-289.039742667228,188.41300252825022,-163.57188019901514,469.7651811875403},d={-269364.2200021003,76526.56222875071,-18943.703452634152,454766.1288672799};

    dizzy::mul(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}

TEST(DivideTest, DividesIntegers) {
    std::array<float, 4> a, b={153,91,436,558}, c={947,70,264,703}, d={0.16156282998944033,1.3,1.6515151515151516,0.7937411095305832};

    dizzy::div(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}

TEST(DivideTest, DividesNegative) {
    std::array<float, 4> a, b={687,634,442,357}, c={-260,-52,-55,-335}, d={-2.6423076923076922,-12.192307692307692,-8.036363636363637,-1.0656716417910448};
    
    dizzy::div(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}

TEST(DivideTest, DividesDecimal) {
    std::array<float, 4> a, b={443.40162537992,505.3492677398026,805.8234371710569,520.9516226314008}, c={590.2828895486891,-163.4230064228177,-72.34945520758629,156.4507158473134}, d={0.7511680132197806,-3.0922773898329403,-11.137933725402279,3.329812968959622};
    
    dizzy::div(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}

TEST(MaddTest, MaddIntegers) {
    std::array<float, 4> a, b={659,581,365,923}, c={198,118,674,501}, d={189,871,579,111}, e={38081,103359,390611,56534};

    dizzy::madd(a, b, c, d);

    EXPECT_THAT(a, ::testing::Eq(e));
}

TEST(MaddTest, MaddNegative) {
    std::array<float, 4> a, b={37,408,706,211}, c={-125,-679,-386,-981}, d={-18,-625,-920,-507}, e={2287,424783,355826,497578};
    
    dizzy::madd(a, b, c, d);

    EXPECT_THAT(a, ::testing::Eq(e));
}

TEST(MaddTest, MaddDecimal) {
    std::array<float, 4> a, b={431.5957787912339,544.194750720635,385.1467010099441,439.93882928043604}, c={582.8954069875181,-274.6881591156125,-282.0429103448987,-168.9471616409719}, d={610.763318836689,-319.471369497478,-622.3394768312573,-616.8598760850728}, e={356442.72908515035,88299.19712812651,175911.5839690194,104656.66402405512};
    
    dizzy::madd(a, b, c, d);

    EXPECT_THAT(a[0], testing::FloatEq(e[0]));
    EXPECT_THAT(a[1], testing::FloatEq(e[1]));
    EXPECT_THAT(a[2], testing::FloatEq(e[2]));
    EXPECT_THAT(a[3], testing::FloatEq(e[3]));
}

TEST(PowTest, PowIntegers) {
    std::array<float, 4> a, b={12,2,16,6}, c={27,25,91,10}, d={1.3737055255899818e+29,33554432,std::numeric_limits<float>::infinity(),60466176};

    dizzy::pow(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}

TEST(PowTest, PowNegative) {
    std::array<float, 4> a, b={18,15,10,19}, c={-35,-24,-41,-36}, d={1.1210387714598537e-44,5.940319061168546e-29,9.999665841421895e-42,0};
    
    dizzy::pow(a, b, c);

    EXPECT_THAT(a, ::testing::Eq(d));
}

TEST(PowTest, PowDecimal) {
    std::array<float, 4> a, b={18.185063526500016,9.32822537352331,10.88621590542607,15.22824240126647}, c={1.4863683376461267,-68.08492043055594,-78.90474474988878,43.46963255666196}, d={74.54186248779297,0,0,std::numeric_limits<float>::infinity()};
    
    dizzy::pow(a, b, c);

    EXPECT_THAT(a[0], testing::FloatEq(d[0]));
    EXPECT_THAT(a[1], testing::FloatEq(d[1]));
    EXPECT_THAT(a[2], testing::FloatEq(d[2]));
    EXPECT_THAT(a[3], testing::FloatEq(d[3]));
}


int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
