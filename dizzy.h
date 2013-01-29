#ifndef dizzy_HPP
#define dizzy_HPP

#include <array>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>

namespace dizzy {

template <typename T>
void add(T &dst, const T &x, float y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt + y;
    }
}

template <typename T>
void add(T &dst, const T &x,
         const T &y) {
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

template <typename T>
void sub(T &dst, const T &x, float y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt - y;
    }
}

template <typename T>
void sub(T &dst, const T &x, const T &y) {
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

template <typename T>
void mul(T &dst, const T &x, float y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = (*xIt) * y;
    }
}

template <typename T>
void mul(T &dst, const T &x, const T &y) {
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

template <typename T>
void mulCplx(T &dstReal, T &dstImag,
             const T &xReal, const T &xImag,
             float yReal, float yImag) {
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

template <typename T>
void mulCplx(T &dstReal, T &dstImag,
             const T &xReal, const T &xImag,
             const T &yReal, const T &yImag) {
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

template <typename T>
void div(T &dst, const T &x, float y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt / y;
    }
}

template <typename T>
void div(T &dst, const T &x, const T &y) {
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

template <typename T>
void divCplx(T &dstReal, T &dstImag,
             const T &xReal, const T &xImag,
             float yReal, float yImag) {
    size_t length = std::min(dstReal.size(), dstImag.size());
    length = std::min(length, xReal.size());
    length = std::min(length, xImag.size());

    float denom = yReal * yReal + yImag * yImag;

    auto dstRealIt = dstReal.begin(), dstImagIt = dstImag.begin();
    auto xRealIt = xReal.begin(), xImagIt = xImag.begin();
    auto dstEnd = dstRealIt + length;
    for (; dstRealIt != dstEnd;
         dstRealIt++, dstImagIt++, xRealIt++, xImagIt++) {
        *dstRealIt = ((*xRealIt) * yReal + (*xImagIt) * yImag) / denom;
        *dstImagIt = ((*xImagIt) * yReal - (*xRealIt) * yImag) / denom;
    }
}

template <typename T>
void divCplx(T &dstReal, T &dstImag,
             const T &xReal, const T &xImag,
             const T &yReal, const T &yImag) {
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
        float denom = (*yRealIt) * (*yRealIt) + (*yImagIt) * (*yImagIt);
        *dstRealIt = ((*xRealIt) * (*yRealIt) + (*xImagIt) * (*yImagIt)) / denom;
        *dstImagIt = ((*xImagIt) * (*yRealIt) - (*xRealIt) * (*yImagIt)) / denom;   
    }
}

template <typename T>
void madd(T &dst, const T &x, const T &y, float z) {
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

template <typename T>
void madd(T &dst, const T &x, const T &y,
          const T &z) {
    size_t length = std::min(dst.size(), x.size());
    length = std::min(length, y.size());
    length = std::min(length, z.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = y.begin();
    auto zIt = z.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++, zIt++) {
        *dstIt = (*xIt) + (*yIt) * (*zIt);
    }
}

template <typename T>
void abs(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::fabs(*xIt);
    }
}

template <typename T>
void absCplx(T &dst, const T &xReal,
             const T &xImag) {
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

template <typename T>
void sin(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::sin(*xIt);
    }
}

template <typename T>
void cos(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::cos(*xIt);
    }
}

template <typename T>
void tan(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::tan(*xIt);
    }
}

template <typename T>
void acos(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::acos(*xIt);
    }
}

template <typename T>
void asin(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::asin(*xIt);
    }
}

template <typename T>
void atan(T &dst, const T &x) {   
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::atan(*xIt);
    }
}

template <typename T>
void atan2(T &dst, const T &y, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto yIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++, yIt++) {
        *dstIt = std::atan(*yIt, *xIt);
    }
}

template <typename T>
void ceil(T &dst, const T &x) {   
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::ceil(*xIt);
    }
}

template <typename T>
void floor(T &dst, const T &x) {  
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::floor(*xIt);
    }
}

template <typename T>
void round(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::round(*xIt);
    }
}

template <typename T>
void exp(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::exp(*xIt);
    }
}

template <typename T>
void log(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::log(*xIt);
    }
}

template <typename T>
void pow(T &dst, const T &x, float y) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;

    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::pow(*xIt, y);
    }
}

template <typename T>
void pow(T &dst, const T &x, const T &y) {
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

template <typename T>
void sqrt(T &dst, const T &x) {
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = std::sqrt(*xIt);
    }
}

template <typename T>
float max(const T &x) {
    return *std::max_element(x.begin(), x.end());
}

template <typename T>
float min(const T &x) {
    return *std::min_element(x.begin(), x.end());
}

template <typename T>
float sum(const T &x) {
    float s = std::accumulate(x.begin(), x.end(), 0.0f);
    return s;
}

template <typename T>
void random(T &dst, float low = 0.0f, float high = 1.0f) {
    float diff = high - low;

    auto dstIt = dst.begin();
    auto dstEnd = dst.end();
    for (; dstIt != dstEnd; dstIt++) {
        *dstIt = ((float) std::rand() / RAND_MAX) * diff + low;
    }
}

template <typename T>
void clamp(T &dst, const T &x, float xMin, float xMax) {
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

template <typename T>
void fract(T &dst, const T &x) {  
    size_t length = std::min(dst.size(), x.size());

    auto dstIt = dst.begin();
    auto xIt = x.begin();
    auto dstEnd = dstIt + length;
    for (; dstIt != dstEnd; dstIt++, xIt++) {
        *dstIt = *xIt - std::floor(*xIt);
    }
}

template <typename T>
void ramp(T &dst, float first, float last) {
    size_t length = dst.size();

    float increment = (last - first) / (length - 1u);

    auto dstIt = dst.begin();
    auto dstEnd = dst.end();
    uint32_t k = 0u;
    for (; dstIt != dstEnd; dstIt++, k++) {
        *dstIt = first + k * increment;
    }
}

template <typename T>
void sign(T &dst, const T &x) {   
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
        else if (1.0f / *xIt == std::numeric_limits<float>::infinity()) {
            *dstIt = 1.0f;
        }
        else {
            *dstIt = -1.0f;
        }
    }
}

template <typename T>
void sampleLinear(T &dst, const T &x, const T &t,
                  bool repeat=false) {
    size_t length = std::min(dst.size(), t.size());
    size_t xLength = x.size();
    uint32_t maxIndex = xLength - 1u;

    auto dstIt = dst.begin();
    auto tIt = t.begin();
    auto dstEnd = dstIt + length;

    if (repeat) {
        float invXLength = 1.0f / xLength;

        for (; dstIt != dstEnd; dstIt++, tIt++) {
            float tDash = *tIt - std::floor(*tIt * invXLength) * xLength;
            uint32_t idx = tDash;
            float w = tDash - idx;
            float p1 = x[idx];
            float p2 = x[idx < maxIndex ? idx + 1u : 0u];
            *dstIt = p1 + w * (p2 - p1);
        }
    }
    else {
        for (; dstIt != dstEnd; dstIt++, tIt++) {
            float tDash = *tIt < 0.0f ? 0.0f :
                (*tIt > maxIndex ? maxIndex : *tIt);
            uint32_t idx = tDash;
            float w = tDash - idx;
            float p1 = x[idx];
            float p2 = x[idx < maxIndex ? idx + 1u : maxIndex];
            *dstIt = p1 + w * (p2 - p1);
        }
    }
}

template <typename T>
void sampleCubic(T &dst, const T &x, const T &t,
                 bool repeat=false)  {
    size_t length = std::min(dst.size(), t.size());
    size_t xLength = x.size();
    uint32_t maxIndex = xLength - 1u;

    auto dstIt = dst.begin();
    auto tIt = t.begin();
    auto dstEnd = dstIt + length;

    if (repeat) {
        float invXLength = 1.0f / xLength;

        for (; dstIt != dstEnd; dstIt++, tIt++) {
            float tDash = *tIt - std::floor(*tIt * invXLength) * xLength;
            uint32_t idx = tDash;
            float w = tDash - idx;
            float w2 = w * w;
            float w3 = w2 * w;
            float h2 = -2.0f * w3 + 3.0f * w2;
            float h1 = 1.0f - h2;
            float h4 = w3 - w2;
            float h3 = h4 - w2 + w;
            float p1 = x[idx > 0u ? idx - 1u : maxIndex];
            float p2 = x[idx];
            float p3 = x[idx < maxIndex ? idx + 1u : 0u];
            float p4 = x[idx < maxIndex - 1u ? idx + 2u :
                            (idx + 2u - std::floor((idx + 2u) * invXLength) *
                             xLength)];
            *dstIt = h1 * p2 + h2 * p3 +
                     0.5f * (h3 * (p3 - p1) + h4 * (p4 - p2));
        }
    }
    else {
        for (; dstIt != dstEnd; dstIt++, tIt++) {
            float tDash = *tIt < 0.0f ? 0.0f :
                *tIt > maxIndex ? maxIndex : *tIt;
            uint32_t idx = tDash;
            float w = tDash - idx;
            float w2 = w * w;
            float w3 = w2 * w;
            float h2 = -2.0f * w3 + 3.0f * w2;
            float h1 = 1.0f - h2;
            float h4 = w3 - w2;
            float h3 = h4 - w2 + w;
            float p1 = x[idx > 0u ? idx - 1u : 0u];
            float p2 = x[idx];
            float p3 = x[idx < maxIndex ? idx + 1u : 0u];
            float p4 = x[idx < maxIndex - 1u ? idx + 2u : maxIndex];
            *dstIt = h1 * p2 + h2 * p3 +
                     0.5f * (h3 * (p3 - p1) + h4 * (p4 - p2));
        }
    }
}

template <typename T>
void pack(T &dst, uint32_t offset, uint32_t stride,
          const T *src1, const T *src2=NULL,
          const T *src3=NULL, const T *src4=NULL) {
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

template <typename T>
void unpack(const T &src, uint32_t offset, uint32_t stride,
            T *dst1, T *dst2=NULL, T *dst3=NULL,
            T *dst4=NULL) {
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
