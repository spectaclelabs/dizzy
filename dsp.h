#ifndef dizzy_HPP
#define dizzy_HPP

#include <array>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>

namespace dizzy {

typedef float Sample;

template <size_t N>
using Buffer = std::array<Sample, N>;

template <size_t N1, size_t N2>
void add(const Buffer<N1> &dst, const Buffer<N2> &x, Sample y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt + y;
    }
}

template <size_t N1, size_t N2, size_t N3>
void add(const Buffer<N1> &dst, const Buffer<N2> &x,
         const Buffer<N3> &y) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = *xIt + *yIt;
    }
}

template <size_t N1, size_t N2>
void sub(const Buffer<N1> &dst, const Buffer<N2> &x, Sample y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt - y;
    }
}

template <size_t N1, size_t N2, size_t N3>
void sub(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &y) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = *xIt - *yIt;
    }
}

template <size_t N1, size_t N2>
void mul(Buffer<N1> &dst, const Buffer<N2> &x, Sample y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = (*xIt) * y;
    }
}

template <size_t N1, size_t N2, size_t N3>
void mul(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &y) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = (*xIt) * (*yIt);
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4>
void mulCplx(Buffer<N1> &dstReal, Buffer<N2> &dstImag,
             const Buffer<N3> &xReal, const Buffer<N4> &xImag,
             Sample yReal, Sample yImag) {
    size_t length = std::min(dstReal.size(), dstImag.size());
    length = std::min(length, xReal.size());
    length = std::min(length, xImag.size());

    auto dstRealIt = dstReal.begin(), dstImagIt = dstImag.begin();
    auto xRealIt = xReal.begin(), xImagIt = xImag.begin();
    auto dstEnd = dstRealIt + length;
    for (; dstRealIt != dstEnd;
         dstRealIt++, dstImagIt++, xRealIt++, xImagIt++) {
        *dstRealIt = (*xRealIt) * yReal - (*xImagIt) * yImag;
        *dstImagIt = (*xRealIt) * yImag + (*xImagIt) * yReal;
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4, size_t N5, size_t N6>
void mulCplx(Buffer<N1> &dstReal, Buffer<N2> &dstImag,
             const Buffer<N3> &xReal, const Buffer<N4> &xImag,
             const Buffer<N5> &yReal, const Buffer<N6> &yImag) {
    size_t length = std::min(dstReal.size(), dstImag.size());
    length = std::min(length, xReal.size());
    length = std::min(length, xImag.size());
    length = std::min(length, yReal.size());
    length = std::min(length, yImag.size());

    auto dstRealIt = dstReal.begin(), dstImagIt = dstImag.begin();
    auto xRealIt = xReal.begin(), xImagIt = xImag.begin();
    auto yRealIt = yReal.begin(), yImagIt = yImag.begin();
    auto dstEnd = dstRealIt + length;
    for (; dstRealIt != dstEnd;
         dstRealIt++, dstImagIt++, xRealIt++, xImagIt++, yRealIt++, yImagIt++) {
        *dstRealIt = (*xRealIt) * (*yRealIt) - (*xImagIt) * (*yImagIt);
        *dstImagIt = (*xRealIt) * (*yImagIt) + (*xImagIt) * *(yRealIt);
    }
}

template <size_t N1, size_t N2>
void div(Buffer<N1> &dst, const Buffer<N2> &x, Sample y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt / y;
    }
}

template <size_t N1, size_t N2, size_t N3>
void div(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &y) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = *xIt / *yIt;
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4>
void divCplx(Buffer<N1> &dstReal, Buffer<N2> &dstImag,
             const Buffer<N3> &xReal, const Buffer<N4> &xImag,
             Sample yReal, Sample yImag) {
    size_t length = std::min(dstReal.size(), dstImag.size());
    length = std::min(length, xReal.size());
    length = std::min(length, xImag.size());

    Sample denom = yReal * yReal + yImag * yImag;

    auto dstRealIt = dstReal.begin(), dstImagIt = dstImag.begin();
    auto xRealIt = xReal.begin(), xImagIt = xImag.begin();
    auto dstEnd = dstRealIt + length;
    for (; dstRealIt != dstEnd;
         dstRealIt++, dstImagIt++, xRealIt++, xImagIt++) {
        *dstRealIt = ((*xRealIt) * yReal + (*xImagIt) * yImag) / denom;
        *dstImagIt = ((*xImagIt) * yReal - (*xRealIt) * yImag) / denom;
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4, size_t N5, size_t N6>
void divCplx(Buffer<N1> &dstReal, Buffer<N2> &dstImag,
             const Buffer<N3> &xReal, const Buffer<N4> &xImag,
             const Buffer<N5> &yReal, const Buffer<N6> &yImag) {
    size_t length = std::min(dstReal.size(), dstImag.size());
    length = std::min(length, xReal.size());
    length = std::min(length, xImag.size());
    length = std::min(length, yReal.size());
    length = std::min(length, yImag.size());

    auto dstRealIt = dstReal.begin(), dstImagIt = dstImag.begin();
    auto xRealIt = xReal.begin(), xImagIt = xImag.begin();
    auto yRealIt = yReal.begin(), yImagIt = yImag.begin();
    auto dstEnd = dstRealIt + length;
    for (; dstRealIt != dstEnd;
         dstRealIt++, dstImagIt++, xRealIt++, xImagIt++, yRealIt++, yImagIt++) {
        Sample denom = (*yRealIt) * (*yRealIt) + (*yImagIt) * (*yImagIt);
        *dstRealIt = ((*xRealIt) * (*yRealIt) + (*xImagIt) * (*yImagIt)) / denom;
        *dstImagIt = ((*xImagIt) * (*yRealIt) - (*xRealIt) * (*yImagIt)) / denom;   
    }
}

template <size_t N1, size_t N2, size_t N3>
void madd(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &y, Sample z) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto dstEnd = dstIt + length;

    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = (*xIt) + (*yIt) * z;
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4>
void madd(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &y,
          const Buffer<N4> &z) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());
    length = std::min(length, z.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto zIt = z.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = (*xIt) + (*yIt) * (*zIt);
    }
}

template <size_t N1, size_t N2>
void abs(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::fabs(*xIt);
    }
}

template <size_t N1, size_t N2, size_t N3>
void absCplx(Buffer<N1> &dst, const Buffer<N2> &xReal,
             const Buffer<N3> &xImag) {
    size_t length = std::min(dst.size(), xReal.size());
    length = std::min(length, xImag.size());

    auto dstIt = dst.begin();
    auto xRealIt = xReal.begin(), xImagIt = xImag.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xRealIt++, xImagIt++) {
        *dstIt = std::sqrt((*xRealIt) * (*xRealIt)) +
                           ((*xImagIt) * (*xImagIt));
    }
}

template <size_t N1, size_t N2>
void sin(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::sin(*xIt);
    }
}

template <size_t N1, size_t N2>
void cos(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::cos(*xIt);
    }
}

template <size_t N1, size_t N2>
void tan(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::tan(*xIt);
    }
}

template <size_t N1, size_t N2>
void acos(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::acos(*xIt);
    }
}

template <size_t N1, size_t N2>
void asin(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::asin(*xIt);
    }
}

template <size_t N1, size_t N2>
void atan(Buffer<N1> &dst, const Buffer<N2> &x) {   
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::atan(*xIt);
    }
}

template <size_t N1, size_t N2, size_t N3>
void atan2(Buffer<N1> &dst, const Buffer<N2> &y, const Buffer<N3> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = std::atan(*yIt, *xIt);
    }
}

template <size_t N1, size_t N2>
void ceil(Buffer<N1> &dst, const Buffer<N2> &x) {   
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::ceil(*xIt);
    }
}

template <size_t N1, size_t N2>
void floor(Buffer<N1> &dst, const Buffer<N2> &x) {  
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::floor(*xIt);
    }
}

template <size_t N1, size_t N2>
void round(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::round(*xIt);
    }
}

template <size_t N1, size_t N2>
void exp(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::exp(*xIt);
    }
}

template <size_t N1, size_t N2>
void log(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::log(*xIt);
    }
}

template <size_t N1, size_t N2>
void pow(Buffer<N1> &dst, const Buffer<N2> &x, Sample y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;

    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::pow(*xIt, y);
    }
}

template <size_t N1, size_t N2, size_t N3>
void pow(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &y) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto dstEnd = dstIt + length;

    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = std::pow(*xIt, *yIt);
    }
}

template <size_t N1, size_t N2>
void sqrt(Buffer<N1> &dst, const Buffer<N2> &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::sqrt(*xIt);
    }
}

template <size_t N>
Sample max(const Buffer<N> &x) {
    return *std::max_element(x.begin(), x.end());
}

template <size_t N>
Sample min(const Buffer<N> &x) {
    return *std::min_element(x.begin(), x.end());
}

template <size_t N>
Sample sum(const Buffer<N> &x) {
    return std::accumulate(x.begin(), x.end());
}

template <size_t N>
void random(Buffer<N> &dst, Sample low = 0.0f, Sample high = 1.0f) {
    Sample diff = high - low;

    auto dstIt = dst.begin();
    auto dstEnd = dst.end();
    for (; dstIt != dstEnd; dstIt++) {
        *dstIt = ((Sample) std::rand() / RAND_MAX) * diff + low;
    }
}

template <size_t N1, size_t N2>
void clamp(Buffer<N1> &dst, const Buffer<N2> &x, Sample xMin, Sample xMax) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        if (*xIt >= xMax) {
            *dstIt = xMax;
        }
        else if (*xIt <= xMin) {
            *dstIt = xMin;
        }
        else {
            *dstIt = *xIt;
        }
    }
}

template <size_t N1, size_t N2>
void fract(Buffer<N1> &dst, const Buffer<N2> &x) {  
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt - std::floor(*xIt);
    }
}

template <size_t N>
void ramp(Buffer<N> &dst, Sample first, Sample last) {
    size_t length = dst.size();

    Sample increment = (last - first) / (length - 1u);

    auto dstIt = dst.begin();
    auto dstEnd = dst.end();
    uint32_t k = 0u;
    for (; dstIt != dstEnd; dstIt++, k++) {
        *dstIt = first + k * increment;
    }
}

template <size_t N1, size_t N2>
void sign(Buffer<N1> &dst, const Buffer<N2> &x) {   
    /* Is there a faster way to work out whether we have +0.0 or -0.0?
     * Mainly want to get rid of the division */
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        if (*xIt > 0.0f) {
            *dstIt = 1.0f;
        }
        else if (*xIt < 0.0f) {
            *dstIt = -1.0f;
        }
        else if (1.0f / *xIt == std::numeric_limits<Sample>::infinity()) {
            *dstIt = 1.0f;
        }
        else {
            *dstIt = -1.0f;
        }
    }
}

template <size_t N1, size_t N2, size_t N3>
void sampleLinear(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &t,
                  bool repeat=false) {
    size_t length = std::min(dst.size(), t.size());
    size_t xLength = x.size();
    uint32_t maxIndex = xLength - 1u;

    auto dstIt = dst.begin();
    auto tIt = t.begin();
    auto dstEnd = dstIt + length;

    if (repeat) {
        Sample invXLength = 1.0f / xLength;

        for (; dstIt != dstEnd; dstIt++, tIt++) {
            Sample tDash = *tIt - std::floor(*tIt * invXLength) * xLength;
            uint32_t idx = tDash;
            Sample w = tDash - idx;
            Sample p1 = x[idx];
            Sample p2 = x[idx < maxIndex ? idx + 1u : 0u];
            *dstIt = p1 + w * (p2 - p1);
        }
    }
    else {
        for (; dstIt != dstEnd; dstIt++, tIt++) {
            Sample tDash = *tIt < 0.0f ? 0.0f :
                (*tIt > maxIndex ? maxIndex : *tIt);
            uint32_t idx = tDash;
            Sample w = tDash - idx;
            Sample p1 = x[idx];
            Sample p2 = x[idx < maxIndex ? idx + 1u : maxIndex];
            *dstIt = p1 + w * (p2 - p1);
        }
    }
}

template <size_t N1, size_t N2, size_t N3>
void sampleCubic(Buffer<N1> &dst, const Buffer<N2> &x, const Buffer<N3> &t,
                 bool repeat=false)  {
    size_t length = std::min(dst.size(), t.size());
    size_t xLength = x.size();
    uint32_t maxIndex = xLength - 1u;

    auto dstIt = dst.begin();
    auto tIt = t.begin();
    auto dstEnd = dstIt + length;

    if (repeat) {
        Sample invXLength = 1.0f / xLength;

        for (; dstIt != dstEnd; dstIt++, tIt++) {
            Sample tDash = *tIt - std::floor(*tIt * invXLength) * xLength;
            uint32_t idx = tDash;
            Sample w = tDash - idx;
            Sample w2 = w * w;
            Sample w3 = w2 * w;
            Sample h2 = -2.0f * w3 + 3.0f * w2;
            Sample h1 = 1.0f - h2;
            Sample h4 = w3 - w2;
            Sample h3 = h4 - w2 + w;
            Sample p1 = x[idx > 0u ? idx - 1u : maxIndex];
            Sample p2 = x[idx];
            Sample p3 = x[idx < maxIndex ? idx + 1u : 0u];
            Sample p4 = x[idx < maxIndex - 1u ? idx + 2u :
                            (idx + 2u - std::floor((idx + 2u) * invXLength) *
                             xLength)];
            *dstIt = h1 * p2 + h2 * p3 +
                     0.5f * (h3 * (p3 - p1) + h4 * (p4 - p2));
        }
    }
    else {
        for (; dstIt != dstEnd; dstIt++, tIt++) {
            Sample tDash = *tIt < 0.0f ? 0.0f :
                *tIt > maxIndex ? maxIndex : *tIt;
            uint32_t idx = tDash;
            Sample w = tDash - idx;
            Sample w2 = w * w;
            Sample w3 = w2 * w;
            Sample h2 = -2.0f * w3 + 3.0f * w2;
            Sample h1 = 1.0f - h2;
            Sample h4 = w3 - w2;
            Sample h3 = h4 - w2 + w;
            Sample p1 = x[idx > 0u ? idx - 1u : 0u];
            Sample p2 = x[idx];
            Sample p3 = x[idx < maxIndex ? idx + 1u : 0u];
            Sample p4 = x[idx < maxIndex - 1u ? idx + 2u : maxIndex];
            *dstIt = h1 * p2 + h2 * p3 +
                     0.5f * (h3 * (p3 - p1) + h4 * (p4 - p2));
        }
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4, size_t N5>
void pack(Buffer<N1> &dst, uint32_t offset, uint32_t stride,
          const Buffer<N2> *src1, const Buffer<N3> *src2=NULL,
          const Buffer<N4> *src3=NULL, const Buffer<N5> *src4=NULL) {
    if ((src2 && src2->size() != src1->size()) ||
        (src3 && src3->size() != src1->size()) ||
        (src4 && src4->size() != src1->size())) {
        return;
    }

    uint32_t dstCount = (dst.size() - offset) / stride;

    size_t length = std::min(dstCount, src1.size());

    auto dstIt = dst.begin() + offset;
    auto dstEnd = dstIt + stride * length;
    auto srcIt = src1->begin();
    for (; dstIt != dstEnd; dstIt+=stride, srcIt++) {
        *dstIt = *srcIt;
    }

    if (src2) {
        dstIt = dst.begin() + offset + 1;
        dstEnd = dstIt + stride * length + 1;
        srcIt = src2->begin();
        for (; dstIt != dstEnd; dstIt+=stride, srcIt++) {
            *dstIt = *srcIt;
        }
    }


   if (src3) {
        dstIt = dst.begin() + offset + 2;
        dstEnd = dstIt + stride * length + 2;
        srcIt = src3->begin();
        for (; dstIt != dstEnd; dstIt+=stride, srcIt++) {
            *dstIt = *srcIt;
        }
    }

    if (src4) {
        dstIt = dst.begin() + offset + 3;
        dstEnd = dstIt + stride * length + 3;
        srcIt = src4->begin();
        for (; dstIt != dstEnd; dstIt+=stride, srcIt++) {
            *dstIt = *srcIt;
        }
    }
}

template <size_t N1, size_t N2, size_t N3, size_t N4, size_t N5>
void unpack(const Buffer<N1> &src, uint32_t offset, uint32_t stride,
            Buffer<N2> *dst1, Buffer<N3> *dst2=NULL, Buffer<N4> *dst3=NULL,
            Buffer<N5> *dst4=NULL) {
    if ((dst2 && dst2->size() != dst1->size()) ||
        (dst3 && dst3->size() != dst1->size()) ||
        (dst4 && dst4->size() != dst1->size())) {
        return;
    }

    uint32_t srcCount = (src.size() - offset) / stride;

    size_t length = std::min(srcCount, dst1.size());

    auto dstIt = dst1->begin();
    auto dstEnd = dstIt + length;
    auto srcIt = src.begin() + offset;
    for (; dstIt != dstEnd; dstIt++, srcIt+=stride) {
        *dstIt = *srcIt;
    }

    if (dst2) {
        dstIt = dst2->begin();
        dstEnd = dstIt + length;
        srcIt = src.begin() + offset + 1;
        for (; dstIt != dstEnd; dstIt++, srcIt+=stride) {
            *dstIt = *srcIt;
        }
    }

    if (dst3) {
        dstIt = dst3->begin();
        dstEnd = dstIt + length;
        srcIt = src.begin() + offset + 2;
        for (; dstIt != dstEnd; dstIt++, srcIt+=stride) {
            *dstIt = *srcIt;
        }
    }

    if (dst4) {
        dstIt = dst4->begin();
        dstEnd = dstIt + length;
        srcIt = src.begin() + offset + 3;
        for (; dstIt != dstEnd; dstIt++, srcIt+=stride) {
            *dstIt = *srcIt;
        }
    }
}

}

#endif
