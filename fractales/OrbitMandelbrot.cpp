#include "OrbitMandelbrot.h"
#include <climits>
#include <fractales/orbits/BitmapOrbit.h>
#include <fractales/orbits/PointOrbit.h>
#include <fractales/orbits/LineOrbit.h>

double OrbitMandelbrot::compute_value(std::complex<double> c) {
    double dist = INT_MAX;
    int i = 0;
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        for (auto orbit : orbits) {
            dist = std::min(dist, orbit->getOrbitValue(orbit->getOrbitFastValue(z)));
        }
        i = i + 1;
    }
    if (i == maxiter || dist == INT_MAX) {
        return INT_MAX;
    }
    //dist  = orbit->getOrbitValue(dist);

    return dist;
}

Fractal *OrbitMandelbrot::clone() {
    auto *f = new OrbitMandelbrot(*this);
    //TODO copy orbits?
    return f;
}

FractalProto *OrbitMandelbrot::serialize() {
    auto fp = ContinuousMandelbrot::serialize();
    auto ofp = new OrbitFractalProto();
    fp->set_allocated_orbit(ofp);

    for (auto orbit : orbits) {
        ofp->mutable_orbits()->AddAllocated(orbit->serialize());
    }
    return fp;
}

OrbitMandelbrot *OrbitMandelbrot::deserialize(FractalProto *ofp) {
    OrbitMandelbrot * mandel;
    if (ofp->has_orbit()) {
        std::vector<Orbit *> orbits = std::vector<Orbit *>((unsigned long) (ofp->orbit().orbits_size()));
        for (int i = 0; i < ofp->orbit().orbits_size(); i++) {
            OrbitProto op = ofp->orbit().orbits(i);
            if (op.has_bitmaporbit()) {
                orbits[i] = BitmapOrbit::deserialize(&op);
            } else if (op.has_lineorbit()) {
                orbits[i] = LineOrbit::deserialize(&op);
            } else if (op.has_pointorbit()) {
                orbits[i] = PointOrbit::deserialize(&op);
            }
        }
        mandel = new OrbitMandelbrot(orbits, ofp->width(), ofp->height(), ofp->left(), ofp->right(), ofp->top(),
                                   ofp->bottom());
    } else {
        mandel = new OrbitMandelbrot(std::vector<Orbit *>(0), ofp->width(), ofp->height(), ofp->left(), ofp->right(),
                                   ofp->top(),
                                   ofp->bottom());
    }
    mandel->set_maxiter(ofp->maxiter());
    return mandel;
}
