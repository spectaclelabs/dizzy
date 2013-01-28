#include <limits>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "dizzy.h"

MATCHER_P2(Near, expected, error, "") {
  return expected - error <= arg && arg <= expected + error;
}

MATCHER_P2(Between, a, b, "") { return a <= arg && arg <= b; }

TEST(AcosTest, Values) {
    dizzy::Buffer<4> a, b={0.9929446523468466,-0.9994428453422334,-0.4708111937898803,-0.3258771376731108}, c={0.11885839994974795,3.1082098315898414,2.061006356375571,1.902735690106372};

    dizzy::acos(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(AsinTest, Values) {
    dizzy::Buffer<4> a, b={-0.9479498091526298,-0.37975206467687117,-0.9387113206139908,0.1679918140503386}, c={-1.2467342892123465,-0.3895282691242395,-1.2188725629806436,0.16879217704919824};

    dizzy::asin(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(AtanTest, Values) {
    dizzy::Buffer<4> a, b={0.7044233820823672,0.9897194046961619,0.7749970484411393,0.2356478766691885}, c={0.613688512043791,0.7802313525415834,0.6593082243262487,0.23142584191961307};

    dizzy::atan(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(AbsTest, AbsInteger) {
    dizzy::Buffer<4> a, b={119,844,770,695}, c={119,844,770,695};

    dizzy::abs(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(AbsTest, AbsNegative) {
    dizzy::Buffer<4> a, b={308,802,-818,-262}, c={308,802,818,262};

    dizzy::abs(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(AbsTest, AbsDecimal) {
    dizzy::Buffer<4> a, b={-113.94355306401849,713.2789045572281,89.32031504809856,-936.2620343454182}, c={113.94355306401849,713.2789045572281,89.32031504809856,936.2620343454182};

    dizzy::abs(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(CosTest, CosInteger) {
    dizzy::Buffer<4> a, b={492,24,6,933}, c={-0.3341937939677003,0.424179007336997,0.960170286650366,-0.998594868867907};

    dizzy::cos(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(CosTest, CosNegative) {
    dizzy::Buffer<4> a, b={-775,385,-785,-864}, c={-0.5625036986477305,-0.1542812333919083,0.9217746469028693,-0.9980773599075725};

    dizzy::cos(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(CosTest, CosDecimal) {
    dizzy::Buffer<4> a, b={844.3818856030703,-320.0954329222441,429.24825102090836,504.6162735670805}, c={-0.7606138373400368,0.9403911430868874,-0.408539905065236,-0.38079199072659525};

    dizzy::cos(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(SinTest, SinInteger) {
    dizzy::Buffer<4> a, b={708,875,43,886}, c={-0.9093225141277265,0.9977932782684322,-0.8317747426285983,0.07081237357015184};

    dizzy::sin(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(SinTest, SinNegative) {
    dizzy::Buffer<4> a, b={-443,-398,588,-163}, c={0.035428428178979524,-0.8317580087191733,-0.49876540925697305,0.35491017584493534};

    dizzy::sin(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(SinTest, SinDecimal) {
    dizzy::Buffer<4> a, b={-604.3019876815379,424.8524666763842,-991.2007269449532,326.91611954942346}, c={-0.8984375603847213,-0.6724088750135231,0.9996011439225351,0.18933374663949218};

    dizzy::sin(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(TanTest, TanInteger) {
    dizzy::Buffer<4> a, b={275,770,148,149}, c={-9.001181796296159,0.3201068544908864,0.3595365943310712,4.356147801749622};

    dizzy::tan(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(TanTest, TanNegative) {
    dizzy::Buffer<4> a, b={946,36,869,257}, c={0.400121680243227,7.750470905699148,-2.74265124607259,-0.699808745845877};

    dizzy::tan(a, b);
   
    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(TanTest, TanDecimal) {
    dizzy::Buffer<4> a, b={-951.8575337715447,-826.2337702326477,-995.2531554736197,-655.4719307459891}, c={0.0450707475089533,0.005097705624625973,0.7317458255103366,2.0708844769112904};

    dizzy::tan(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(FloorTest, FloorInteger) {
    dizzy::Buffer<4> a, b={37,42,342,762}, c={37,42,342,762};

    dizzy::floor(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(FloorTest, FloorNegative) {
    dizzy::Buffer<4> a, b={-948,-467,904,-850}, c={-948,-467,904,-850};

    dizzy::floor(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(FloorTest, FloorDecimal) {
    dizzy::Buffer<4> a, b={-964.3439133651555,-776.8948446027935,299.41705195233226,-971.3707431219518}, c={-965,-777,299,-972};

    dizzy::floor(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(CeilTest, CeilInteger) {
    dizzy::Buffer<4> a, b={260,658,245,510}, c={260,658,245,510};

    dizzy::ceil(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(CeilTest, CeilNegative) {
    dizzy::Buffer<4> a, b={-749,-710,-998,-854}, c={-749,-710,-998,-854};

    dizzy::ceil(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(CeilTest, CeilDecimal) {
    dizzy::Buffer<4> a, b={71.55867060646415,-214.71129171550274,-786.2984924577177,613.5131972841918}, c={72,-214,-786,614};

    dizzy::ceil(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(RoundTest, RoundInteger) {
    dizzy::Buffer<4> a, b={989,995,624,906}, c={989,995,624,906};

    dizzy::round(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(RoundTest, RoundNegative) {
    dizzy::Buffer<4> a, b={-662,879,928,152}, c={-662,879,928,152};

    dizzy::round(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(RoundTest, RoundDecimal) {
    dizzy::Buffer<4> a, b={-476.4967826195061,883.6545743979514,-198.23159836232662,151.6108987852931}, c={-476,884,-198,152};

    dizzy::round(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(FractTest, FractInteger) {
    dizzy::Buffer<4> a, b={845,853,63,957}, c={0,0,0,0};

    dizzy::fract(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(FractTest, FractNegative) {
    dizzy::Buffer<4> a, b={-952,333,-454,229}, c={0,0,0,0};

    dizzy::fract(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(FractTest, FractDecimal) {
    dizzy::Buffer<4> a, b={917.7344590425491,270.071208011359,904.5123816467822,695.6681017763913}, c={0.7344590425491333,0.07120801135897636,0.5123816467821598,0.6681017763912678};

    dizzy::fract(a, b);

    EXPECT_THAT(a[0], Near(c[0], 1e-4));
    EXPECT_THAT(a[1], Near(c[1], 1e-4));
    EXPECT_THAT(a[2], Near(c[2], 1e-4));
    EXPECT_THAT(a[3], Near(c[3], 1e-4));
}

TEST(SignTest, SignInteger) {
    dizzy::Buffer<4> a, b={130,617,631,612}, c={1,1,1,1};

    dizzy::sign(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(SignTest, SignNegative) {
    dizzy::Buffer<4> a, b={-87,91,-960,996}, c={-1,1,-1,1};

    dizzy::sign(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(SignTest, SignDecimal) {
    dizzy::Buffer<4> a, b={258.9477892033756,-484.6998075954616,920.1819151639938,419.0220576710999}, c={1,-1,1,1};

    dizzy::sign(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(SignTest, SignSignedZero) {
    dizzy::Buffer<4> a, b={0.0, -0.0, 0.0, -0.0}, c={1,-1,1,-1};

    dizzy::sign(a, b);

    EXPECT_THAT(a, testing::Eq(c));
}

TEST(SqrtTest, SqrtInteger) {
    dizzy::Buffer<4> a, b={734,590,568,968}, c={27.09243436828813,24.289915602982237,23.83275057562597,31.11269837220809};

    dizzy::sqrt(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(SqrtTest, SqrtNegative) {
    dizzy::Buffer<4> a, b={284,-202,428,-100}, c={16.852299546352718, std::numeric_limits<float>::quiet_NaN(),20.688160865577203,std::numeric_limits<float>::quiet_NaN()};

    dizzy::sqrt(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::NanSensitiveFloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::NanSensitiveFloatEq(c[3]));
}

TEST(SqrtTest, SqrtDecimal) {
    dizzy::Buffer<4> a, b={-698.8785550929606,531.6585469990969,528.1991087831557,-700.5601609125733}, c={std::numeric_limits<float>::quiet_NaN(),23.05772206873647,22.9825827265596,std::numeric_limits<float>::quiet_NaN()};

    dizzy::sqrt(a, b);

    EXPECT_THAT(a[0], testing::NanSensitiveFloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::NanSensitiveFloatEq(c[3]));
}

TEST(LogTest, LogInteger) {
    dizzy::Buffer<4> a, b={174,582,692,973}, c={5.159055299214529,6.366470447731438,6.539585955617669,6.880384082186005};

    dizzy::log(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(LogTest, LogNegative) {
    dizzy::Buffer<4> a, b={151,-47,-811,279}, c={5.017279836814924,std::numeric_limits<float>::quiet_NaN(),std::numeric_limits<float>::quiet_NaN(),5.631211781821365};

    dizzy::log(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::NanSensitiveFloatEq(c[1]));
    EXPECT_THAT(a[2], testing::NanSensitiveFloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(LogTest, LogDecimal) {
    dizzy::Buffer<4> a, b={803.5481157712638,829.9219533801079,-325.41520334780216,558.1515361554921}, c={6.689037066111817,6.721331664297192,std::numeric_limits<float>::quiet_NaN(),6.324630495683939};

    dizzy::log(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::NanSensitiveFloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(ExpTest, ExpInteger) {
    dizzy::Buffer<4> a, b={42,151,311,69}, c={1.739274941520501e+18,std::numeric_limits<float>::infinity(),std::numeric_limits<float>::infinity(),9.253781621373885e+29};

    dizzy::exp(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(ExpTest, ExpNegative) {
    dizzy::Buffer<4> a, b={60,-374,246,-195}, c={1.1420073962419164e+26,0,std::numeric_limits<float>::infinity(),0};

    dizzy::exp(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}

TEST(ExpTest, ExpDecimal) {
    dizzy::Buffer<4> a, b={-409.5905045978725,-100.81147076562047,-663.9901311136782,673.2404991053045}, c={0,1.6815581571897805e-44,0,std::numeric_limits<float>::infinity()};

    dizzy::exp(a, b);

    EXPECT_THAT(a[0], testing::FloatEq(c[0]));
    EXPECT_THAT(a[1], testing::FloatEq(c[1]));
    EXPECT_THAT(a[2], testing::FloatEq(c[2]));
    EXPECT_THAT(a[3], testing::FloatEq(c[3]));
}


TEST(RandomTest, Values) {
    dizzy::Buffer<4> a;

    dizzy::random(a, -505.74774169921875, -364.25360107421875);

    EXPECT_THAT(a[0], Between(-505.74774169921875, -364.25360107421875));
    EXPECT_THAT(a[1], Between(-505.74774169921875, -364.25360107421875));
    EXPECT_THAT(a[2], Between(-505.74774169921875, -364.25360107421875));
    EXPECT_THAT(a[3], Between(-505.74774169921875, -364.25360107421875));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
